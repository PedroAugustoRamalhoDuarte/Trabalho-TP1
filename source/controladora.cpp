#include "../include/controladora.h"
#include "ui_controladora.h"

Controladora::Controladora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controladora)
{
    ui->setupUi(this);

    // Inicializando variaveis do usuario
    this->isUsuarioLogado = false;
}

Controladora::~Controladora()
{
    delete ui;
}



void Controladora::on_btnLogin_clicked()
{
    viewAutenticacao->executar(*this->cpfUsuarioLogado);
    this->flag = 1;
    this->hide();

}

void Controladora::on_btnCadastro_clicked()
{
    CPF cpf;
    viewUsuario->executar(cpf);
    this->flag = 1;
    this->hide();
}

void Controladora::on_pushButton_clicked()
{

}
