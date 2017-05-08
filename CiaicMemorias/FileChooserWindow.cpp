#include "FileChooserWindow.h"
#include "ui_FileChooserWindow.h"
#include <QFileDialog>
#include <QTreeWidget>



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

void FileChooserWindow::setItemOfFileTreeToEdit(QTreeWidgetItem* item)
{
    this->item = item;
}

void FileChooserWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("All Files (*.*)"));
    ui->lineEditFile->setText(fileName);
}

void FileChooserWindow::on_pushButton_save_clicked()
{
    item->setText(1,ui->lineEditFile->text());
}
