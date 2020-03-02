#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_target_clicked();

    void on_pushButton_board_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat img_target,img_board;
    void initTableView();
    cv::Mat openImage();
    QImage cvtMat2QImage(cv::Mat src);
};

#endif // MAINWINDOW_H
