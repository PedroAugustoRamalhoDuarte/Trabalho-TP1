#include "include/viewAutenticacao.h"
#include "ui_viewAutenticacao.h"

viewAutenticacao::viewAutenticacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewAutenticacao)
{
    ui->setupUi(this);
    this->cpfUsuarioLogado = new CPF();
}

viewAutenticacao::~viewAutenticacao()
{
    delete ui;
}

bool viewAutenticacao::executar(CPF* cpf) {
    this->cpfUsuarioLogado = cpf;
    this->show();
    return false;
}

void viewAutenticacao::on_Login_clicked()
{
    CPF cpf;
    Senha senha;
    cpf.setValor(ui->lineCpf->text().toStdString());
    senha.setValor(ui->lineSenha->text().toStdString());
    if (modelAutenticacao->autenticar(cpf, senha)){
        *this->cpfUsuarioLogado = cpf;
        this->close();
    } else {
        cout << "Erro ao fazer login " << endl;
    }
}

void viewAutenticacao::on_lineCpf_editingFinished()
{
    CPF cpf;
    try {
        cpf.setValor(ui->lineCpf->text().toStdString());
        ui->checkCPF->setStyleSheet("color:#7d7");
        ui->checkCPF->setText("✓");
    } catch (...) {
        ui->checkCPF->setStyleSheet("color:#f00");
        ui->checkCPF->setText("x");
    }

}

void viewAutenticacao::on_lineSenha_editingFinished()
{
    Senha senha;
    try {
        senha.setValor(ui->lineSenha->text().toStdString());
        ui->checkSenha->setStyleSheet("color:#7d7");
        ui->checkSenha->setText("✓");
    } catch (...) {
        ui->checkSenha->setStyleSheet("color:#f00");
        ui->checkSenha->setText("x");
    }
}
