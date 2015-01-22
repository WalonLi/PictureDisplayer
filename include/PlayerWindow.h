/**
    Provide by Walon Li, YJ Fang

    File PlaywrWindow.h
**/

#ifndef PLAYER_WINDOW_H
#define PLAYER_WINDOW_H

#include <QMainWindow>
#include <QTimer>
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

signals:
    void playerEndSignal() ;


private slots:
    void playerEndSlot() ;
    void closeBtnClickSlot() ;
    void ppBtnClickSlot() ;
    void hideButtons() ;
    // void ppBtnChangeIconSlot() ;

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
