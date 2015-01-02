/**
    Provide by Walon Li, YJ Fang

    File PlayerWindow.cpp
**/

#include "include/PlayerWindow.h"
#include <QPushButton>
#include <QImage>
#include <QDebug>
#include <QScrollBar>
#include "include/Component/PictureComponent.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player),
    scene(new QGraphicsScene())
{
    this->setFixedSize(800, 600);
    ui->setupUi(this);


    // set scene and block wheel signal
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->verticalScrollBar()->blockSignals(true) ;
    ui->graphicsView->horizontalScrollBar()->blockSignals(true) ;

    // set not frame less
    this->setWindowFlags(Qt::FramelessWindowHint);


    scene->setSceneRect(0,0,800,600);
    /*
    scene->addItem(new pdr::PictureComponent(scene,
                                             new QImage("image/walon.jpg"),
                                             pdr::PictureComponent::IgnoreAspecRatio));
    */
    scene->addItem(new pdr::PictureComponent(scene, new QImage("image/walon.jpg"))) ;



    // Test Code
    // VM CentOS not support opcacity now, I will test it with Windows later.
    /*
    QPalette pal = palette() ;
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    this->setWindowOpacity(0.7);
    this->setPalette(pal);
    this->setAttribute(Qt::WA_TranslucentBackground, true) ;
    this->setPalette(pal);

    scene->setPalette(pal);
    ui->graphicsView->setWindowOpacity(0.7);
    ui->graphicsView->setWindowFlags(Qt::FramelessWindowHint);
    ui->graphicsView->setAttribute(Qt::WA_NoBackground, true);
    ui->graphicsView->setAttribute(Qt::WA_NoSystemBackground, true) ;
    ui->graphicsView->setAttribute(Qt::WA_TranslucentBackground, true) ;

    ui->graphicsView->setPalette(pal);
    */


}

PlayerWindow::~PlayerWindow()
{
    delete ui;
    delete scene ;
}
