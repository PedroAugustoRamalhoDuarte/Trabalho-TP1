#include "include/viewVendas.h"
#include "ui_viewVendas.h"


viewVendas::viewVendas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewVendas)
{
    ui->setupUi(this);
}

viewVendas::~viewVendas()
{
    delete ui;
}

void viewVendas::executar(CPF cpf) {
    this->show();
}


void viewVendas::setModelVendas(ISVendas *modelVendas) {
    viewVendas::modelVendas = modelVendas;
}

