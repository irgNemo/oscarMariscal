#ifndef VIEWTESTRESULTS_H
#define VIEWTESTRESULTS_H

#include <QWidget>

namespace Ui {
class viewTestResults;
}

class viewTestResults : public QWidget
{
    Q_OBJECT

public:
    explicit viewTestResults(QWidget *parent = 0);
    ~viewTestResults();

private:
    Ui::viewTestResults *ui;
};

#endif // VIEWTESTRESULTS_H
