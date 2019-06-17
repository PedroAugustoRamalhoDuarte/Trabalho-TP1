#ifndef VIEWVENDAS_H
#define VIEWVENDAS_H

#include <QMainWindow>
#include "Model.h"
#include "Interfaces_Apresentacao.h"
//#include "../../Programas/Qt/5.12.3/gcc_64/include/QtCore/QArgument"

namespace Ui {
class viewVendas;
}

class viewVendas : public QMainWindow, public IAVendas
{
    Q_OBJECT

public:
    explicit viewVendas(QWidget *parent = nullptr);

    void executar(CPF cpf) override;

    void setModelVendas(ISVendas *modelVendas) override;

    ~viewVendas();

private slots:
    void on_btnComprarIngresso_clicked();

    void on_btnVerIngressosVendidos_clicked();

    void on_btnVoltar2_clicked();

    void on_btnVoltar_clicked();

    void on_btnHome_clicked();

    void on_btnComprar_clicked();

    void on_comboBoxEve_currentIndexChanged(const QString &arg1);

    void on_tableQtdVendida_cellClicked(int row, int column);

    void on_pushButton_clicked();

private:
    Ui::viewVendas *ui;

    // Interface de serviço
    ISVendas* modelVendas;

    // Atributo cpf usuario logado passado pela controladora
    CPF cpfUsuarioLogado;

};

#endif // VIEWVENDAS_H
