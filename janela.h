#ifndef JANELA_H
#define JANELA_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include "lerface.h"
#include "novousuario.h"
#include "novareserva.h"
#include "listareservas.h"

namespace Ui {
class Janela;
}

class Janela : public QMainWindow
{
    Q_OBJECT

public:
    explicit Janela(QWidget *parent = 0);
    ~Janela();

private:
    Ui::Janela *ui;
    NovoUsuario* janelaCadastrasUsuario;
    NovaReserva* janelaNovaReserva;
    ListaReservas* janelaListarReservas;

    QSqlDatabase meuBanco;

    QImage frameCapture;

    QTimer* timer;
    LerFace* faceDetect;

    Pessoa* usuarioLogado;

public slots:
    void UpdateFrame();
    void EncotraFace();

private slots:
    void on_AdicionarNovo_clicked();

    void on_Detectar_clicked(bool sucesso);

    void tiraFoto();

    void resetaNovoUsuario();

    void on_fazerReserva_clicked();

    void listaReservas();

};

#endif // JANELA_H
