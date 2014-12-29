/**
    Provide by Walon Li, YJ Fang

    File SelectorWindow.cpp
**/

#include <QDebug>
#include "include/SelectorWindow.h"


SelectorWindow::SelectorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Selector)
{
    this->setFixedSize(300, 70);
    ui->setupUi(this);
}

SelectorWindow::~SelectorWindow()
{
    delete ui;
}

void SelectorWindow::on_select_button_clicked()
{
    QString file_name ;
    file_name = QFileDialog::getOpenFileName(this, "Choose your script file.") ;
    qDebug() << file_name ;
}
