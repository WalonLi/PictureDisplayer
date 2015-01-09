/**
    Provide by Walon Li, YJ Fang

    File PlaywrWindow.h
**/

#ifndef PLAYER_WINDOW_H
#define PLAYER_WINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ui_Player.h"
#include "Button/PlayPauseBtn.h"

namespace Ui {
class Player;
}

class PlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerWindow(QWidget *parent = 0);
    ~PlayerWindow();

signals:
    void sendPlayerEndSignal() ;

private slots:
    void getPlayerEndSignal() ;

private:
    Ui::Player *ui;
    QGraphicsScene *scene_;
    pdr::PlayPauseBtn *pp_btn_;
} ;

#endif // MAINWINDOW_H
