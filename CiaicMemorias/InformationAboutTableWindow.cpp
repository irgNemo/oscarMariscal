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
