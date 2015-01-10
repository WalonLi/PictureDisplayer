/**
    Provide by Walon Li, YJ Fang

    File PlaywrWindow.h
**/

#ifndef PLAYER_WINDOW_H
#define PLAYER_WINDOW_H

#include <QMainWindow>
#include "ui_Player.h"
#include "PlayerLayout/GraphicsView.h"

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
    pdr::GraphicsView *graphics_view_ ;
} ;

#endif // MAINWINDOW_H
