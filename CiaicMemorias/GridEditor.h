#ifndef GRIDEDITOR_H
#define GRIDEDITOR_H

#include <QWidget>
#include <QDebug>
#include <QMenu>
#include "DataFormat.h"
#include "XmlFileWriter.h"
#include "InformationAboutTableWindow.h"
#include <vector>


namespace Ui {
class GridEditor;
}

class GridEditor : public QWidget
{
    Q_OBJECT

public:

    explicit GridEditor(QWidget *parent = 0);
    ~GridEditor();
    void setDataFormat(DataFormat data);
    int getRowCount() const;
    void setRowCount(int value);
    int getColumnCount() const;
    void setColumnCount(int value);
    void setStadisticsWindow(InformationAboutTableWindow* window);
    void renameHeaders(std::vector<std::string> headers);

private slots:
    void on_pushButton_clicked();
    void on_action_get_stadistics_on_column_triggered();
    void on_tableWidget_customContextMenuRequested(const QPoint &pos);

private:
    int rowCount;
    int columnCount;
    Ui::GridEditor *ui;
    InformationAboutTableWindow * stadisticsWindow;
};

#endif // GRIDEDITOR_H
