#include "janela.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Janela mainWindow;
    mainWindow.show();

    return a.exec();
}
