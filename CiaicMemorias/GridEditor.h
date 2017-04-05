#ifndef GRIDEDITOR_H
#define GRIDEDITOR_H

#include <QWidget>
#include "DataFormat.h"


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

private:
    int rowCount;
    int columnCount;
    Ui::GridEditor *ui;
};

#endif // GRIDEDITOR_H
