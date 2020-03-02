#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stable.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initTableView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_target_clicked()
{
    cv::Mat cvimg=this->openImage();
    QImage img=this->cvtMat2QImage(cvimg);
    QPixmap pix=QPixmap::fromImage(img);
    ui->label_env->setPixmap(pix);
    ui->label_env->setText("");
    this->img_target=cvimg;
}

void MainWindow::on_pushButton_board_clicked()
{
    cv::Mat cvimg=this->openImage();
    QImage img=this->cvtMat2QImage(cvimg);
    QPixmap pix=QPixmap::fromImage(img);
    ui->label_board->setPixmap(pix);
    ui->label_board->setText("");
    this->img_board=cvimg;
}

void MainWindow::on_pushButton_add_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void MainWindow::on_pushButton_del_clicked()
{
    if(ui->tableWidget->currentRow()!=-1){
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
    this->initTableView();
}

void MainWindow::initTableView()
{
    while(ui->tableWidget->rowCount()!=0){
        ui->tableWidget->removeRow(0);
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("x_left"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("y_left"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("x_right"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("y_right"));
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

cv::Mat MainWindow::openImage()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Load image","/home/lyx","image file(*.jpg *.png)");
    cv::Mat cvimg;
    if(!fileName.isEmpty()){
        cvimg=cv::imread(fileName.toStdString(),cv::IMREAD_UNCHANGED);
    }
    cvimg.convertTo(cvimg,CV_8UC(cvimg.channels()));
//    qDebug()<<"opened image is "<<cvimg.rows<<" x "<<cvimg.cols<<",the channels is:"<<cvimg.channels()<<endl;
    return cvimg;
}

QImage MainWindow::cvtMat2QImage(cv::Mat src)
{
    QImage img;
    if(src.channels()==3){
        img=QImage((const unsigned char*)src.data,src.cols,src.rows,src.step,QImage::Format_RGB888);
        img=img.rgbSwapped();
    }
    else if(src.channels()==4){
        img=QImage((const unsigned char*)src.data,src.cols,src.rows,src.step,QImage::Format_ARGB32);
    }
    else if(src.channels()==1){
        img=QImage((const unsigned char*)src.data,src.cols,src.rows,src.step,QImage::Format_Grayscale8);
    }
    return img;
}
