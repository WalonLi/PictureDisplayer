/**
    Provide by Walon Li, YJ Fang

    File PlayerWindow.cpp
**/


#include <QDebug>
#include "include/Controller.h"
#include "include/PlayerWindow.h"

PlayerWindow::PlayerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Player),
    graphics_view_(NULL)
{
    this->setFixedSize(800, 600);
    ui->setupUi(this);

    // connect signal
    QObject::connect(this, SIGNAL(playerEndSignal()), this, SLOT(playerEndSlot())) ;

    // set not frame less
    this->setWindowFlags(Qt::FramelessWindowHint);

    // set graphics view
    graphics_view_ = new pdr::GraphicsView(ui->centralWidget) ;

    // set mouse track
    // this->setMouseTracking(true);
    // ui->centralWidget->setMouseTracking(true);
    // graphics_view_->setMouseTracking(true);


    // set controller
    pdr::Controller *controller = pdr::Controller::getInstance();
    controller->setPlayerWindow(this);
    controller->setGraphicsView(graphics_view_);

    //boost::thread m_t(&pdr::Controller::play, controller) ;
}

void PlayerWindow::playerEndSlot()
{
    qDebug() << "End" ;
    QApplication::quit() ;
}

void PlayerWindow::closeBtnClickSlot()
{
    pdr::Controller::getInstance()->stop();
    QApplication::quit() ;
}

void PlayerWindow::ppBtnClickSlot()
{
    qDebug() << "Play ause btn clicked" ;

    pdr::Controller *controller = pdr::Controller::getInstance();

    if (controller->getState() == pdr::Controller::CTRL_PAUSE)
    {
        controller->resume();
        graphics_view_->getPlayPauseBtn()->setBtnPixmap(false);
    }
    else if (controller->getState() == pdr::Controller::CTRL_PLAY)
    {
        controller->pause();
        graphics_view_->getPlayPauseBtn()->setBtnPixmap(true);
    }
}


PlayerWindow::~PlayerWindow()
{
    delete ui;
    delete graphics_view_ ;
}

