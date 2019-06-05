#include "include/viewEventos.h"
#include "ui_viewEventos.h"

viewEventos::viewEventos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewEventos)
{
    ui->setupUi(this);
}

viewEventos::~viewEventos()
{
    delete ui;
}

void viewEventos::executar(CPF cpf) {
    if (cpf.getValor() != "") {
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        ui->stackedWidget->setCurrentIndex(1);
    }
    this->show();

}

void viewEventos::on_btnHome_clicked()
{
    this->close();
}
