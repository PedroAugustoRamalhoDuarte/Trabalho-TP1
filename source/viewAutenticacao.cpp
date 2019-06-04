#include "include/viewAutenticacao.h"
#include "ui_viewAutenticacao.h"

viewAutenticacao::viewAutenticacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewAutenticacao)
{
    ui->setupUi(this);
    //Escondendo caracteres da senha
    ui->lineSenha->setEchoMode(QLineEdit::Password);
    this->cpfUsuarioLogado = new CPF();
}

viewAutenticacao::~viewAutenticacao()
{
    cout << "Destrutor da porra da viewAutenticao" << endl;
    free(this->cpfUsuarioLogado);
    //delete (ModelAutenticacao*)(modelAutenticacao);
    delete ui;
}

bool viewAutenticacao::executar(CPF* cpf) {
    this->cpfUsuarioLogado = cpf;
    this->show();
    if (userLogedIn)
        return true;
    return false;
}

void viewAutenticacao::on_Login_clicked()
{
    CPF cpf;
    Senha senha;
    try {
        cpf.setValor(ui->lineCpf->text().toStdString());
        senha.setValor(ui->lineSenha->text().toStdString());
        cout << "AntesDeAutenticar" << endl;
        if (modelAutenticacao->autenticar(cpf, senha)){
            cout << "AntesDeAtribuirCPF(btnLogin)" << endl;
            *this->cpfUsuarioLogado = cpf;
            cout << "DepoisDeAtribuirCPF(btnLogin)" << endl;
            userLogedIn = true;
            //this->close();
        } else {
            cout << "Erro ao fazer login " << endl;
        }
    } catch (...) {
        cout << "Erro no formato" << endl;
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


void viewAutenticacao::on_Home_clicked()
{
    this->close();
}

void viewAutenticacao::on_pushButton_clicked()
{

}

void viewAutenticacao::on_showPassword_clicked()
{
    if(!ui->showPassword->isChecked())
        ui->lineSenha->setEchoMode(QLineEdit::Password);
    else
        ui->lineSenha->setEchoMode(QLineEdit::Normal);
}
