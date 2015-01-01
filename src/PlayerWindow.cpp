/**
    Provide by Walon Li, YJ Fang

    File PlayerWindow.cpp
**/

#include "include/PlayerWindow.h"
#include <QPushButton>
#include <QImage>
#include <QDebug>
#include "include/Component/PictureComponent.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player),
    scene(new QGraphicsScene())
{
    this->setFixedSize(800, 600);
    ui->setupUi(this);



    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // sampe as below
    // scene->addWidget(new QPushButton("123"));
    scene->addWidget(new pdr::PictureComponent(scene, new QImage("image/walon.jpg"), pdr::PictureComponent::IgnoreAspecRatio)) ;
    qDebug() << scene->height() << scene->width();
    // pdr::PictureComponent* comp = new pdr::PictureComponent(scene, new QImage("image/walon.jpg")) ;
    // scene->addWidget(comp) ;
}

PlayerWindow::~PlayerWindow()
{
    delete ui;
    delete scene ;
}
