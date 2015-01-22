/**
    Provide by Walon Li, YJ Fang

    File PlaywrWindow.h
**/

#ifndef PLAYER_WINDOW_H
#define PLAYER_WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Component/Component.h"
#include "ui_Player.h"
#include "PlayerLayout/GraphicsView.h"
#include "PlayerLayout/PlayPauseBtn.h"
#include "PlayerLayout/CloseBtn.h"
#include "PlayerLayout/CycleBtn.h"
#include "PlayerLayout/LoadFileBtn.h"

namespace Ui {
class Player;
}

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerWindow(QWidget *parent = 0);
    ~PlayerWindow();


    void timerEvent(QTimerEvent*);



private slots:
    void endPlaySlots() ;
    void closeBtnClickSlot() ;
    void ppBtnClickSlot() ;
    void hideButtons() ;
    // void ppBtnChangeIconSlot() ;

    void playCompSlots(pdr::Component*) ;
    void pauseCompSlots(pdr::Component*) ;
    void resumeCompSlots(pdr::Component*) ;
    void stopCompSlots(pdr::Component*) ;

private:
    Ui::Player *ui;
    pdr::GraphicsView *graphics_view_ ;

    QTimer *button_timer_ ;
    pdr::CloseBtn *close_btn_;
    pdr::LoadFileBtn *load_file_btn_;
    pdr::CycleBtn *cycle_btn_;
    pdr::PlayPauseBtn *pp_btn_;
} ;

#endif // MAINWINDOW_H
