#include "include/viewEventos.h"
#include "ui_viewEventos.h"

viewEventos::viewEventos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewEventos)
{
    ui->setupUi(this);
}

viewEventos::~viewEventos()
{
    delete ui;
}

void viewEventos::executar(CPF cpf) {
    if (cpf.getValor() != "") {
        cpfUsuarioLogado = cpf;
        // Menu Eventos Usuario logado
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        // Pesquisar Evento
        ui->stackedWidget->setCurrentIndex(1);
    }
    this->show();

}

void viewEventos::on_btnHome_clicked()
{
    this->close();
}

void viewEventos::on_btnPesquisarReal_clicked()
{
    Cidade cidade;
    Estado estado;
    Data dataIncio;
    Data dataFim;
    // Retirar tamanho quando pesquisar estiver pronto
    list<Evento> listaEventos(5);
    try {
        // Pesquisar
        cidade.setValor(ui->lineCidade->text().toStdString());
        estado.setValor(ui->lineEstado->text().toStdString());
        dataIncio.setValor(ui->dateInicio->text().toStdString());
        dataFim.setValor(ui->dateFim->text().toStdString());
        modelEventos->pesquisarEventos(listaEventos, dataIncio, dataFim, cidade, estado);
    } catch (...) {
        cout << "Erro na Pesquisa" << endl;
    }

    if (listaEventos.size() == 0 ) {
        // Mostrar ao Usuário que não houve elementos no sistema no qual se enquadra na busca
    }

    // Adicionar na tabela
    ui->tableEventos->clearContents();
    ui->tableEventos->setRowCount(listaEventos.size());
    for (int i=0; i < listaEventos.size() ; i++) {
        ui->tableEventos->setItem(i, 1, new QTableWidgetItem("Hello"));
        ui->tableEventos->setItem(i, 6, new QTableWidgetItem("Link para Apresentações"));
    }

    ui->tableEventos->update();
}

void viewEventos::on_btnCriarEvento_clicked()
{
    CodigoDeEvento codigo;
    NomeDeEvento nome;
    Cidade cidade;
    Estado estado;
    ClasseDeEvento classe;
    FaixaEtaria faixa;

    try {
        codigo.setValor(ui->clineCodigo->text().toStdString());
        nome.setValor(ui->clineNome->text().toStdString());
        cidade.setValor(ui->clineCidade->text().toStdString());
        estado.setValor(ui->clineEstado->text().toStdString());
        classe.setValor(ui->clineClasse->text().toStdString());
        faixa.setValor(ui->clineFaixa->text().toStdString());
        eventoADD.setCodigo(codigo);
        eventoADD.setNome(nome);
        eventoADD.setCidade(cidade);
        eventoADD.setEstado(estado);
        eventoADD.setClasse(classe);
        eventoADD.setFaixa(faixa);
        ui->stackedWidget->setCurrentIndex(3);
        listApresentacao.clear();
    } catch(...){
        cout << "erro adicionar evento" << endl;
    }
}

void viewEventos::on_btnCriar_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void viewEventos::on_btnAdicionarApr_clicked()
{
    CodigoDeApresentacao codigo;
    Data data;
    Horario horario;
    Preco preco;
    NumeroDeSala sala;
    Disponibilidade disponibilidade;
    Apresentacao apresentacao;
    try {
     codigo.setValor(ui->alineCodigo->text().toStdString());
     data.setValor(ui->alineData->text().toStdString());
     horario.setValor(ui->alineHorario->text().toStdString());
     preco.setValor(ui->alinePreco->text().toStdString());
     sala.setValor(ui->alineSala->text().toStdString());
     disponibilidade.setValor(ui->alineDisponibilidade->text().toStdString());
     apresentacao.setCodigo(codigo);
     apresentacao.setData(data);
     apresentacao.setHorario(horario);
     apresentacao.setPreco(preco);
     apresentacao.setNumeroDeSala(sala);
     apresentacao.setDisponibilidade(disponibilidade);
     listApresentacao.push_back(apresentacao);
    } catch (...) {
        cout << "Erro ao adicionar Apresentação" << endl;
    }
}

void viewEventos::on_btnConcluirApr_clicked()
{
    try {
        modelEventos->criarEvento(cpfUsuarioLogado, eventoADD, listApresentacao);
    } catch (...) {
        cout << "Erro ao criar Evento" << endl;
    }
}
