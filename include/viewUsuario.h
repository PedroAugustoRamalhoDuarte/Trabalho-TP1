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

    void executar(CPF &cpf);

    ~viewUsuario();

    void setModelUsuario(ISUsuario *modelUsuario);

private slots:
            void on_pushButton_clicked();

            void on_pushButton_3_clicked();

            void on_buttonDelete_clicked();

            void on_linecpf_editingFinished();

            void on_linesenha_editingFinished();

            void on_linenumero_editingFinished();

            void on_linecodigo_editingFinished();

            void on_linedata_editingFinished();

            void on_pushButton_2_clicked();

private:
    Ui::viewUsuario *ui;
    ISUsuario* modelUsuario;
};

#endif // MAINWINDOW_H
