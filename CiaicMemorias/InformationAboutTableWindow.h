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
    void setLineSize(int size);
    void setLineName(QString name);
    void setLineMode(int mode);

private:
    Ui::InformationAboutTableWindow *ui;
};

#endif // INFORMATIONABOUTTABLEWINDOW_H
