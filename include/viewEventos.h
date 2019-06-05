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
    void executar(CPF cpf);
    ~viewEventos();

    void setModelEventos(ISEventos *modelEventos) {
        viewEventos::modelEventos = modelEventos;
    }


private slots:
    void on_btnHome_clicked();

    void on_btnPesquisarReal_clicked();

    void on_btnCriarEvento_clicked();

    void on_btnCriar_clicked();

    void on_btnAdicionarApr_clicked();

    void on_btnConcluirApr_clicked();

private:
    Ui::viewEventos *ui;
    Evento eventoADD;
    list<Apresentacao> listApresentacao;
    ISEventos* modelEventos;
    CPF cpfUsuarioLogado;
};

#endif // VIEWEVENTOS_H
