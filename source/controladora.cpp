#include "../include/controladora.h"
#include "ui_controladora.h"

Controladora::Controladora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controladora)
{
    ui->setupUi(this);


    // Inicializando variaveis do usuario
    this->isUsuarioLogado = false;
    this->cpfUsuarioLogado = new CPF();


}

Controladora::~Controladora()
{
    delete ui;
}



void Controladora::on_btnLogin_clicked()
{
    viewAutenticacao->executar(this->cpfUsuarioLogado);
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

void Controladora::on_btnEventos_clicked()
{
    // Incializando label Usuario
    ui->label->setText(QString::fromStdString(this->cpfUsuarioLogado->getValor()));
}
