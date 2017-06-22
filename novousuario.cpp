#include "novousuario.h"
#include "ui_novousuario.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cv;

NovoUsuario::NovoUsuario(QWidget *parent) :QDialog(parent), ui(new Ui::NovoUsuario)
{
    ui->setupUi(this);

    ui->materias_label->setVisible(false);
    ui->materia_field->setVisible(false);

    numFotosTiradas = 0;

    connect(this,SIGNAL(on_tiraFoto_botao_clicked()),this,SLOT(UpdateNumFotos()));
    connect(this,SIGNAL(rejected()), this, SLOT(on_ok_cancela_botao_rejected()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateFrameNovoUsuario()));
    timer->start(20);

}

NovoUsuario::~NovoUsuario()
{
    delete ui;
}

void NovoUsuario::on_ok_cancela_botao_accepted()
{
    Pessoa novoUsuario;
    bool erro = false;

    if(numFotosTiradas < 10){ ui->erro_label->setText("Necessário tirar 10 fotos"); erro = true; }
    if(ui->matricula_field->text().isEmpty()){ ui->erro_label->setText("Campo Matrícula precisa ser preenchido"); erro = true; }
    else if(ui->tipo_pessoa_field->currentIndex() == 0){ ui->erro_label->setText("Selecione um tipo de usuário"); erro = true; }
    else if(ui->nome_field->text().isEmpty()){ ui->erro_label->setText("Campo Nome precisa ser preenchido"); erro = true; }
    else if(ui->sobrenome_field->text().isEmpty()){ ui->erro_label->setText("Campo Sobrenome precisa ser preenchido"); erro = true; }

    if(erro == false){
        printf("foi\n");
        novoUsuario.setMatricula(ui->matricula_field->text().toStdString());
        novoUsuario.setTipoPessoa(ui->tipo_pessoa_field->currentIndex());
        novoUsuario.setNome(ui->nome_field->text().toStdString());
        novoUsuario.setSobrenome(ui->sobrenome_field->text().toStdString());
        novoUsuario.setMaterias(ui->materia_field->text().toStdString());

        string PATH = "Data/";
        PATH += novoUsuario.getMatricula();
        novoUsuario.setPathImagens(PATH);

        bool sucesso = novoUsuario.SalvaBD();
        if(sucesso){
            string renomearPasta = "mv Data/temp_NovoUsuario ";
            renomearPasta += novoUsuario.getPathImagens();
            system(renomearPasta.c_str());
        }
        emit accept();
    }

}

void NovoUsuario::on_tipo_pessoa_field_currentIndexChanged(int index)
{
    if(index == 1 || index == 2){
        ui->materias_label->setVisible(true);
        ui->materia_field->setVisible(true);
    }
    else{
        ui->materias_label->setVisible(false);
        ui->materia_field->setVisible(false);
    }
}

void NovoUsuario::on_ok_cancela_botao_rejected()
{
    system("rm -rf Data/temp_NovoUsuario");
}

void NovoUsuario::UpdateFrameNovoUsuario()
{
    ui->videoCapture->setPixmap(QPixmap::fromImage(*frameCapture));
}

void NovoUsuario::UpdateNumFotos()
{
    string numFotos = to_string(numFotosTiradas);
    QString fotos = QString((numFotos+"/10").c_str());
    ui->num_fotos_label->setText(fotos);
}
