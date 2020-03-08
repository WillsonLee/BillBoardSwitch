#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stable.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initTableView();
    connect(ui->label_env,&PicLabel::clicked,this,&MainWindow::targetImageClicked);
    connect(ui->label_board,&PicLabel::clicked,this,&MainWindow::boardImageClicked);
    connect(ui->label_env,&PicLabel::coordXChanged,this,&MainWindow::changeX);
    connect(ui->label_env,&PicLabel::coordYChanged,this,&MainWindow::changeY);
    connect(ui->label_board,&PicLabel::coordXChanged,this,&MainWindow::changeX);
    connect(ui->label_board,&PicLabel::coordYChanged,this,&MainWindow::changeY);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_target_clicked()
{
    cv::Mat cvimg;
    bool opened=this->openImage(cvimg);
    if(opened){
        QImage img=this->cvtMat2QImage(cvimg);
        ui->label_env->setImage(img);
        this->img_target=cvimg;
    }
}

void MainWindow::on_pushButton_board_clicked()
{
    cv::Mat cvimg;
    bool opened=this->openImage(cvimg);
    if(opened){
        QImage img=this->cvtMat2QImage(cvimg);
        ui->label_board->setImage(img);
        this->img_board=cvimg;
    }
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

bool MainWindow::openImage(cv::Mat &dst)
{
    QString fileName=QFileDialog::getOpenFileName(this,"Load image","/home/lyx","image file(*.jpg *.png)");
    if(!fileName.isEmpty()){
        dst=cv::imread(fileName.toStdString(),cv::IMREAD_UNCHANGED);
        dst.convertTo(dst,CV_8UC(dst.channels()));
        return true;
    }
    return false;
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

void MainWindow::changeX(int x)
{
    ui->lcdNumber_x->display(x);
}

void MainWindow::changeY(int y)
{
    ui->lcdNumber_y->display(y);
}

void MainWindow::targetImageClicked(bool loaded)
{
    if(loaded){
        qDebug()<<"writing coord to table"<<ui->lcdNumber_x->value()<<","<<ui->lcdNumber_y->value()<<endl;
    }
    else{
        ui->pushButton_target->click();
    }
}

void MainWindow::boardImageClicked(bool loaded)
{
    if(loaded){
        qDebug()<<"writing coord to table"<<ui->lcdNumber_x->value()<<","<<ui->lcdNumber_y->value()<<endl;
    }
    else{
        ui->pushButton_board->click();
    }
}
