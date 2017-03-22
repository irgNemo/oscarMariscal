#ifndef PROJECTEDITOR_H
#define PROJECTEDITOR_H

#include <QWidget>

namespace Ui {
class ProjectEditor;
}

class ProjectEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectEditor(QWidget *parent = 0);
    ~ProjectEditor();
    void on_saveButton_clicked();
    void setLineEdits(QString projectName, QString filepathInput, QString filepatOutput);
private:
    Ui::ProjectEditor *ui;
};

#endif // PROJECTEDITOR_H
