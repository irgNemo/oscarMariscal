#ifndef VENTANAEJECUTAR_H
#define VENTANAEJECUTAR_H

#include <QWidget>

namespace Ui {
class VentanaEjecutar;
}

class VentanaEjecutar : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaEjecutar(QWidget *parent = 0);
    ~VentanaEjecutar();

private:
    Ui::VentanaEjecutar *ui;
};

#endif // VENTANAEJECUTAR_H
