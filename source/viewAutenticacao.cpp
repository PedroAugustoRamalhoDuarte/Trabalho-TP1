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
    this->userLogedIn = false;
}

viewAutenticacao::~viewAutenticacao()
{
    cout << "Destrutor da porra da viewAutenticao" << endl;
    free(this->cpfUsuarioLogado);
    //delete (ModelAutenticacao*)(modelAutenticacao);
    delete ui;
}

bool viewAutenticacao::executar(CPF* cpf) {
    viewAutenticacao::lineclean();
    this->cpfUsuarioLogado = cpf;
    this->show();
    if (userLogedIn)
        return true;
    return false;
}

void viewAutenticacao::lineclean(){
    ui->lineCpf->setText("");
    ui->lineSenha->setText("");
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
            this->close();

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

// Redirecionar para página principal
void viewAutenticacao::on_Home_clicked()
{
    this->close();
}


void viewAutenticacao::on_showPassword_clicked()
{
    if(!ui->showPassword->isChecked())
        ui->lineSenha->setEchoMode(QLineEdit::Password);
    else
        ui->lineSenha->setEchoMode(QLineEdit::Normal);
}
