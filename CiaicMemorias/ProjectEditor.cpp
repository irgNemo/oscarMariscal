#include "ProjectEditor.h"
#include "ui_ProjectEditor.h"

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
