#ifndef INFORMATIONABOUTTABLEWINDOW_H
#define INFORMATIONABOUTTABLEWINDOW_H

#include <QWidget>

namespace Ui {
class InformationAboutTableWindow;
}

class InformationAboutTableWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InformationAboutTableWindow(QWidget *parent = 0);
    ~InformationAboutTableWindow();

private:
    Ui::InformationAboutTableWindow *ui;
};

#endif // INFORMATIONABOUTTABLEWINDOW_H
