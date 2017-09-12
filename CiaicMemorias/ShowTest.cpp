#include "ShowTest.h"
#include "ui_ShowTest.h"
#include <QFileInfo>
#include <CsvFileReader.h>
#include <QDebug>
#include "LearnMatrix.h"

ShowTest::ShowTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowTest)
{
    ui->setupUi(this);
}

ShowTest::~ShowTest()
{
    delete ui;
}
void ShowTest::setProject(QTreeWidgetItem *value)
{
    project = value;
}


void ShowTest::fillComboBoxes()
{
    QTreeWidgetItem* input = project->child(0);
    QTreeWidgetItem* topTestingSets;
    //There needs to be at least one training and testing set.
    if (input->childCount()>1){
        if (input->child(0)->text(0).compare("training sets",Qt::CaseInsensitive) == 0){
            topTestingSets = input->child(1);
        }
        else if (input->child(0)->text(0).compare("Training",Qt::CaseInsensitive) == 0){
            topTestingSets =input->child(0);
        }

    }
    testingSets= topTestingSets;
    //Filling the comboBoxes, to choose the testing and training set.
    for (int i = 0; i < testingSets->childCount();i++){
        QFileInfo fileInfo(testingSets->child(i)->text(1));
        QString filename(fileInfo.fileName());
        ui->comboBoxTesting->addItem(filename,QVariant(i));//saving the index of the child node in qvariant
    }
}

void ShowTest::on_pushButton_pressed()
{
    /*
    //Getting the fiels
    int indexOffileToUse = ui->comboBoxTesting->currentIndex();
    QString filePathOfFile = trainingSets->child(indexOffileToUse)->text(1);
    CsvFileReader reader(filePathOfFile.toUtf8().constData());
    reader.read();
    DataFormat data = reader.getDataFormat();
    //Learn
    LearnMatrix learn(data);
    learn.setMatriz();
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
    */
}
