/**
    Provide by Walon Li, YJ Fang

    File PlayerWindow.cpp
**/


#include <QPushButton>
#include <QImage>
#include <QDebug>
#include <QScrollBar>
#include "include/Controller.h"
#include "include/PlayerWindow.h"
#include "include/Component/PictureComponent.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player),
    scene_(new QGraphicsScene())
{
    this->setFixedSize(800, 600);
    ui->setupUi(this);


    // set scene and block wheel signal
    ui->graphicsView->setScene(scene_);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->verticalScrollBar()->blockSignals(true) ;
    ui->graphicsView->horizontalScrollBar()->blockSignals(true) ;

    // set not frame less
    this->setWindowFlags(Qt::FramelessWindowHint);

    // set static scene size
    scene_->setSceneRect(0,0,800,600);

    // set controller
    pdr::Controller *controller = pdr::Controller::getInstance();
    controller->setParentWidget(this);
    controller->setGraphicsView(ui->graphicsView);

}

PlayerWindow::~PlayerWindow()
{
    delete ui;
    delete scene_ ;
}
