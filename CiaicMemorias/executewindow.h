#ifndef EXECUTEWINDOW_H
#define EXECUTEWINDOW_H

#include <QWidget>
#include "qtreewidget.h"

namespace Ui {
class ExecuteWindow;
}

class ExecuteWindow : public QWidget
{
    Q_OBJECT
    QTreeWidgetItem *project;
    QTreeWidgetItem *testingSets;
    QTreeWidgetItem *trainingSets;

public:
    explicit ExecuteWindow(QWidget *parent = 0);
    void applyLearnMatrix();
    ~ExecuteWindow();
    void setProject(QTreeWidgetItem *value);
    void fillComboBoxes();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ExecuteWindow *ui;
};

#endif // EXECUTEWINDOW_H
