#include "controladora.h"
#include "ui_controladora.h"

Controladora::Controladora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controladora)
{
    ui->setupUi(this);
}

Controladora::~Controladora()
{
    delete ui;
}

void Controladora::on_pushButton_clicked()
{
    CPF cpf;
    viewUsuario->executar(cpf);
    this->close();
}
