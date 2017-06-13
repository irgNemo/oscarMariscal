#include "GridEditor.h"
#include "ui_GridEditor.h"
#include <QList>
#include <vector>

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
    tabla->resizeColumnsToContents();
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

void GridEditor::setStadisticsWindow(InformationAboutTableWindow *window)
{
    stadisticsWindow = window;
}

void GridEditor::renameHeaders(std::vector<std::__cxx11::string> headers)
{
    QList<QString> list;
    for (int i = 0 ; i < headers.size(); i++){
        list.append(QString::fromStdString( headers.at(i)));
    }
    ui->tableWidget->setHorizontalHeaderLabels(list);
}

void GridEditor::on_pushButton_clicked()
{
    //obtaining the contents of the grid.
    int contents[rowCount][columnCount];
    DataFormat format;
    for (int i = 0 ; i < rowCount; i++){
        for (int j = 0 ; j < columnCount; j++){
            contents[i][j] = ui->tableWidget->item(i,j)->text().toInt();
        }
    }
    /*
    format.setNumFil(rowCount);
    format.setNumCol(columnCount);
    //int **temp = contents;
    format.setFundamentalSet(temp);
    XmlFileWriter writer;
    writer.setDataFormat(format);
    writer.setFileName("test1234.csv");
    writer.write();
    */

}

void GridEditor::on_action_get_stadistics_on_column_triggered()
{
    int column =  ui->tableWidget->currentColumn();
    QList<int> list;
    for (int i = 0 ;i <ui->tableWidget->rowCount() ;i++ ){
        list.append(ui->tableWidget->item(i,column)->text().toInt());
    }
    int size = list.size();
    std::sort(list.begin(),list.end());
    int median;
    if (size%2==0){
        median = (list.at((size/2)-1)+list.at((size/2)))/2;
    }
    else{
        median = list.at((size/2)-1);
    }
    int number = list.at(0);
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=0; i<list.size(); i++){
          if (list.at(i) == number) { // count occurrences of the current number
             ++count;
          }
          else
          { // now this is a different number
                if (count > countMode)
                {
                      countMode = count; // mode is the biggest ocurrences
                      mode = number;
                }
               count = 1; // reset count for the new number
               number = list.at(i);
      }
    }
    stadisticsWindow->setLineMode(mode);
    stadisticsWindow->setLineName("Test");
    stadisticsWindow->setLineSize(size);
}

void GridEditor::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu;
    menu.addAction(ui->action_get_stadistics_on_column);
    menu.exec(QCursor::pos());
}

