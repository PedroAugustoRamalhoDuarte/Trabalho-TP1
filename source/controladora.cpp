#include "../include/controladora.h"
#include "ui_controladora.h"

Controladora::Controladora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controladora)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);

    // Inicializando variaveis do usuario
    this->isUsuarioLogado = false;
    this->flag = 0;
    this->cpfUsuarioLogado = new CPF();


}

Controladora::~Controladora()
{
    delete ui;
}


void Controladora::on_btnLogin_clicked()
{
    if (viewAutenticacao->executar(this->cpfUsuarioLogado))
        this->isUsuarioLogado = true;
    else
        this->isUsuarioLogado = false;
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

void Controladora::on_btnEventos_clicked()
{
    // Incializando label Usuario
    ui->label->setText(QString::fromStdString(this->cpfUsuarioLogado->getValor()));
    viewEventos->executar();
    this->flag = 1;
    this->hide();

}

void Controladora::executar()
{
    cout << "PASSOU EXECUTAR CONTROLADORA" << endl;
    //cout << isUsuarioLogado << endl;
    /*if(!isUsuarioLogado){
        if (ui->stackedWidget->is)
        ui->stackedWidget->setCurrentIndex(0);
    }
    else {
        ui->stackedWidget->setCurrentIndex(1);
    }*/
    this->show();
    cout << "PASSOU SHOW EXECUTAR " << endl;
}

void Controladora::on_pushButton_clicked()
{

}

void Controladora::setViewAutenticacao(IAAutenticacao *viewAutenticacao) {
    Controladora::viewAutenticacao = viewAutenticacao;
}

void Controladora::setViewUsuario(IAUsuario *viewUsuario) {
    Controladora::viewUsuario = viewUsuario;
}

void Controladora::setViewEventos(IAEventos *viewEventos) {
    Controladora::viewEventos = viewEventos;
}

void Controladora::setViewVendas(IAVendas *viewVendas) {
    Controladora::viewVendas = viewVendas;
}

