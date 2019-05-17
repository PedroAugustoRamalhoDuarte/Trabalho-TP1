#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QToolTip>
#include <QPixmap>
#include "include/Model.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
            void on_pushButton_clicked();

            void on_pushButton_3_clicked();

            void on_buttonDelete_clicked();

            void on_linecpf_editingFinished();

            void on_linesenha_editingFinished();

            void on_linenumero_editingFinished();

            void on_linecodigo_editingFinished();

            void on_linedata_editingFinished();

private:
    Ui::MainWindow *ui;
    ISUsuario* modelUsuario;
};

#endif // MAINWINDOW_H
