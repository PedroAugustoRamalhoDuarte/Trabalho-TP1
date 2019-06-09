#ifndef VIEWVENDAS_H
#define VIEWVENDAS_H

#include <QMainWindow>
#include "Model.h"
#include "Interfaces_Apresentacao.h"
#include "../../Programas/Qt/5.12.3/gcc_64/include/QtCore/QArgument"

namespace Ui {
class viewVendas;
}

class viewVendas : public QMainWindow, public IAVendas
{
    Q_OBJECT

public:
    explicit viewVendas(QWidget *parent = nullptr);

    void executar(CPF cpf) override;

    void setModelVendas(ISVendas *modelVendas);

    ~viewVendas();

private:
    // Interface de serviço
    ISVendas* modelVendas;

    Ui::viewVendas *ui;
};

#endif // VIEWVENDAS_H
