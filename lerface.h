#ifndef LERFACE_H
#define LERFACE_H

#include <QMainWindow>

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "pessoa.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace cv;
using namespace cv::face;
using namespace std;

#include <QObject>

class LerFace : public QObject
{
    Q_OBJECT
    public:
        explicit LerFace(QObject *parent = 0);
        ~LerFace();
        bool sinalFoto;
        bool sinalDetecao;
        int numFotos;

        bool LerFrameOpenCV(QImage* frameCapture);
        bool detectaUsuario(QImage* frameCapture, string path_user);

    signals:
        void encontrado();

    private:
        string PWD = "/home/pablomuro/Projeto-TP1-UNB-2017-Deteccao-Facial/";

        void read_csv(vector<Mat>& images, string path_user);
        cv::String face_cascade_name = "Cascades/lbpcascade_frontalface.xml";

        cv::CascadeClassifier face_cascade;

        vector<Mat> images;
        vector<int> labels;
        cv::Ptr<cv::face::FaceRecognizer> model;
        Size faceSize;

        cv::VideoCapture capture;
        cv::Mat frame;
        cv::Mat frame_gray;

        QImage frameQT;

};

#endif // LEFACE_H
