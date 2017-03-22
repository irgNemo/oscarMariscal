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
#include "ProjectEditor.h"

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
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open XML File 2"), "/home", tr("XML Files (*.xml)"));
    qDebug() << fileName ;
    XmlFileReader reader(fileName.toUtf8().constData());
    std::string fileNameInStd =fileName.toUtf8().constData() ;
    reader.read();
    QTreeWidgetItem* projectName = new QTreeWidgetItem();
    projectName->setText(0,"ProjectName");
    projectName->setText(1,reader.getProjectName());
    QTreeWidgetItem* input = new QTreeWidgetItem();
    input->setText(0,"input");
    input->setText(1,reader.getInputFile());
    QTreeWidgetItem* output = new QTreeWidgetItem();
    output ->setText(0,"output");
    output ->setText(1,reader.getOutputFile());

    projectName->addChild(input);
    projectName->addChild(output);
    ui->treeWidget->addTopLevelItem(projectName);
}

void MainWindow::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    qDebug() << "Column: " << index.column() << "Row:" << index.row();
    QString text = ui->treeWidget->currentItem()->text(0);
    qDebug() << text;
//    cargarVentana(new Form(this));
//    ui->mdiArea->activeSubWindow();
    //ui->treeWidget->curren

    if (text.compare("ProjectName",Qt::CaseInsensitive) == 0){
        qDebug() << text << "Inside";
        ProjectEditor* ventana = new ProjectEditor();
        QString projectName = ui->treeWidget->currentItem()->text(1);
        QString inputFile = ui->treeWidget->currentItem()->child(0)->text(1);
        QString outputFile= ui->treeWidget->currentItem()->child(1)->text(1);
        ventana->setLineEdits(projectName,inputFile,outputFile);
        cargarVentana( ventana );
    }
}
