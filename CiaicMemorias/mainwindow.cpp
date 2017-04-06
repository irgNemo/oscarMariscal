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
#include "CsvFileReader.h"
#include "GridEditor.h"
#include "InformationAboutTableWindow.h"
#include "FileChooserWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
    headerItem->setText(0,QString("File Name"));
    headerItem->setText(1,QString("Content"));
    ui->treeWidget->setHeaderItem(headerItem);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    //connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(on_treeWidget_customContextMenuRequested(QPoint)));
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
    QString text = ui->treeWidget->currentItem()->text(0);
    QString contents =ui->treeWidget->currentItem()->text(1);

    if (text.compare("ProjectName",Qt::CaseInsensitive) == 0){
        qDebug() << text << "Inside";
        ProjectEditor* ventana = new ProjectEditor();
        QString projectName = ui->treeWidget->currentItem()->text(1);
        QString inputFile = ui->treeWidget->currentItem()->child(0)->text(1);
        QString outputFile= ui->treeWidget->currentItem()->child(1)->text(1);
        ventana->setLineEdits(projectName,inputFile,outputFile);
        cargarVentana(ventana);
    }
    else if (text.compare("Set",Qt::CaseInsensitive) == 0){
        FileChooserWindow * ventana = new FileChooserWindow;
        cargarVentana(ventana);
    }
    else if (text.compare("Test",Qt::CaseInsensitive) == 0){
        FileChooserWindow * ventana = new FileChooserWindow;
        cargarVentana(ventana);
    }

    if (contents.endsWith(".csv",Qt::CaseInsensitive)){
        CsvFileReader reader(contents.toUtf8().constData());
        GridEditor* editorCsv = new GridEditor();
        InformationAboutTableWindow * stadistics = new InformationAboutTableWindow();
        reader.read();
        QFile file(contents);
        //editorCsv->setWindowTitle(file.fileName());
        qDebug() << file.fileName();
        DataFormat data = reader.getDataFormat();
        editorCsv->setDataFormat(data);
        cargarVentana(stadistics);
        cargarVentana(editorCsv);
    }

}

void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "That's where you're right kiddo";
    QMenu contextMenu(tr("Context menu"), ui->treeWidget);


    QAction trainingAction("Add Training set", this);
    connect(&trainingAction, SIGNAL(triggered()), this, SLOT(addTrainingSet()));
    contextMenu.addAction(&trainingAction);
    QAction testingAction("Add Testing set", this);
    connect(&testingAction, SIGNAL(triggered()), this, SLOT(addTestingSet()));
    contextMenu.addAction(&testingAction);
    contextMenu.exec(mapToGlobal( QCursor::pos() ));
}

void MainWindow::addTrainingSet()
{
    QTreeWidgetItem * topLevel =  ui->treeWidget->topLevelItem(0);
    QTreeWidgetItem * input=  topLevel->child(0);
    QTreeWidgetItem* topTraining = new QTreeWidgetItem();
    topTraining  ->setText(0,"Training Sets");

    QTreeWidgetItem* bottomTraining = new QTreeWidgetItem();
    bottomTraining ->setText(0,"Set");
    bottomTraining ->setText(1,"1");
    topTraining->addChild(bottomTraining);

    input->addChild(topTraining);
}

void MainWindow::addTestingSet()
{
    QTreeWidgetItem * topLevel =  ui->treeWidget->topLevelItem(0);
    QTreeWidgetItem * input=  topLevel->child(0);
    QTreeWidgetItem* topTraining = new QTreeWidgetItem();
    topTraining  ->setText(0,"Testing Sets");

    QTreeWidgetItem* bottomTraining = new QTreeWidgetItem();
    bottomTraining ->setText(0,"Test");
    bottomTraining ->setText(1,"1");
    topTraining->addChild(bottomTraining);

    input->addChild(topTraining);

}

void MainWindow::on_actionlicenses_triggered()
{
    LicensesWindow *licences = new LicensesWindow();
    licences->show();
}
