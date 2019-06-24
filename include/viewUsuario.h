#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QToolTip>
#include <QPixmap>
#include "Model.h"
#include "Interfaces_Apresentacao.h"
namespace Ui {
    class viewUsuario;
}

class viewUsuario : public QMainWindow, public IAUsuario
{
    Q_OBJECT

public:
    explicit viewUsuario(QWidget *paren0t = nullptr);

    void executar(CPF *cpf);

    void lineclean();

    ~viewUsuario();

    void setModelUsuario(ISUsuario *modelUsuario);

private slots:
            // Verificar Formato
            void on_linecpf_editingFinished();

            void on_linesenha_editingFinished();

            void on_linenumero_editingFinished();

            void on_linecodigo_editingFinished();

            void on_linedata_editingFinished();

            // Mostrar senha
            void on_checkBox_clicked();

            // Botoões
            void on_buttonDelete_clicked();

            void on_btnRegistrar_clicked();

            void on_btnHome_clicked();

            void on_btnHome_2_clicked();

private:

    Ui::viewUsuario *ui;

    // Interface de serviço
    ISUsuario* modelUsuario;

    // Cpf usuário logado passado pela controladora
    CPF* cpfUsuarioLogado;
};

#endif // MAINWINDOW_H
