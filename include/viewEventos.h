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

    void aprlineclean();

    void eventolineclean();

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

    void on_clineCodigo_editingFinished();

    void on_clineNome_editingFinished();

    void on_clineCidade_editingFinished();

    void on_clineEstado_editingFinished();

    void on_clineClasse_editingFinished();

    void on_clineFaixa_editingFinished();

    void on_alineData_editingFinished();

    void on_alineHorario_editingFinished();

    void on_alineCodigo_editingFinished();

    void on_alinePreco_editingFinished();

    void on_alineSala_editingFinished();

    void on_alineDisponibilidade_editingFinished();

    void on_tableEventos_cellClicked(int row, int column);

    void on_btnPesquisar_clicked();

    void on_buttonHome_clicked();

    void on_pushButton_clicked();

    void on_btnMenu3_clicked();

    void on_btnHome_2_clicked();

private:
    Ui::viewEventos *ui;
    Evento eventoADD;
    list<Apresentacao> listApresentacao;
    ISEventos* modelEventos;
    CPF cpfUsuarioLogado;
};

#endif // VIEWEVENTOS_H
