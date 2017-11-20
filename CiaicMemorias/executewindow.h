#ifndef EXECUTEWINDOW_H
#define EXECUTEWINDOW_H

#include <QWidget>
#include "qtreewidget.h"
#include "LearningAlgorithm.h"
#include "QGroupBox"


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
    void doTesting();
    //Used for obtaining the class of patterns like 0,1,0
    int getClassNumber(int* pattern, int size);


private slots:
    void on_buttonBox_accepted();

    void on_radioNormal_toggled(bool checked);

    void on_buttonBoxCross_accepted();

private:
    void toggleUserInterfaceAlgorithms();
    bool equalPatterns(int * patternOne, int * patternTwo ,int xSize);
    QGroupBox groupForRadio;
    Ui::ExecuteWindow *ui;
    LearningAlgorithm* algorithm;
};

#endif // EXECUTEWINDOW_H
