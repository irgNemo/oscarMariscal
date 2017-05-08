#ifndef FILECHOOSERWINDOW_H
#define FILECHOOSERWINDOW_H
#include <QWidget>
#include <QTreeWidget>

namespace Ui {
class FileChooserWindow;
}

class FileChooserWindow : public QWidget
{
    Q_OBJECT


public:
    explicit FileChooserWindow(QWidget *parent = 0);
    ~FileChooserWindow();
    void setItemOfFileTreeToEdit(QTreeWidgetItem *item);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_save_clicked();

private:
    Ui::FileChooserWindow *ui;
    QTreeWidgetItem* item;
};

#endif // FILECHOOSERWINDOW_H
