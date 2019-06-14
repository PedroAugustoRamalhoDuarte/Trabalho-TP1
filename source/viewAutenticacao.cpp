#include "include/viewAutenticacao.h"
#include "ui_viewAutenticacao.h"

viewAutenticacao::viewAutenticacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewAutenticacao)
{
    ui->setupUi(this);
    //Escondendo caracteres da senha
    ui->lineSenha->setEchoMode(QLineEdit::Password);

    // Incializando variaveis para suporte na autenticação
    this->cpfUsuarioLogado = new CPF();
}

viewAutenticacao::~viewAutenticacao()
{
    cout << "Destrutor da porra da viewAutenticao" << endl;
    free(this->cpfUsuarioLogado);
    //delete (ModelAutenticacao*)(modelAutenticacao);
    delete ui;
}

void viewAutenticacao::executar(CPF* cpf) {
    viewAutenticacao::lineclean();
    this->cpfUsuarioLogado = cpf;
    this->show();
}

void viewAutenticacao::lineclean(){
    ui->lineCpf->setText("");
    ui->lineSenha->setText("");
    ui->labelErro->setText("");
}

// Botão Login
void viewAutenticacao::on_Login_clicked()
{
    CPF cpf;
    Senha senha;
    try {
        cpf.setValor(ui->lineCpf->text().toStdString());
        senha.setValor(ui->lineSenha->text().toStdString());
        if (modelAutenticacao->autenticar(cpf, senha)){
            *this->cpfUsuarioLogado = cpf;
            this->close();
        } else {
            ui->labelErro->setText("Cpf e Senha não coincidem");
        }
    } catch (...) {
        ui->labelErro->setText("Erro no formato do CPF ou Senha");
    }
}

// Redirecionar para página principal
void viewAutenticacao::on_Home_clicked()
{
    this->close();
}

// Lógica para botão mostrar senha
void viewAutenticacao::on_showPassword_clicked()
{
    if(!ui->showPassword->isChecked())
        ui->lineSenha->setEchoMode(QLineEdit::Password);
    else
        ui->lineSenha->setEchoMode(QLineEdit::Normal);
}

// Métodos de verificação de formato
void viewAutenticacao::on_lineCpf_editingFinished()
{
    CPF cpf;
    try {
        cpf.setValor(ui->lineCpf->text().toStdString());
    } catch (...) {

    }

}


void viewAutenticacao::on_lineSenha_editingFinished()
{
    Senha senha;
    try {
        senha.setValor(ui->lineSenha->text().toStdString());
    } catch (...) {

    }
}
