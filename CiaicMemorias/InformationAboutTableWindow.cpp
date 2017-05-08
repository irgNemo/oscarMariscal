#include "InformationAboutTableWindow.h"
#include "ui_InformationAboutTableWindow.h"

InformationAboutTableWindow::InformationAboutTableWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InformationAboutTableWindow)
{
    ui->setupUi(this);
}

InformationAboutTableWindow::~InformationAboutTableWindow()
{
    delete ui;
}

void InformationAboutTableWindow::setLineSize(int size)
{
    ui->lineEdit_Size->setText(QString::number(size));
}

void InformationAboutTableWindow::setLineName(QString name)
{
    ui->lineEdit_name->setText(name);
}

void InformationAboutTableWindow::setLineMode(int mode)
{
    //ui->lineEdit_Mode->setText(QString::number(mode));
    ui->lineEdit_Mean->setText(QString::number(mode));
}

