#include "include/viewAutenticacao.h"
#include "ui_viewAutenticacao.h"

viewAutenticacao::viewAutenticacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewAutenticacao)
{
    ui->setupUi(this);
}

viewAutenticacao::~viewAutenticacao()
{
    delete ui;
}

bool viewAutenticacao::executar(CPF &cpf) {
    this->show();
    return false;
}

void viewAutenticacao::on_Login_clicked()
{
    CPF cpf;
    Senha senha;
    cpf.setValor(ui->lineCpf->text().toStdString());
    senha.setValor(ui->lineSenha->text().toStdString());
    modelAutenticacao->autenticar(cpf, senha);

    // Parei aqui
}
