#ifndef NOVARESERVA_H
#define NOVARESERVA_H

#include <QDialog>
#include "reserva.h"
#include "pessoa.h"

namespace Ui {
class NovaReserva;
}

class NovaReserva : public QDialog
{
    Q_OBJECT

public:
    explicit NovaReserva(QWidget *parent = 0);
    ~NovaReserva();

    Pessoa* pessoa;
    Ui::NovaReserva *ui;

private slots:
    void on_ok_cancela_botao_accepted();

    void on_ok_cancela_botao_rejected();

    void on_recorrente_field_toggled(bool checked);

private:
    //Ui::NovaReserva *ui;

};

#endif // NOVARESERVA_H
