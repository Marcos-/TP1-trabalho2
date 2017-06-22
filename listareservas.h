#ifndef LISTARESERVAS_H
#define LISTARESERVAS_H

#include <QDialog>
#include <QtSql>
#include "reserva.h"

namespace Ui {
class ListaReservas;
}

class ListaReservas : public QDialog
{
    Q_OBJECT

public:
    explicit ListaReservas(QWidget *parent = 0);
    ~ListaReservas();

private:
    Ui::ListaReservas *ui;

    enum Colunas{
        Autor , Proposta,
        Aula , Recorrente,
        Num_Salas, Horario,
        Data_Inicio, Data_Fim,
        Matriculas
    };
};

#endif // LISTARESERVAS_H
