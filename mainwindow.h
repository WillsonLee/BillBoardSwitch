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
    bool openImage(cv::Mat &dst);
    QImage cvtMat2QImage(cv::Mat src);
public slots:
    void changeX(int x);
    void changeY(int y);
    void targetImageClicked(bool loaded);
    void boardImageClicked(bool loaded);
};

#endif // MAINWINDOW_H
