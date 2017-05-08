#ifndef PROJECTEDITOR_H
#define PROJECTEDITOR_H

#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class ProjectEditor;
}

class ProjectEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectEditor(QWidget *parent = 0);
    ~ProjectEditor();
    void setLineEdits(QString projectName, QString filepathInput, QString filepatOutput);
    void setTreeWidget(QTreeWidget* tree);
private slots:
    void on_saveButton_clicked();

private:
    Ui::ProjectEditor *ui;
    QTreeWidget* tree;
};

#endif // PROJECTEDITOR_H
