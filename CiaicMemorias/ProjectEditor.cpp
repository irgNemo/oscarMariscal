#include "ProjectEditor.h"
#include "ui_ProjectEditor.h"
#include "XmlFileWriter.h"

ProjectEditor::ProjectEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectEditor)
{
    ui->setupUi(this);
}

ProjectEditor::~ProjectEditor()
{
    delete ui;
}

void ProjectEditor::setLineEdits(QString projectName, QString filepathInput, QString filepatOutput)
{
    ui->projectNameLineEdit->setText(projectName);
    ui->inputFileLineEdit->setText(filepathInput);
    ui->outputFileLineEdit->setText(filepatOutput);
}

void ProjectEditor::on_saveButton_clicked()
{
    XmlFileWriter writer;
    writer.setInputFile(ui->inputFileLineEdit->text().toUtf8().constData());
    writer.setOutputFile(ui->outputFileLineEdit->text().toUtf8().constData());
    writer.setProjectName(ui->projectNameLineEdit->text().toUtf8().constData());
    writer.write();

}
