#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "QMdiSubWindow"
#include "QMdiArea"
#include "iostream"
#include "QFileDialog"
#include "QDebug"
#include "XmlFileReader.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
    headerItem->setText(0,QString("File Name"));
    headerItem->setText(1,QString("Content"));
    ui->treeWidget->setHeaderItem(headerItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cargarVentana(new Form(this));
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::cargarVentana(QWidget *widget)
{
    auto window = ui->mdiArea->addSubWindow(widget );
    window->setWindowTitle(widget->windowTitle());
    window->setWindowIcon(widget->windowIcon());
    window->show();
}

void MainWindow::on_actionOpen_project_triggered()
{

//    QString fileName = QFileDialog::getOpenFileName(this,tr("Open XML File 2"), "/home", tr("XML Files (*.xml)"));
//    qDebug() << fileName ;
//    //
//    //readBasicStructure(fileName);
//    XmlFileReader
//    XmlReader reader;
//    std::string fileNameInStd =fileName.toUtf8().constData() ;
//    reader.read(fileNameInStd);

//    QTreeWidgetItem* input = new QTreeWidgetItem();
//    input->setText(0,"input");
//    input->setText(1,reader.inputFile);
//    QTreeWidgetItem* output = new QTreeWidgetItem();
//    output ->setText(0,"output");
//    output ->setText(1,reader.outputFile);

//    ui->treeWidget->addTopLevelItem(output );
//    ui->treeWidget->addTopLevelItem(input);
}

void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    qDebug() << "Column: " << index.column() << "Row:" << index.row();
    qDebug() << ui->treeWidget->currentItem()->text(0);
    cargarVentana(new Form(this));
    ui->mdiArea->activeSubWindow();
}