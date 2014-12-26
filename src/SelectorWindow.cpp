/**
    Provide by Walon Li, YJ Fang

    File SelectorWindow.cpp
**/

#include "include/SelectorWindow.h"


SelectorWindow::SelectorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Selector)
{
    ui->setupUi(this);
}

SelectorWindow::~SelectorWindow()
{
    delete ui;
}
