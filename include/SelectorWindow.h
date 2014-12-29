/**
    Provide by Walon Li, YJ Fang

    File SelectorWindow.h
**/

#ifndef SELECTOR_WINDOW_H
#define SELECTOR_WINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "ui_Selector.h"

namespace Ui {
class Selector;
}

class SelectorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectorWindow(QWidget *parent = 0);
    ~SelectorWindow();

private slots:
    void on_select_button_clicked();

private:
    Ui::Selector *ui;
} ;

#endif // MAINWINDOW_H
