#include "include/viewVendas.h"
#include "ui_viewVendas.h"


viewVendas::viewVendas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewVendas)
{
    ui->setupUi(this);

    // Setando as tabelas para não edição
    ui->tableCpfQte->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableQtdVendida->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->labelCompra->setText("");
}

viewVendas::~viewVendas()
{
    delete ui;
}

void viewVendas::executar(CPF cpf) {
    list<CodigoDeApresentacao> listCodigoApr;
    list<CodigoDeEvento> listCodigoEve;
    // Redireciona para o menu de Vendas
    this->cpfUsuarioLogado = cpf;
    ui->stackedWidget->setCurrentIndex(0);
    try {
        //Clean
        ui->comboBoxApr->clear();
        ui->comboBoxEve->clear();

        modelVendas->listarApresentacao(listCodigoApr);
        ui->comboBoxApr->addItem("");
        for (auto codigo : listCodigoApr){
            ui->comboBoxApr->addItem(QString::fromStdString(codigo.getValor()));
        }
        modelVendas->listarEventos(listCodigoEve, cpfUsuarioLogado);
        ui->comboBoxEve->addItem("");
        for (auto codigo : listCodigoEve){
            ui->comboBoxEve->addItem(QString::fromStdString(codigo.getValor()));
        }
    } catch (...) {
        cout << "Sem Eventos" << endl;
    }

    this->show();
}


void viewVendas::setModelVendas(ISVendas *modelVendas) {
    viewVendas::modelVendas = modelVendas;
}


void viewVendas::on_btnComprarIngresso_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineQuantidade->setText("");
}

void viewVendas::on_btnVerIngressosVendidos_clicked()
{
    ui->tableQtdVendida->clearContents();
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
        codigoDeApresentacao.setValor(ui->comboBoxApr->currentText().toStdString());
        quantidade = ui->lineQuantidade->text().toInt();
        if (modelVendas->adquirirIngresso(cpfUsuarioLogado,codigoDeApresentacao, quantidade))
            ui->labelCompra->setText("Comprado com sucesso!");
        else
            ui->labelCompra->setText("Quantidade solicitada maior que a quantidade disponível!");
    } catch (...) {
        ui->labelCompra->setText("Erro ao comprar");

    }
}

void viewVendas::on_comboBoxEve_currentIndexChanged(const QString &arg1)
{
    list<pair<CodigoDeApresentacao, int>> tabelaQtdIngressos;
    try {
        CodigoDeEvento codigo;
        // Critério de parada
        if (arg1 == "") return;
        codigo.setValor(arg1.toStdString());
        modelVendas->vendasDoEvento(codigo, tabelaQtdIngressos);
        cout << tabelaQtdIngressos.size();
        ui->tableQtdVendida->clearContents();
        ui->tableQtdVendida->setRowCount((tabelaQtdIngressos).size());
        int i = 0;
        for(auto reg : tabelaQtdIngressos) {
            ui->tableQtdVendida->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(reg.first.getValor())));
            ui->tableQtdVendida->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(to_string(reg.second))));
            ui->tableQtdVendida->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(" + ")));
            i++;
        }
    } catch (...) {
        cout << "ERRO ComboBox Eventos" << endl;
    }
}

void viewVendas::on_tableQtdVendida_cellClicked(int row, int column)
{
    const int INFORMACAO = 2;
    CodigoDeApresentacao codigo;
    list<pair<CPF, int>> listRegistro;
    if (column == INFORMACAO){
        try {
            codigo.setValor(ui->tableQtdVendida->item(row, 0)->text().toStdString());
            modelVendas->vendasPorCpf(codigo, listRegistro);
            ui->tableCpfQte->clearContents();
            ui->tableCpfQte->setRowCount((listRegistro).size());
            int i=0;
            for (auto reg: listRegistro) {
                ui->tableCpfQte->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(reg.first.getValor())));
                ui->tableCpfQte->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(to_string(reg.second))));
                i++;
            }        
            ui->tableCpfQte->update();
            ui->stackedWidget->setCurrentIndex(3);
        } catch (...) {
            cout << "Deu ruim na tabela" << endl;
        }
    } else {
        cout << "CLICKOU ERRADO MALUCO" << endl;
    }
}

void viewVendas::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
