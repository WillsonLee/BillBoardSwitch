#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stable.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cv::Mat img(512,512,CV_8UC3);
    cv::randn(img,128,50);
    cv::imshow("image",img);
    qDebug()<<"precompiled version,is it faster now?"<<endl;
    qDebug()<<"I modified it again!any difference?"<<endl;
    qDebug()<<"now?"<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
