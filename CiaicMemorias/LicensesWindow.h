#ifndef LICENSESWINDOW_H
#define LICENSESWINDOW_H

#include <QWidget>

namespace Ui {
class LicensesWindow;
}

class LicensesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LicensesWindow(QWidget *parent = 0);
    ~LicensesWindow();

private:
    Ui::LicensesWindow *ui;
};

#endif // LICENSESWINDOW_H
