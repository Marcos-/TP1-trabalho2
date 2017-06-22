#include "janela.h"
#include "ui_janela.h"
#include "novousuario.h"
#include "lerface.h"
#include <iostream>

#define LOCAL_BD "/home/marcos/Documentos/UnB/TP1-Trabalho2/assets/Pessoas.sqlite"

Janela::Janela(QWidget *parent) : QMainWindow(parent), ui(new Ui::Janela)
{
    ui->setupUi(this);

    ui->fazerReserva->hide();

    faceDetect = new LerFace();
    usuarioLogado = new Pessoa();

    janelaCadastrasUsuario = new NovoUsuario();
    janelaCadastrasUsuario->frameCapture = &frameCapture;
    janelaNovaReserva = new NovaReserva();

    meuBanco = QSqlDatabase::addDatabase("QSQLITE");
    meuBanco.setDatabaseName(LOCAL_BD);
    QFileInfo checkFile(LOCAL_BD);

    if(checkFile.isFile()){
        if(meuBanco.open()){
            ui->Acesso->setText("[+] Conectado ao banco ");
        }else{
            ui->Acesso->setText("[+] Erro ao conectar no banco ");
        }
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateFrame()));
    timer->start(20);

    connect(faceDetect,SIGNAL(encontrado()),this,SLOT(EncotraFace()));
    connect(janelaCadastrasUsuario,SIGNAL(on_tiraFoto_botao_clicked()),this,SLOT(tiraFoto()));
    connect(janelaCadastrasUsuario,SIGNAL(rejected()),this,SLOT(resetaNovoUsuario()));
    connect(janelaCadastrasUsuario,SIGNAL(accepted()),this,SLOT(resetaNovoUsuario()));

    connect(ui->actionListar,SIGNAL(triggered()), this, SLOT(listaReservas()));
}

Janela::~Janela()
{
    delete ui;
    meuBanco.close();
}

void Janela::listaReservas(){
    janelaListarReservas = new ListaReservas();
    janelaListarReservas->setModal(true);
    janelaListarReservas->exec();
}

void Janela::EncotraFace(){
     ui->Acesso->setText("[+] ACESSO LIBERADO\nBem vindo "+QString(usuarioLogado->getNome().c_str()));
     ui->fazerReserva->show();
}

void Janela::on_AdicionarNovo_clicked()
{
    system("mkdir Data/temp_NovoUsuario");
    janelaCadastrasUsuario->setModal(true);
    janelaCadastrasUsuario->frameCapture = &frameCapture;

    this->hide();
    janelaCadastrasUsuario->exec();
}

void Janela::on_Detectar_clicked(bool sucesso = false)
{
    ui->fazerReserva->hide();
    faceDetect->sinalDetecao = false;
    QString Matricula;
    Matricula = ui->Matricula->text();

    if(!meuBanco.isOpen()){
        qDebug() << "Sem conexao";
        return;
    }

    QSqlQuery query;
    bool sucessoBD = query.exec("SELECT * FROM Pessoas WHERE numero_usuario =\'"+Matricula+"\'");

    if(sucessoBD){
        if(query.next()){
            if(sucesso == false){
                usuarioLogado->getPessoaFromSQL(query);
                sucesso = faceDetect->detectaUsuario(&frameCapture, usuarioLogado->getPathImagens());
            }
            if(sucesso){
                ui->Acesso->setText("[+] ACESSO LIBERADO\nBem vindo "+QString(usuarioLogado->getNome().c_str()));
                ui->fazerReserva->show();
            }else{
                ui->Acesso->setText("[-] ACESSO NEGADO");
            }

        }else{
            ui->Acesso->setText("[-] ACESSO NEGADO\nUsuario nao cadastrado");
        }
    }else{
        ui->Acesso->setText("[-] ERRO AO ACESSAR O BANCO ");
    }
}

void Janela::UpdateFrame()
{
    faceDetect->LerFrameOpenCV(&frameCapture);
    ui->faceCapture->setPixmap(QPixmap::fromImage(frameCapture));
}

void Janela::tiraFoto(){
    faceDetect->sinalFoto = true;
    UpdateFrame();
    janelaCadastrasUsuario->numFotosTiradas = faceDetect->numFotos;
}

void Janela::resetaNovoUsuario(){
    this->show();
    janelaCadastrasUsuario->numFotosTiradas = 0;
    faceDetect->numFotos = 0;
}

void Janela::on_fazerReserva_clicked()
{
    janelaNovaReserva->setModal(true);
    janelaNovaReserva->pessoa = usuarioLogado;
    janelaNovaReserva->exec();

}
