#include "viewTestResults.h"
#include "ui_viewTestResults.h"

viewTestResults::viewTestResults(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewTestResults)
{
    ui->setupUi(this);
}

viewTestResults::~viewTestResults()
{
    delete ui;
}
