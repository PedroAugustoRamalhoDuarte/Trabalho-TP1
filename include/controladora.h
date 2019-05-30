#ifndef CONTROLADORA_H
#define CONTROLADORA_H

#include <QMainWindow>
#include "Interfaces_Apresentacao.h"
#include "viewUsuario.h"
#include "viewAutenticacao.h"

namespace Ui {
class Controladora;
}

class Controladora : public QMainWindow
{
    Q_OBJECT

public:
    int flag = 0;

    explicit Controladora(QWidget *parent = nullptr);
    ~Controladora();

private slots:
    void on_pushButton_clicked();

    void on_btnLogin_clicked();

    void on_btnCadastro_clicked();

    void on_btnEventos_clicked();

private:
    // Interfaces de apresentacao
    IAAutenticacao* viewAutenticacao = new class viewAutenticacao();
    IAUsuario* viewUsuario = new class viewUsuario();
    IAEventos* viewEventos;
    IAVendas* viewVendas;

    // View da controladora principal
    Ui::Controladora *ui;

    // Variaveis de usuario
    CPF* cpfUsuarioLogado;
    bool isUsuarioLogado;

};

#endif // CONTROLADORA_H
