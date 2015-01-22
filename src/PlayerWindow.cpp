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
    graphics_view_(NULL),
    button_timer_(new QTimer()),
    close_btn_(NULL),
    load_file_btn_(NULL),
    cycle_btn_(NULL),
    pp_btn_(NULL)
{
    this->setFixedSize(800, 600);
    ui->setupUi(this);

    // connect signal
    QObject::connect(this, SIGNAL(playerEndSignal()), this, SLOT(playerEndSlot())) ;

    // set not frame less
    this->setWindowFlags(Qt::FramelessWindowHint);

    // set graphics view
    graphics_view_ = new pdr::GraphicsView(ui->centralWidget) ;
    close_btn_ = new pdr::CloseBtn(graphics_view_) ;
    load_file_btn_ = new pdr::LoadFileBtn(graphics_view_) ;
    cycle_btn_ = new pdr::CycleBtn(graphics_view_) ;
    pp_btn_ = new pdr::PlayPauseBtn(graphics_view_) ;


    // set mouse track
    // this->setMouseTracking(true);
    // ui->centralWidget->setMouseTracking(true);
    // graphics_view_->setMouseTracking(true);


    // set controller
    pdr::Controller *controller = pdr::Controller::getInstance();
    controller->setPlayerWindow(this);
    controller->setGraphicsView(graphics_view_);

    //boost::thread m_t(&pdr::Controller::play, controller) ;

    QObject::connect(button_timer_, SIGNAL(timeout()), this, SLOT(hideButtons())) ;
    this->startTimer(500) ;
}


void PlayerWindow::timerEvent(QTimerEvent*)
{
    static QPoint org = QCursor::pos() ;
    QPoint mod = QCursor::pos() ;

    // check cursor in views or not
    if (!this->rect().contains(this->mapFromGlobal(mod)))
        return  ;

    if (mod != org)
    {
        org = mod ;
        button_timer_->stop();
        // check button alive or not
        if (close_btn_->isHidden()
            && load_file_btn_->isHidden()
            && cycle_btn_->isHidden()
            && pp_btn_->isHidden())
        {
            close_btn_->play();
            load_file_btn_->play();
            cycle_btn_->play();
            pp_btn_->play();
        }
        button_timer_->start(3000);
    }
}

void PlayerWindow::hideButtons()
{
    close_btn_->hide();
    load_file_btn_->hide();
    cycle_btn_->hide();
    pp_btn_->hide();
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
        pp_btn_->setBtnPixmap(false);
    }
    else if (controller->getState() == pdr::Controller::CTRL_PLAY)
    {
        controller->pause();
        pp_btn_->setBtnPixmap(true);
    }
}


PlayerWindow::~PlayerWindow()
{
    delete close_btn_;
    delete load_file_btn_;
    delete cycle_btn_;
    delete pp_btn_;
    delete graphics_view_ ;
    delete ui;
}

