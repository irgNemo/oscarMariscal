#include "ProjectEditor.h"
#include "ui_ProjectEditor.h"
#include "XmlFileWriter.h"
#include <QTreeWidget>
#include <QDebug>

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
}

void ProjectEditor::setTreeWidget(QTreeWidget *tree)
{
    this->tree = tree;
}



void ProjectEditor::on_saveButton_clicked()
{
    qDebug() << "On othe save button slot";
    QTreeWidgetItem* projectName = new QTreeWidgetItem();
    projectName->setText(0,"ProjectName");
    projectName->setText(1,ui->projectNameLineEdit->text());
    QTreeWidgetItem* input = new QTreeWidgetItem();
    input->setText(0,"input");
    //input->addChild(topTraining);

    QTreeWidgetItem* output = new QTreeWidgetItem();
    output ->setText(0,"output");

    projectName->addChild(input);
    projectName->addChild(output);
    tree->addTopLevelItem(projectName);

}
