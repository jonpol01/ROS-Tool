#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ROS-Tools");
    this->setStyleSheet("background-color:gray;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess *proc = new QProcess(this);
    QString program = "/home/johnpaul/new.py";
    proc->startDetached(program);

    proc->close();
}
