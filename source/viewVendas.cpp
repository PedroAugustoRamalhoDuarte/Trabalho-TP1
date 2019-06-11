#include "include/viewVendas.h"
#include "ui_viewVendas.h"


viewVendas::viewVendas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewVendas)
{
    ui->setupUi(this);
}

viewVendas::~viewVendas()
{
    delete ui;
}

void viewVendas::executar(CPF cpf) {
    // Redireciona para o menu de Vendas
    this->cpfUsuarioLogado = cpf;
    ui->stackedWidget->setCurrentIndex(0);
    this->show();
}


void viewVendas::setModelVendas(ISVendas *modelVendas) {
    viewVendas::modelVendas = modelVendas;
}


void viewVendas::on_btnComprarIngresso_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void viewVendas::on_btnVerIngressosVendidos_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void viewVendas::on_btnVoltar2_clicked()
{
    // Redireciona para o menu de Vendas
    ui->stackedWidget->setCurrentIndex(0);
}

void viewVendas::on_btnVoltar_clicked()
{
    // Redireciona para o menu de Vendas
    ui->stackedWidget->setCurrentIndex(0);
}

void viewVendas::on_btnHome_clicked()
{
    this->close();
}

void viewVendas::on_btnComprar_clicked()
{
    CodigoDeApresentacao codigoDeApresentacao;
    int quantidade;
    try {
        codigoDeApresentacao.setValor(ui->lineCodigoApresentacao->text().toStdString());
        quantidade = ui->lineQuantidade->text().toInt();
        modelVendas->adquirirIngresso(cpfUsuarioLogado,codigoDeApresentacao, quantidade);
        ui->labelCompra->setText("Comprado com sucesso!");
    } catch (...) {
        ui->labelCompra->setText("Erro ao comprar");

    }
}
