#include "FileChooserWindow.h"
#include "ui_FileChooserWindow.h"
#include <QFileDialog>


FileChooserWindow::FileChooserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileChooserWindow)
{
    ui->setupUi(this);
}

FileChooserWindow::~FileChooserWindow()
{
    delete ui;
}

void FileChooserWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("All Files (*.*)"));
    ui->lineEdit->setText(fileName);
}
