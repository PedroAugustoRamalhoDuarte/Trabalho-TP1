//
// Created by pedro on 15/05/19.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolTip>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    modelUsuario = new ModelServicoUsuario();
    ui->setupUi(this);

    QPixmap pix("../TrabalhoTP1/imagens/interrogacao.png");
    ui->helpCPF->setPixmap(pix.scaled(40,40,Qt::KeepAspectRatio));
    ui->helpCPF->setToolTip("O CPF deve estar no formato <br>XXX.XXX.XXX-XX no qual X são números válidos");
    ui->helpSenha->setPixmap(pix.scaled(40,40,Qt::KeepAspectRatio));
    ui->helpSenha->setToolTip("cpf");
}

MainWindow::~MainWindow()
{
    delete (ModelServicoUsuario*)(modelUsuario);
    delete ui;
}

void MainWindow::on_pushButton_clicked()
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
        ui->msg->setText("Usuário inserido com sucesso!");
    } catch (std::exception &e) {
        ui->msg->setText("Errou maluco");
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    CPF cpf;
    Usuario usuario;
    CartaoDeCredito cartao;
    try {
        cpf.setValor(ui->linecpf->text().toStdString());
        modelUsuario->mostrarUsuario(cpf, &usuario, &cartao);
    } catch (...) {
        cout << "Erro ao mostrar Usuario" << endl;
    }

}

void MainWindow::on_buttonDelete_clicked()
{
    CPF cpf;
    try {
        cpf.setValor(ui->linecpf->text().toStdString());
        modelUsuario->excluirUsuario(cpf);
    } catch (...) {
        cout << "Erro ao excluir Usuario" << endl;
    }
}

void MainWindow::on_linecpf_editingFinished()
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

void MainWindow::on_linesenha_editingFinished()
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

void MainWindow::on_linenumero_editingFinished()
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

void MainWindow::on_linecodigo_editingFinished()
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

void MainWindow::on_linedata_editingFinished()
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

