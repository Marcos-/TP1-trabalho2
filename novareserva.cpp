#include "novareserva.h"
#include "ui_novareserva.h"

NovaReserva::NovaReserva(QWidget *parent) :QDialog(parent),ui(new Ui::NovaReserva)
{
    ui->setupUi(this);

    pessoa = new Pessoa();

    ui->dataFim_label->setVisible(false);
    ui->dataFim_field->setVisible(false);

    QDate dataAtual = QDate::currentDate();
    ui->dataInicio_field->setDate(dataAtual);
    ui->dataInicio_field->setMinimumDate(dataAtual);
    ui->dataFim_field->setMinimumDate(dataAtual);

    ui->horario_field->setTime(QTime::currentTime());

    connect(this,SIGNAL(rejected()), this, SLOT(on_ok_cancela_botao_rejected()));
}

NovaReserva::~NovaReserva()
{
    delete ui;
}

void NovaReserva::on_ok_cancela_botao_accepted()
{
    Reserva novaReserva;
    bool erro = false;


    if(ui->proposta_field->text().isEmpty()){ ui->erro_label->setText("Campo Matrícula precisa ser preenchido"); erro = true; }
    else if(ui->salas_field->text().isEmpty()){ ui->erro_label->setText("Campo Nome precisa ser preenchido"); erro = true; }
    else if(ui->matriculas_field->text().isEmpty()){ ui->erro_label->setText("Campo Sobrenome precisa ser preenchido"); erro = true; }


    QString nome = QString(to_string(pessoa->getId()).c_str());
    ui->erro_label->setText(nome);
    if(erro == false){
        novaReserva.setProposta(ui->proposta_field->text().toStdString());
        novaReserva.setAula(ui->aula_field->text().toStdString());
        novaReserva.setRecorrente(to_string(ui->recorrente_field->isChecked()));
        novaReserva.setProposta(ui->proposta_field->text().toStdString());
        novaReserva.setNumSalas(ui->salas_field->text().toStdString());
        novaReserva.setHorario(ui->horario_field->text().toStdString());
        novaReserva.setDataInicio(ui->dataInicio_field->text().toStdString());
        novaReserva.setDataFim(ui->dataFim_field->text().toStdString());
        novaReserva.setMatriculas(ui->matriculas_field->text().toStdString());

        bool sucesso = novaReserva.SalvaBD(pessoa);
        if(sucesso){
            emit accept();
        }
        else{
            ui->erro_label->setText("Erro ao salvar no banco");
        }
    }
}

void NovaReserva::on_ok_cancela_botao_rejected()
{

}

void NovaReserva::on_recorrente_field_toggled(bool checked)
{
    if(checked){
        ui->dataFim_label->setVisible(true);
        ui->dataFim_field->setVisible(true);

        ui->dataInicio_label->setText("Data Inicio : ");
    }else{
        ui->dataFim_label->setVisible(false);
        ui->dataFim_field->setVisible(false);

        ui->dataInicio_label->setText("Data : ");
    }
}
