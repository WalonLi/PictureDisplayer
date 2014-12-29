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
    this->setFixedSize(300, 100);
    ui->setupUi(this);
}

SelectorWindow::~SelectorWindow()
{
    delete ui;
}

void SelectorWindow::on_select_btn_clicked()
{
    QString file_name ;
    file_name = QFileDialog::getOpenFileName(this, "Choose your script file.") ;
    qDebug() << file_name ;
}

void SelectorWindow::on_load_btn_clicked()
{
    this->close() ;
}
