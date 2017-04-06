#include "LicensesWindow.h"
#include "ui_LicensesWindow.h"

LicensesWindow::LicensesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LicensesWindow)
{
    ui->setupUi(this);
}

LicensesWindow::~LicensesWindow()
{
    delete ui;
}
