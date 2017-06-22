#ifndef NOVOUSUARIO_H
#define NOVOUSUARIO_H

#include <QDialog>
#include "pessoa.h"
#include "lerface.h"

namespace Ui {
class NovoUsuario;
}

class NovoUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit NovoUsuario(QWidget *parent = 0);
    ~NovoUsuario();
    QImage* frameCapture;
    int numFotosTiradas;

private:
    Ui::NovoUsuario *ui;

    QTimer* timer;


private slots:
    void on_ok_cancela_botao_accepted();

    void on_tipo_pessoa_field_currentIndexChanged(int index);

    void on_ok_cancela_botao_rejected();

    void UpdateNumFotos();


public slots:
    void UpdateFrameNovoUsuario();

signals:
    void on_tiraFoto_botao_clicked();
};

#endif // NOVOUSUARIO_H
