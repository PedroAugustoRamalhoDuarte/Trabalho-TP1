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
    // Teste


}

// Módulo Autenticação
void Controladora::on_btnLogin_clicked()
{
    if (viewAutenticacao->executar(this->cpfUsuarioLogado))
        this->isUsuarioLogado = true;
    else
        this->isUsuarioLogado = false;
    this->flag = 1;
    this->hide();

}

// Módulo de Usuários
void Controladora::on_btnCadastro_clicked()
{
    viewUsuario->executar(*this->cpfUsuarioLogado);
    this->flag = 1;
    this->hide();
}

// Módulo de Eventos
void Controladora::on_btnEventos_clicked()
{
    viewEventos->executar();
    this->flag = 1;
    this->hide();

}

void Controladora::executar()
{
    cout << "PASSOU EXECUTAR CONTROLADORA" << endl;
    //cout << isUsuarioLogado << endl;
    // Se o usuário estiver logado
    if(cpfUsuarioLogado->getValor() != ""){
        ui->btnCadastro->setText("Perfil");
        ui->btnLogin->setVisible(false);
    }
    // Se o usuário não estiver logado
    else {
        ui->btnCadastro->setText("Cadastre-se");
        ui->btnLogin->setVisible(true);
    }
    this->show();
    cout << "PASSOU SHOW EXECUTAR " << endl;
}

Controladora::~Controladora()
{
    delete ui;
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

