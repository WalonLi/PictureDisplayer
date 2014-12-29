/**
    Provide by Walon Li, YJ Fang

    File PlayerWindow.cpp
**/

#include "include/PlayerWindow.h"


PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player)
{
    this->setFixedSize(800, 600);
    ui->setupUi(this);
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
}
