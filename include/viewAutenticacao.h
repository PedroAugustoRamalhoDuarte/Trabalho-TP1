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
    bool executar(CPF* cpf) override;

    explicit viewAutenticacao(QWidget *parent = nullptr);

    ~viewAutenticacao();

private slots:
    void on_Login_clicked();

    void on_lineCpf_editingFinished();

    void on_lineSenha_editingFinished();

private:
    Ui::viewAutenticacao *ui;
    ISAutenticacao* modelAutenticacao = new class ModelAutenticacao();
    CPF* cpfUsuarioLogado;
};

#endif // VIEWAUTENTICACAO_H
