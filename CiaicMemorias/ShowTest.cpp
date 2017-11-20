#include "ShowTest.h"
#include "ui_ShowTest.h"
#include <QFileInfo>
#include <CsvFileReader.h>
#include <QDebug>
#include "LearnMatrix.h"
#include "BinaryAssociativeMemories.h"
#include "DataFormat.h"
#include "qdebug.h"
#include "CsvFileReader.h"
#include <string>


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
    output = project->child(1);
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

    for (int i = 0; i < testingSets->childCount();i++){
        QFileInfo fileInfo(testingSets->child(i)->text(1));
        QString filename(fileInfo.fileName());
        ui->comboBoxTesting->addItem(filename,QVariant(i));//saving the index of the child node in qvariant
    }

}

//Creates a learning algorithm based on the info in the tree.
void ShowTest::recreateLearningAlgorithm()
{


    //QString matrix = output->text(1);
    //QString outputVectors = project->child(2)->text(1);
    //std::string pathMatrix = matrix.toUtf8().constData();
    //std::string pathOutputVector = outputVectors.toUtf8().constData();
    //CsvFileReader reader(pathMatrix);
    //CsvFileReader reader(pathOutputVector);
    //LearnMatrix* learn = new LearnMatrix(reader.getDataFormat());
    //algorithm = learn;
    //learn->set
    //Reading the files;


    //learn->setMatriz(reader.getDataFormat().getFundamentalSet());
    //algorithm.setMatriz();
    //algorithm.setVectorSalida();
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
