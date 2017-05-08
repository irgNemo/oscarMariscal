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
#include <string>
#include "ProjectEditor.h"
#include "CsvFileReader.h"
#include "GridEditor.h"
#include "InformationAboutTableWindow.h"
#include "FileChooserWindow.h"
#include "XmlFileWriter.h"
#include <vector>


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
}

MainWindow::~MainWindow()
{
    delete ui;
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
    //Testing and training sets
    QStringList testingSets = reader.getTestingSets();
    QTreeWidgetItem* topTesting = new QTreeWidgetItem();
    topTesting->setText(0,"Testing_Sets");
    int i=0;
    foreach (QString testFile, testingSets) {

        QTreeWidgetItem* testForTree = new QTreeWidgetItem();
        testForTree ->setText(0,QString::number(i));
        testForTree ->setText(1,testFile);
        i++;
        topTesting->addChild(testForTree);
    }
    input->addChild(topTesting);
    //Training
    QStringList training = reader.getTrainingSets();
    QTreeWidgetItem* topTraining = new QTreeWidgetItem();
    topTraining ->setText(0,"Training_Sets");
    i=0;
    qDebug() << training.size();
    foreach (QString trainFile, training) {
        QTreeWidgetItem* trainForTree = new QTreeWidgetItem();
        trainForTree ->setText(0,QString::number(i));
        trainForTree ->setText(1,trainFile);
        i++;
        topTraining->addChild(trainForTree);
    }
    input->addChild(topTraining);

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


    /*
    if (text.compare("ProjectName",Qt::CaseInsensitive) == 0){
        qDebug() << text << "Inside";
        ProjectEditor* ventana = new ProjectEditor();
        QString projectName = ui->treeWidget->currentItem()->text(1);
        QString inputFile = ui->treeWidget->currentItem()->child(0)->text(1);
        QString outputFile= ui->treeWidget->currentItem()->child(1)->text(1);
        ventana->setLineEdits(projectName,inputFile,outputFile);
        cargarVentana(ventana);
    }*/
    if (text.contains("Set") == 0){
        FileChooserWindow * ventana = new FileChooserWindow;
        QTreeWidgetItem * item=ui->treeWidget->currentItem();
        ventana->setItemOfFileTreeToEdit(item);
        cargarVentana(ventana);
    }
    else if (text.contains("Test") == 0){
        FileChooserWindow * ventana = new FileChooserWindow;
        ventana->setItemOfFileTreeToEdit(ui->treeWidget->currentItem());
        cargarVentana(ventana);
    }

    if (contents.endsWith(".csv",Qt::CaseInsensitive)){
        CsvFileReader reader(contents.toUtf8().constData());
        GridEditor* editorCsv = new GridEditor();

        InformationAboutTableWindow * stadistics = new InformationAboutTableWindow();
        editorCsv->setStadisticsWindow(stadistics);
        reader.read();
        std::vector<string> headers =  reader.getHeaders();
        QFile file(contents);
        //editorCsv->setWindowTitle(file.fileName());
        qDebug() << file.fileName();
        DataFormat data = reader.getDataFormat();
        editorCsv->setDataFormat(data);
        editorCsv->renameHeaders(headers);
        cargarVentana(stadistics);
        cargarVentana(editorCsv);
    }

}

void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug() << "That's where you're right kiddo";
    QMenu contextMenu;

    QAction trainingAction("Add Training set", this);
    connect(&trainingAction, SIGNAL(triggered()), this, SLOT(addTrainingSet()));
    contextMenu.addAction(&trainingAction);
    QAction testingAction("Add Testing set", this);
    connect(&testingAction, SIGNAL(triggered()), this, SLOT(addTestingSet()));
    contextMenu.addAction(&testingAction);
    QAction saveProjectAction("Save project", this);
    connect(&saveProjectAction, SIGNAL(triggered()), this, SLOT(saveProject()));
    contextMenu.addAction(&saveProjectAction);
    contextMenu.exec( QCursor::pos());
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

void MainWindow::saveProject()
{
    //Identifying the elements of the tree.
    QTreeWidgetItem * topLevel =  ui->treeWidget->topLevelItem(0);
    QTreeWidgetItem * input=  topLevel->child(0);
    QTreeWidgetItem * output=  topLevel->child(1);
    QTreeWidgetItem * topTestingSets = NULL;
    QTreeWidgetItem * topTrainingSets= NULL;
    qDebug() << topLevel->text(1);
    if (input->childCount()>0){
        //In case there's only a training or testing set.
        if (input->childCount()==1){
            if (input->child(0)->text(0).compare("training sets",Qt::CaseInsensitive) == 0){
                topTrainingSets=input->child(0);
            }
            else if (input->child(0)->text(0).compare("Testing sets",Qt::CaseInsensitive) == 0){
                topTestingSets=input->child(0);
            }
        }
        //In case there's training and testing sets.
        if (input->childCount()==2){
            if (input->child(0)->text(0).compare("training sets",Qt::CaseInsensitive) == 0){
                topTrainingSets=input->child(0);
                topTestingSets =input->child(1);
            }
            else if (input->child(0)->text(0).compare("Training",Qt::CaseInsensitive) == 0){
                topTestingSets =input->child(0);
                topTrainingSets=input->child(1);
            }
        }
    }
    //Writing to file.
    XmlFileWriter writer;
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save Address Book"), "",
                            tr("Address Book (*.abk);;All Files (*)"));
    writer.setFileName(fileName.toUtf8().constData() );

    QString projectName= topLevel->text(1);
    QString outputText= output->text(1);
    //training sets
    writer.setProjectName( projectName.toUtf8().constData());
    writer.setOutputFile(outputText.toUtf8().constData());
    if (topTrainingSets!=NULL){
        for (int i = 0 ; i < topTrainingSets->childCount();i++){
            writer.addTrainingSet( topTrainingSets->child(i)->text(1));
        }

    }
    //Testing sets
    if (topTestingSets!=NULL){
        for (int i =0 ; i < topTestingSets->childCount();i++){
            writer.addTestingSet( topTestingSets->child(i)->text(1) );
        }
    }
    writer.write();




}


void MainWindow::on_actionlicenses_triggered()
{
    LicensesWindow *licences = new LicensesWindow();
    licences->show();
}

void MainWindow::on_actionNew_project_triggered()
{
    qDebug() << "Helos";
    ProjectEditor* ventana = new ProjectEditor();
    ventana->setTreeWidget(ui->treeWidget);
    //ventana->setLineEdits(projectName,inputFile,outputFile);
    cargarVentana(ventana);

}
