#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_down = new Downloader();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_down_clicked()
{
    QString url = "http://www.linuxkiss.com/themes/simplebootx/Public/images/demo/1.jpg";
    QString path = "/home/leo/Demo/Downloader/lahua_pic/1.jpg";
    m_down->downloadFileFromURL(url,path);
}
