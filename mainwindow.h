#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Downloader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    Downloader*   m_down;

private slots:
    void on_down_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
