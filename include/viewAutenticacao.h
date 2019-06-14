#ifndef VIEWAUTENTICACAO_H
#define VIEWAUTENTICACAO_H

#include <QMainWindow>
#include "Interfaces_Apresentacao.h"
#include "Interfaces_Servicos.h"
#include "Model.h"

namespace Ui {
class viewAutenticacao;
}

class viewAutenticacao : public QMainWindow, public IAAutenticacao
{
    Q_OBJECT

public:
    void executar(CPF *cpf) override;

    explicit viewAutenticacao(QWidget *parent = nullptr);

    ~viewAutenticacao();

    void setModelAutenticacao(ISAutenticacao *modelAutenticacao) override{
        viewAutenticacao::modelAutenticacao = modelAutenticacao;
    }

private slots:
    void on_Login_clicked();

    void on_lineCpf_editingFinished();

    void on_lineSenha_editingFinished();

    void on_Home_clicked();

    void on_showPassword_clicked();

private:
    Ui::viewAutenticacao *ui;

    // Ligação da camada de serviço
    ISAutenticacao* modelAutenticacao;

    // CPF recebido pela controladora
    CPF* cpfUsuarioLogado;

    // Limpa a view
    void lineclean();
};

#endif // VIEWAUTENTICACAO_H
