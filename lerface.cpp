#include "lerface.h"
#define PERSON_LABEL 10
#include <iomanip>

using namespace cv;
using namespace cv::face;
using namespace std;

LerFace::LerFace(QObject *parent) : QObject(parent)
{
    sinalFoto = false;
    sinalDetecao = false;
    numFotos = 0;

    labels.resize(10);
    for(int i=0;i<10;i++){
        labels[i] = 10;
    }

    capture.open( 0 );
    if ( ! capture.isOpened() ) { printf("--(!)Error opening video capture\n"); }

    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n");};

}

LerFace::~LerFace()
{
}

bool LerFace::LerFrameOpenCV(QImage* frameCapture){
    bool retorno = false;
    capture.read(frame);

    if( frame.empty() )
    {
        printf(" --(!) No captured frame -- Break!");
        return false;
    }
    vector<cv::Rect> faces;
    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    vector<int> compression_params;
    compression_params.push_back(100);

    //face_cascade.detectMultiScale( frame_gray, faces, 1.01, 15, 0, Size(80, 80) );
    face_cascade.detectMultiScale( frame_gray, faces, 1.05, 15, 0, Size(80, 80) );

    for ( size_t i = 0; i < faces.size(); i++ ){
        Rect face_i_rec = faces[i];
        Mat face_i = frame_gray(face_i_rec);
        if(sinalFoto && numFotos <=9){
            numFotos++;
            imwrite(format("Data/temp_NovoUsuario/temp_NovoUsuario%d.jpg", numFotos), face_i, compression_params);
        }

        string box_text = "";
        int labelPrediction = -1;
        double confidence = 0.0;
        if(sinalDetecao){
            resize(face_i, face_i, faceSize);
            model->predict(face_i, labelPrediction, confidence);
            //box_text = format("Prediction = %d\tconfidence %.2f", labelPrediction,confidence);
        }

        //Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        if(labelPrediction == 10){
            rectangle(frame, faces[i], CV_RGB(0, 255,0), 2);
            retorno = true;
            emit encontrado();
        }
        else{
            rectangle(frame, faces[i], CV_RGB(255, 0,0), 2);
        }
        //int pos_x = std::max(face_i_rec.tl().x - 10, 0);
        //int pos_y = std::max(face_i_rec.tl().y - 10, 0);
        // And now put it into the image:
        //putText(frame, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
    }
    sinalFoto = false;

   cv::resize(frame, frame, Size(282, 240), 0, 0, INTER_CUBIC);

    cv::cvtColor(frame,frame,CV_BGR2RGB);
    QImage frameQT((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    *frameCapture = frameQT;
//    ui->videoLabel->setPixmap(QPixmap::fromImage(frameQT));

    return retorno;
}

void LerFace::read_csv(vector<Mat>& images, string path_user) {

    path_user += "/temp_NovoUsuario";
    const string extensaoJpg = ".jpg";
    for(int i=1;i<=10;i++){
        images.push_back(imread((PWD+path_user+to_string(i)+extensaoJpg), 0));
    }

}

bool LerFace::detectaUsuario(QImage* frameCapture, string path_user){
    sinalDetecao = true;
    images.clear();

    try {
        read_csv(images, path_user);
    } catch (cv::Exception& e) {
        cerr << "Error opening file CSV Reason: " << e.msg << endl;
        exit(1);
    }
    LerFace::faceSize = Size(images[0].size().width, images[0].size().height);
    model = createLBPHFaceRecognizer(3, 12, 12, 12, 320.0);
    model->train(images,labels);
    bool retorno = LerFrameOpenCV(frameCapture);

    images.clear();

    return retorno;
}
