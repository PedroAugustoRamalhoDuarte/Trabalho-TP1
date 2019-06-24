#include "../include/viewUsuario.h"
#include "ui_viewUsuario.h"

viewUsuario::viewUsuario(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::viewUsuario)
{
    ui->setupUi(this);

    // Diretorio Caso QtCreator
    QPixmap pix("../TrabalhoTP1/imagens/interrogacao.png");

    // Diretorio caso Clion
    //QPixmap pix("../imagens/interrogacao.png");

    // Código do Help para digitação dos campos
    ui->helpCPF->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpCPF->setToolTip("O CPF deve estar no formato XXX.XXX.XXX-XX no qual X são números válidos");
    ui->helpSenha->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpSenha->setToolTip("A senha deve conter no mínimo 6 caracteres e no máximo 12. Entre os caracteres deve ter pelo menos uma letra maiúscula, <br>"
                              "uma minúscula e um dígito. Não pode conter dois caracteres repetidos.");
    ui->helpCartao->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpCartao->setToolTip("O cartão deve conter um número válido sem espaço entre os números");
    ui->helpCodigo->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpCodigo->setToolTip("O Código conter os 3 digitos de segurança");
    ui->helpValidade->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpValidade->setToolTip("A data deve estar no formato MM/AA, no qual MM é o mês e AA o ano");

    //Escondendo os caracteres da senha
    ui->linesenha->setEchoMode(QLineEdit::Password);
}

void viewUsuario::executar(CPF *cpf){
    // Limpando os dados de cadastro
    viewUsuario::lineclean();
    this->cpfUsuarioLogado = cpf;
    if (cpf->getValor() == "") {
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        auto *usuario = new Usuario();
        auto *cartao = new CartaoDeCredito();
        try {
            modelUsuario->mostrarUsuario(*this->cpfUsuarioLogado, usuario, cartao);
            ui->labelSetCPF->setText(QString::fromStdString(usuario->getCpf().getValor()));
            ui->labelSetCartao->setText(QString::fromStdString(cartao->getNumero().getValor()));
            ui->labelSetCodigo->setText(QString::fromStdString(cartao->getCodigoDeSeguranca().getValor()));
            ui->labelSetValidade->setText(QString::fromStdString(cartao->getDataDeValidade().getValor()));
        } catch (...) {
            cout << "Erro ao mostrar Usuario";
        }
        delete usuario;
        delete cartao;
        ui->stackedWidget->setCurrentIndex(1);

    }
    // Mostra a view do Usuario
    this->show();
}

viewUsuario::~viewUsuario()
{
    // Encerra a conexao do banco de dados(alterar local depois)
    //delete (ModelUsuario*)(modelUsuario);
    delete ui;
}

//---------------------------------------------
// Verificação de formato
void viewUsuario::on_linecpf_editingFinished()
{
    CPF cpf;
    try {
        cpf.setValor(ui->linecpf->text().toStdString());
        ui->labelCheckCPF->setStyleSheet("color:#7d7");
        ui->labelCheckCPF->setText("✓");
    } catch (...) {
        ui->labelCheckCPF->setStyleSheet("color:#f00");
        ui->labelCheckCPF->setText("x");
    }
}

void viewUsuario::on_linesenha_editingFinished()
{
    Senha senha;
    try {
        senha.setValor(ui->linesenha->text().toStdString());
        ui->labelCheckSenha->setStyleSheet("color:#7d7");
        ui->labelCheckSenha->setText("✓");
    } catch (...) {
        ui->labelCheckSenha->setStyleSheet("color:#f00");
        ui->labelCheckSenha->setText("x");
    }
}

void viewUsuario::on_linenumero_editingFinished()
{
    NumeroDeCartaoDeCredito cartao;
    try {
        cartao.setValor(ui->linenumero->text().toStdString());
        ui->labelCheckCartao->setStyleSheet("color:#7d7");
        ui->labelCheckCartao->setText("✓");
    } catch (...) {
        ui->labelCheckCartao->setStyleSheet("color:#f00");
        ui->labelCheckCartao->setText("x");
    }

}

void viewUsuario::on_linecodigo_editingFinished()
{
    CodigoDeSeguranca codigo;
    try {
        codigo.setValor(ui->linecodigo->text().toStdString());
        ui->labelCheckCodigo->setStyleSheet("color:#7d7");
        ui->labelCheckCodigo->setText("✓");
    } catch (...) {
        ui->labelCheckCodigo->setStyleSheet("color:#f00");
        ui->labelCheckCodigo->setText("x");
    }
}

void viewUsuario::on_linedata_editingFinished()
{
    DataDeValidade data;
    try {
        data.setValor(ui->linedata->text().toStdString());
        ui->labelCheckData->setStyleSheet("color:#7d7");
        ui->labelCheckData->setText("✓");
    } catch (...) {
        ui->labelCheckData->setStyleSheet("color:#f00");
        ui->labelCheckData->setText("x");
    }
}

void viewUsuario::on_checkBox_clicked()
{
    if(!ui->checkBox->isChecked())
        ui->linesenha->setEchoMode(QLineEdit::Password);
    else
        ui->linesenha->setEchoMode(QLineEdit::Normal);


}

//------------------------------------------------------
// Botões

void viewUsuario::on_btnRegistrar_clicked()
{
    CPF cpf;
    Senha senha;
    NumeroDeCartaoDeCredito numero;
    CodigoDeSeguranca codigo;
    DataDeValidade data;
    try {
        cpf.setValor(ui->linecpf->text().toStdString());
        senha.setValor(ui->linesenha->text().toStdString());
        numero.setValor(ui->linenumero->text().toStdString());
        codigo.setValor(ui->linecodigo->text().toStdString());
        data.setValor(ui->linedata->text().toStdString());
        Usuario* usuario = new Usuario(cpf, senha);
        CartaoDeCredito* cartao = new  CartaoDeCredito(numero, codigo, data);
        modelUsuario->cadastrarUsuario(*usuario, *cartao);
        ui->msg->setText("Usuário cadastrado com sucesso! Para fazer login redirecione para página de login");
    } catch (...) {
        ui->msg->setText("Erro ao cadastrar o usuário");
    }

}

void viewUsuario::on_btnHome_clicked()
{
    this->close();
}

void viewUsuario::on_buttonDelete_clicked()
{
    try {
        if (modelUsuario->excluirUsuario(*cpfUsuarioLogado)){
            // Seta o cpf "", para dar Logout
            cpfUsuarioLogado->resetCPF();
            this->close();
            }
        else
            ui->labelMsgPerfil->setText("Erro ao excluir (O usuário possui eventos cadastrados)");
    } catch (...) {
        ui->labelMsgPerfil->setText("Erro ao excluir (Erro na base de dados)");
    }
}

void viewUsuario::on_btnHome_2_clicked()
{
    this->close();
}

void viewUsuario::setModelUsuario(ISUsuario *modelUsuario) {
    viewUsuario::modelUsuario = modelUsuario;
}

// Método para limpar os campos
void viewUsuario::lineclean(){
    ui->labelMsgPerfil->setText("");
    ui->msg->setText("");
    ui->linecpf->setText("");
    ui->linedata->setText("");
    ui->linesenha->setText("");
    ui->linecodigo->setText("");
    ui->linenumero->setText("");
    ui->labelCheckCPF->setText("");
    ui->labelCheckCartao->setText("");
    ui->labelCheckCodigo->setText("");
    ui->labelCheckData->setText("");
    ui->labelCheckSenha->setText("");
}
