#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include <QString>
#include "LicensesWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void cargarVentana(QWidget *widget);
    void on_actionOpen_project_triggered();
    void on_treeWidget_doubleClicked(const QModelIndex &index);
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
    void addTrainingSet();
    void addTestingSet();
    void saveProject();


    void on_actionlicenses_triggered();

    void on_actionNew_project_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
