#include "listareservas.h"
#include "ui_listareservas.h"

ListaReservas::ListaReservas(QWidget *parent) :QDialog(parent),ui(new Ui::ListaReservas)
{
    ui->setupUi(this);

    QStringList titulos;
    titulos << "Autor" << "Proposta" << "Aula" << "Recorrente" << "Num Salas" << "Horario" << "Data_Inicio" << "Data_Fim" << "Matriculas";
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    Reserva reservaItem;

    QSqlQuery query;
    bool sucessoBD = query.exec("SELECT * FROM Reservas");

    if(sucessoBD){
        while(query.next()){
            reservaItem.getResevaFromSQL(query);
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Autor,
                                     new QTableWidgetItem(QString(reservaItem.getAutor().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Proposta,
                                     new QTableWidgetItem(QString(reservaItem.getProposta().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Aula,
                                     new QTableWidgetItem(QString(reservaItem.getAula().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Recorrente,
                                     new QTableWidgetItem(QString(reservaItem.getRecorrente().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Num_Salas,
                                     new QTableWidgetItem(QString(reservaItem.getNumSalas().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Horario,
                                     new QTableWidgetItem(QString(reservaItem.getHorario().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Data_Inicio,
                                     new QTableWidgetItem(QString(reservaItem.getDataInicio().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Data_Fim,
                                     new QTableWidgetItem(QString(reservaItem.getDataFim().c_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, Matriculas,
                                     new QTableWidgetItem(QString(reservaItem.getMatriculas().c_str())));
        }
    }else{
        cout << "erro no banco" << endl;
    }
}

ListaReservas::~ListaReservas()
{
    delete ui;
}
