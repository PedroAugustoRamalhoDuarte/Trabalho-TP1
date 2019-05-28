#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <QMainWindow>
#include "include/Interfaces_Apresentacao.h"
#include "mainwindow.h"

namespace Ui {
class Controladora;
}

class Controladora : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controladora(QWidget *parent = nullptr);
    ~Controladora();

private slots:
    void on_pushButton_clicked();

private:
    IAAutenticacao* viewAutenticacao;
    IAUsuario* viewUsuario = new MainWindow();
    IAEventos* viewEventos;
    IAVendas* viewVendas;

    Ui::Controladora *ui;
};

#endif // CONTROLADORA_H
