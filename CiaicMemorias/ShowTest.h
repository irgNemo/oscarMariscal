#ifndef SHOWTEST_H
#define SHOWTEST_H

#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class ShowTest;
}

class ShowTest : public QWidget
{
    Q_OBJECT
    QTreeWidgetItem *project;
    QTreeWidgetItem *testingSets;
    QTreeWidgetItem *output;

public:
    explicit ShowTest(QWidget *parent = 0);
    ~ShowTest();
    void setProject(QTreeWidgetItem *value);
    void fillComboBoxes();

private slots:
    void on_pushButton_pressed();

private:
    Ui::ShowTest *ui;
};

#endif // SHOWTEST_H
