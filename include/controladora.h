#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <QMainWindow>
#include "Interfaces_Apresentacao.h"
#include "viewUsuario.h"
#include "viewAutenticacao.h"
#include "viewEventos.h"

namespace Ui {
class Controladora;
}

class Controladora : public QMainWindow
{
    Q_OBJECT

public:
    int isNotInMenu = 0;

    void executar();

    explicit Controladora(QWidget *parent = nullptr);
    ~Controladora();

    void setViewAutenticacao(IAAutenticacao *viewAutenticacao);

    void setViewUsuario(IAUsuario *viewUsuario);

    void setViewEventos(IAEventos *viewEventos);

    void setViewVendas(IAVendas *viewVendas);
private slots:

    void on_btnLogin_clicked();

    void on_btnCadastro_clicked();

    void on_btnEventos_clicked();

    void on_btnVendas_clicked();

private:
    // Interfaces de apresentacao
    IAAutenticacao* viewAutenticacao;
    IAUsuario* viewUsuario ;
    IAEventos* viewEventos;
    IAVendas* viewVendas;

    // View da controladora principal
    Ui::Controladora *ui;

    // Cpf do usuário logado
    CPF* cpfUsuarioLogado;

};

#endif // CONTROLADORA_H
