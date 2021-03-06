#-------------------------------------------------
#
# Project created by QtCreator 2017-06-10T19:59:38
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoTP1_EXEC
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv

QMAKE_CXXFLAGS += -std=c++0x

LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_videostab -lopencv_calib3d \
     -lopencv_features2d -lopencv_video -lopencv_photo -lopencv_flann -lopencv_face -lopencv_objdetect -lopencv_highgui \
     -lopencv_videoio -lopencv_imgcodecs -lopencv_ml -lopencv_imgproc -lopencv_core

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        janela.cpp \
    novousuario.cpp \
    lerface.cpp \
    pessoa.cpp \
    reserva.cpp \
    novareserva.cpp \
    listareservas.cpp

HEADERS += \
        janela.h \
    novousuario.h \
    lerface.h \
    pessoa.h \
    reserva.h \
    novareserva.h \
    listareservas.h

FORMS += \
        janela.ui \
    novousuario.ui \
    novareserva.ui \
    listareservas.ui
