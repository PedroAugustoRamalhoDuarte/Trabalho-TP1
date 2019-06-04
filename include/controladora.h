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
    int flag = 0;

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

private:
    // Interfaces de apresentacao
    IAAutenticacao* viewAutenticacao;
    IAUsuario* viewUsuario ;
    IAEventos* viewEventos;
    IAVendas* viewVendas;

    // View da controladora principal
    Ui::Controladora *ui;

    // Variaveis de usuario
    CPF* cpfUsuarioLogado;
    bool isUsuarioLogado;

};

#endif // CONTROLADORA_H
