#ifndef FILECHOOSERWINDOW_H
#define FILECHOOSERWINDOW_H

#include <QWidget>

namespace Ui {
class FileChooserWindow;
}

class FileChooserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FileChooserWindow(QWidget *parent = 0);
    ~FileChooserWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FileChooserWindow *ui;
};

#endif // FILECHOOSERWINDOW_H
