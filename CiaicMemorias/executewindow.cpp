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
#include "ConfusionMatrix.h"
#include <QTextStream>
#include "QFile"




void ExecuteWindow::setProject(QTreeWidgetItem *value)
{
    project = value;
}

void ExecuteWindow::fillComboBoxes()
{
    //TODO: this should be on the constructor.
    QStringList items=(QStringList()<<"LearnMatrix" );
    ui->comboBoxAlgorithm->insertItems(0,items);
    QTreeWidgetItem* input = project->child(0);
    QTreeWidgetItem* topTrainingSets;
    QTreeWidgetItem* topTestingSets;

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
        QFileInfo fileInfo(testingSets->child(i)->text(1));
        QString filename(fileInfo.fileName());
        ui->comboBoxTesting->addItem(filename,QVariant(i));
        ui->comboBoxCrossVal->addItem(filename,QVariant(i));
    }
    for (int i = 0; i < trainingSets->childCount();i++){

        QFileInfo fileInfo(trainingSets->child(i)->text(1));
        QString filename(fileInfo.fileName());
        ui->comboBoxTraining->addItem(filename,QVariant(i));//saving the index of the child node in qvariant
        ui->comboBoxCrossVal->addItem(filename,QVariant(i));
    }

}

void ExecuteWindow::doTesting()
{
    int indexOffileToUse = ui->comboBoxTraining->currentIndex();
    QString filePathOfFile = testingSets->child(indexOffileToUse)->text(1);
    CsvFileReader reader(filePathOfFile.toUtf8().constData());
    reader.read();
    DataFormat  data = reader.getDataFormat();
    int ** testingOutput = new int* [data.getNumFil()];

    int ** inputPatterns = data.getFundamentalSet();
    for (int i =0 ; i < data.getNumFil();i++){
        testingOutput[i] = algorithm->retrievalMethod(inputPatterns[i],data.getNumCol());
    }

    DataFormat output;
    output.setFundamentalSet(testingOutput);
    output.setNumFil(data.getNumFil());
    output.setNumCol(data.getNumCol());
    CsvFileWriter writer;
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Output of testing"), "",
                            tr("Csv file (*.csv);;All Files (*)"));
    writer.setFileName(fileName.toUtf8().constData());
    writer.setDataFormat(output);
    writer.write();

}

int ExecuteWindow::getClassNumber(int *pattern, int size)
{
    for (int i = 0 ; i< size ; i++){
        if (pattern[i]==1)
            return i;
    }
}

ExecuteWindow::ExecuteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExecuteWindow)
{
    ui->setupUi(this);
    ui->radioNormal->setChecked(true);
    toggleUserInterfaceAlgorithms();
}


//Change the name.
void ExecuteWindow::applyLearnMatrix()
{
    //Getting the fields
    int indexOffileToUse = ui->comboBoxTraining->currentIndex();
    QString filePathOfFile = trainingSets->child(indexOffileToUse)->text(1);
    CsvFileReader reader(filePathOfFile.toUtf8().constData());
    reader.read();
    DataFormat data = reader.getDataFormat();
    //Learn
    LearnMatrix *learn = new LearnMatrix(data);

    learn->oneHot();
    learn->learningMethod();
    //Writing
    DataFormat dataToWrite;
    dataToWrite.setFundamentalSet(learn->getMatriz());
    //TODO Check to se if this is the correct way to make the columns and rows!.
    dataToWrite.setNumCol(data.getNumCol());
    dataToWrite.setNumFil(data.getNumFil());

    CsvFileWriter writer;
    writer.setDataFormat(dataToWrite);
    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Save output of matrix"), "",
                            tr("Csv file (*.csv);;All Files (*)"));
    writer.setFileName(fileName.toUtf8().constData());

    project->child(1)->setText(1,fileName);

    writer.write();

    //Writing the output vectors.
    CsvFileWriter outputVectorWriter;
    DataFormat outputVectors;
    outputVectors.setFundamentalSet( learn->getVectorSalida());
    //Both set to numFil Because in the moment it's using oneHot
    outputVectors.setNumCol(data.getNumFil());
    outputVectors.setNumFil(data.getNumFil());
    outputVectorWriter.setDataFormat(outputVectors);
    fileName = QFileDialog::getSaveFileName(this,
                            tr("Output Vectors"), "",
                            tr("Csv file (*.csv);;All Files (*)"));
    outputVectorWriter.setFileName(fileName.toUtf8().constData());
    outputVectorWriter.write();
    project->child(2)->setText(0,"outputVector");
    project->child(2)->setText(1,fileName);
    algorithm = learn;
    doTesting();

}



ExecuteWindow::~ExecuteWindow(){
    delete ui;
}

void ExecuteWindow::on_buttonBox_accepted()
{
    QString algorithm =  ui->comboBoxAlgorithm->currentText();
    if(QString::compare( algorithm,"LearnMatrix",Qt::CaseInsensitive)==0){
        applyLearnMatrix();
    }
}


//This method changes the ui so only is iether k-fold validation selected or the other method
void ExecuteWindow::toggleUserInterfaceAlgorithms()
{
    ui->comboBoxTesting->setEnabled(ui->radioNormal->isChecked());
    ui->comboBoxTraining->setEnabled(ui->radioNormal->isChecked());
    ui->comboBoxCrossVal->setEnabled(ui->radioCrossVal->isChecked());
    ui->kSize->setEnabled(ui->radioCrossVal->isChecked());
}

bool ExecuteWindow::equalPatterns(int *patternOne, int *patternTwo, int xSize)
{
    for (int i = 0 ; i < xSize; i++){
        if (patternOne[i] != patternTwo[i])
            return false;
    }
    return true;
}



void ExecuteWindow::on_radioNormal_toggled(bool checked)
{
    toggleUserInterfaceAlgorithms();
}

//Should have a better name, this is k-fold-crossValidation
void ExecuteWindow::on_buttonBoxCross_accepted()
{

    // Reading the output vectors
    QString filePathOfFile = project->child(2)->text(1);
    CsvFileReader readerOutputVector(filePathOfFile.toUtf8().constData());
    readerOutputVector.read();
    DataFormat outputVectors = readerOutputVector.getDataFormat();

    //TODO make code so that we are actually using the correct file
    //input
    int indexOffileToUse = ui->comboBoxTraining->currentIndex();
    filePathOfFile = trainingSets->child(indexOffileToUse)->text(1);
    CsvFileReader reader(filePathOfFile.toUtf8().constData());
    reader.read();
    DataFormat data = reader.getDataFormat();
    //
    int ksize = ui->kSize->value();
    int instancesSize = data.getNumFil();
    int numberOfGroups = instancesSize/ksize;
    QVector <int*> allInstances;
    QVector <int*> outputClasses;
    int ** fundamentalSet = data.getFundamentalSet();

    for (int i = 0 ; i < data.getNumFil(); i++){
        allInstances.append(fundamentalSet[i]);

    }
    for (int i = 0; i < outputVectors.getNumFil();i++){
        outputClasses.append(outputVectors.getFundamentalSet()[i]);
    }
    DataFormat bins[numberOfGroups];
    DataFormat desiredOutput[numberOfGroups];
    for ( int i = 0 ; i < numberOfGroups ;i++){
        int ** entry = new int* [numberOfGroups];
        int ** output = new int* [numberOfGroups];
        if (allInstances.size()>=ksize){
            for (int j = 0; j < ksize; j++){
                entry[j] = allInstances.first();
                output[j] = outputClasses.first();
                outputClasses.pop_front();
                allInstances.pop_front();
            }
        }
        if (allInstances.size()==1 && ksize!=1){
            entry[ksize] = allInstances.first();
            output[ksize] = outputClasses.first();
            outputClasses.pop_front();
            allInstances.pop_front();
        }
        desiredOutput[i].setFundamentalSet(output);
        desiredOutput[i].setNumCol(outputVectors.getNumCol());
        desiredOutput[i].setNumFil(ksize);

        bins[i].setFundamentalSet(entry);
        bins[i].setNumCol(data.getNumCol());
        bins[i].setNumFil(ksize);
    }

    int totalOfErrors=0;
    int totalOfTests=0;
    int errors=0;
    int numberOfTests;




    std::vector <ConfusionMatrix> confusionMatrixes;
    QString stringForFile="";
    //confusionMatrixes.append();
    for (int i = 0; i< numberOfGroups; i++){
        LearnMatrix matrix(bins[i]);
        matrix.setVectorSalida(desiredOutput[i].getFundamentalSet());
        matrix.learningMethod();
        for (int j = 0; j < numberOfGroups; j++){
            if (i==j){
                continue;
            }

            errors=0;
            numberOfTests=bins[j].getNumFil();
            int ** patterns = bins[j].getFundamentalSet();
            int ** desiredOutputs=  desiredOutput[j].getFundamentalSet();
            ConfusionMatrix confusionMatrix(bins[j].getNumCol());
            for (int k =  0 ; k < bins[j].getNumFil(); k++){
                int * pattern = matrix.retrievalMethod(patterns[k],bins[j].getNumCol());
                int sizeOfPattern = bins[j].getNumCol();
                int classInstance = getClassNumber(desiredOutputs[k],sizeOfPattern);
                int classifyAs = getClassNumber(pattern,sizeOfPattern);
                confusionMatrix.addInstance(classInstance,classifyAs);
                /*
                if (!equalPatterns(pattern,desiredOutputs[k],bins[j].getNumCol())){
                    errors++;
                }*/
                confusionMatrixes.push_back(confusionMatrix);
            }

            ConfusionMatrix currentMatrix = confusionMatrixes.at(0);
            QString cadena(currentMatrix.getStringRepresentation().c_str()) ;
            stringForFile+= "current: ";
            stringForFile+= QString::number(i);
            stringForFile+= "testing on: ";
            stringForFile+= QString::number(j);
            stringForFile+= "\n";
            stringForFile+= cadena;

            /*
            totalOfErrors+=errors;
            totalOfTests+=numberOfTests;
            qDebug() << "-------- IN K learning: " << i <<" K testing: " << j ;
            qDebug() << "errors: " <<errors;
            qDebug() << "tests: " <<numberOfTests;*/
        }
    }

    QString fileName = QFileDialog::getSaveFileName(this,
                            tr("Output of k-fold"), "",
                            tr("Txt File (*.txt);;All Files (*)"));
    QFile file (fileName);
    QTextStream out(stdout);
    if (file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        stream << stringForFile;
    }
    file.close();

    //qDebug() << "total of errors: " <<totalOfErrors;
    //qDebug() << "total of tests: " <<numberOfTests;

//    for (int i = 0; i< numberOfGroups; i++){
//        LearnMatrix matrix(bins[i]);
//        matrix.setVectorSalida(desiredOutput[i].getFundamentalSet());
//        matrix.learningMethod();
//        for (int j = 0; j < numberOfGroups; j++){
//            if (i==j){
//                continue;
//            }

//            errors=0;
//            numberOfTests=bins[j].getNumFil();
//            int ** patterns = bins[j].getFundamentalSet();
//            int ** desiredOutputs=  desiredOutput[j].getFundamentalSet();
//            for (int k =  0 ; k < bins[j].getNumFil(); k++){
//                int * pattern = matrix.retrievalMethod(patterns[k],bins[j].getNumCol());
//                if (!equalPatterns(pattern,desiredOutputs[k],bins[j].getNumCol())){
//                    errors++;
//                }
//            }

//            totalOfErrors+=errors;
//            totalOfTests+=numberOfTests;
//            qDebug() << "-------- IN K learning: " << i <<" K testing: " << j ;
//            qDebug() << "errors: " <<errors;
//            qDebug() << "tests: " <<numberOfTests;
//        }
//    }
//    qDebug() << "total of errors: " <<totalOfErrors;
//    qDebug() << "total of tests: " <<numberOfTests;
}


