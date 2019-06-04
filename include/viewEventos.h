#ifndef VIEWEVENTOS_H
#define VIEWEVENTOS_H

#include <QMainWindow>
#include "Interfaces_Apresentacao.h"
#include "Interfaces_Servicos.h"

namespace Ui {
class viewEventos;
}

class viewEventos : public QMainWindow, public IAEventos
{
    Q_OBJECT

public:
    explicit viewEventos(QWidget *parent = nullptr);
    void executar();
    ~viewEventos();

    void setModelEventos(ISEventos *modelEventos) {
        viewEventos::modelEventos = modelEventos;
    }


private slots:
    void on_btnHome_clicked();

private:
    Ui::viewEventos *ui;
    ISEventos* modelEventos;
};

#endif // VIEWEVENTOS_H
