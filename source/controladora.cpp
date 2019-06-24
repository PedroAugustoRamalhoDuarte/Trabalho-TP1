#include "../include/controladora.h"
#include "ui_controladora.h"

Controladora::Controladora(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Controladora) {
    ui->setupUi(this);

    // Inicializando variaveis do usuario
    this->isNotInMenu = 0;
    this->cpfUsuarioLogado = new CPF();
}

// Módulo Autenticação
void Controladora::on_btnLogin_clicked() {
    if (ui->btnLogin->text() == "Logout") {
        // Logout
        delete cpfUsuarioLogado;
        cpfUsuarioLogado = new CPF();
        this->executar();
    } else {
        // Login
        viewAutenticacao->executar(this->cpfUsuarioLogado);
        this->isNotInMenu = 1;
        this->hide();
    }
}

// Módulo de Usuários
void Controladora::on_btnCadastro_clicked() {
    viewUsuario->executar(this->cpfUsuarioLogado);
    this->isNotInMenu = 1;
    this->hide();
}

// Módulo de Eventos
void Controladora::on_btnEventos_clicked() {
    viewEventos->executar(*this->cpfUsuarioLogado);
    this->isNotInMenu = 1;
    this->hide();

}

// Módulo de Vendas
void Controladora::on_btnVendas_clicked() {
    viewVendas->executar(*this->cpfUsuarioLogado);
    this->isNotInMenu = 1;
    this->hide();
}

void Controladora::executar() {
    // Se o usuário estiver logado
    if (cpfUsuarioLogado->getValor() != "") {
        ui->btnCadastro->setText("Perfil");
        ui->btnLogin->setText("Logout");
        ui->btnVendas->setVisible(true);
    }
        // Se o usuário não estiver logado
    else {
        ui->btnCadastro->setText("Cadastre-se");
        ui->btnLogin->setText("Login");
        ui->btnVendas->setVisible(false);
    }
    this->show();
}

Controladora::~Controladora() {
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


