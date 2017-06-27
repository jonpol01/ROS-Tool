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
//    QString program = "/home/johnpaul/new.py";
//    QString roslaunch = "roslaunch logiler_rviz_launchers view_navigation.launch";

    proc->waitForStarted();
    proc->startDetached("/usr/bin/gnome-terminal", QStringList()<< "-e" << "/bin/bash -c 'export ROS_MASTER_URI=http://localhost:11311; roslaunch logiler_rviz_launchers view_navigation.launch' ");
//    proc->startDetached("/usr/bin/gnome-terminal", QStringList()<< "-e" << "/bin/sh -c './launch.sh' ");


    proc->waitForFinished();
    proc->close();
}
