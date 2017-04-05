#include "GridEditor.h"
#include "ui_GridEditor.h"

GridEditor::GridEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridEditor)
{
    ui->setupUi(this);
}

GridEditor::~GridEditor()
{
    delete ui;
}

void GridEditor::setDataFormat(DataFormat data)
{
    columnCount = data.getNumCol();
    rowCount =  data.getNumFil();
    QTableWidget *tabla =   ui->tableWidget;
    tabla->setRowCount(rowCount);
    tabla->setColumnCount(columnCount);
    int ** values = data.getFundamentalSet();
    for (int i = 0 ; i <rowCount; i++ ){
        for (int j = 0 ; j  < columnCount; j++){
            tabla->setItem(i,j, new QTableWidgetItem( QString::number( values[i][j]) ));
        }
    }
}

int GridEditor::getRowCount() const
{
    return rowCount;
}

void GridEditor::setRowCount(int value)
{
    rowCount = value;
}

int GridEditor::getColumnCount() const
{
    return columnCount;
}

void GridEditor::setColumnCount(int value)
{
    columnCount = value;
}
