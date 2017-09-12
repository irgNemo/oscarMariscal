#include "executewindow.h"
#include "ui_executewindow.h"
#include "QDebug"
#include "LearnMatrix.h"
#include "CsvFileReader.h"
#include "CsvFileWriter.h"
#include <QRegExp>
#include <QVariant>
#include <QFileDialog>
#include "DataFormat.h"
#include "LearnMatrix.h"
#include <vector>

void ExecuteWindow::setProject(QTreeWidgetItem *value)
{
    project = value;
}

void ExecuteWindow::fillComboBoxes()
{
    //TODO: this should be on the constructor.
    QStringList items=(QStringList()<<"LearnMatrix" );
    ui->comboBoxLearning->insertItems(0,items);
    QTreeWidgetItem* input = project->child(0);
    QTreeWidgetItem* topTrainingSets;
    QTreeWidgetItem* topTestingSets;
    //There needs to be at least one training and testing set.

    if (input->childCount()>1){
        //At the time there's only two possible options
        if (input->childCount()==2){
            if (input->child(0)->text(0).compare("training sets",Qt::CaseInsensitive) == 0){
                topTrainingSets= input->child(0);
                topTestingSets = input->child(1);
            }
            else if (input->child(0)->text(0).compare("Training",Qt::CaseInsensitive) == 0){
                topTestingSets =input->child(0);
                topTrainingSets=input->child(1);
            }
        }
    }
    testingSets= topTestingSets;
    trainingSets = topTrainingSets;
    //Filling the comboBoxes, to choose the testing and training set.

    for (int i = 0; i < testingSets->childCount();i++){
        ui->comboBoxTesting->addItem(QString::number(i+1),QVariant(i));//saving the index of the child node in qvariant
    }
    for (int i = 0; i < trainingSets->childCount();i++){
        ui->comboBoxTraining->addItem(QString::number(i+1),QVariant(i));
    }

}

ExecuteWindow::ExecuteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExecuteWindow)
{
    ui->setupUi(this);
}



void ExecuteWindow::applyLearnMatrix()
{
    //Getting the fiels
    int indexOffileToUse = ui->comboBoxTraining->currentIndex();
    QString filePathOfFile = trainingSets->child(indexOffileToUse)->text(1);
    CsvFileReader reader(filePathOfFile.toUtf8().constData());
    reader.read();
    DataFormat data = reader.getDataFormat();
    //Learn
    LearnMatrix learn(data);
    learn.oneHot();
    learn.learningMethod();
    //Writing
    DataFormat dataToWrite;
    dataToWrite.setFundamentalSet(learn.getMatriz());
    //TODO Check to se if this is the correct way to make the columns and rows!.
    dataToWrite.setNumCol(data.getNumCol());
    dataToWrite.setNumFil(data.getNumFil());
    CsvFileWriter writer;
    writer.setDataFormat(dataToWrite);
    //std::vector
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save output of matrix"), "",
                            tr("Csv file (*.csv);;All Files (*)"));
    writer.setFileName(fileName.toUtf8().constData());

    project->child(1)->setText(1,fileName);

    writer.write();

}

ExecuteWindow::~ExecuteWindow(){
    delete ui;
}

void ExecuteWindow::on_buttonBox_accepted()
{
    QString algorithm =  ui->comboBoxLearning->currentText();
    if(QString::compare( algorithm,"LearnMatrix",Qt::CaseInsensitive)==0){
        applyLearnMatrix();
    }
}
