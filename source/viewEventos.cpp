#include "include/viewEventos.h"
#include "ui_viewEventos.h"

viewEventos::viewEventos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewEventos)
{
    ui->setupUi(this);

    // Diretorio Caso QtCreator
    QPixmap pix("../TrabalhoTP1/imagens/interrogacao.png");

    // Diretorio caso Clion
    //QPixmap pix("../imagens/interrogacao.png");

    // Código do Help para digitação dos campos de adicionar evento
    ui->helpCodigo->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpCodigo->setToolTip("O Código do evento deve estar no formato XXX no qual X é dígito (0-9)");
    ui->helpNome->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpNome->setToolTip("O Nome do evento deve estar no formato XXXXXXXXXXXXXXXXXXXX no qual cada X pode ser letra, dígito ou espaço");
    ui->helpFaixa->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpFaixa->setToolTip("A faixa etária deve ser L, 10, 12, 14, 16 ou 18");
    ui->helpCidade->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpCidade->setToolTip("A cidade deve estar no formato XXXXXXXXXXXXXXX. Cada X pode ser letra, espaço ou ponto."
                               "Não pode existir espaços seguidos, ponto deve ser precedido por letra e pelo menos um caracter deve ser letra");
    ui->helpEstado->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpEstado->setToolTip("AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, "
                               "PI, RJ, RN, RS, RO, RR, SC, SP, SE ou TO");
    ui->helpClasse->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->helpClasse->setToolTip("O formato da Classe de Evento deve ser X no qual X é um dígito de 1 a 4.\n"
                               "1- Teatro\n"
                               "2- Esporte\n"
                               "3- Show Nacional\n"
                               "4- Show Internacional");

    // Código do Help para digitação dos campos de adicionar apresentação
    ui->aprHelpCodigo->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->aprHelpCodigo->setToolTip("O Código da apresentação deve estar no formato XXXX no qual X é dígito (0-9)");
    ui->aprHelpData->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->aprHelpData->setToolTip("A data deve estar no formato DD/MM/AA");
    ui->aprHelpDisp->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->aprHelpDisp->setToolTip("A disponibilidade é um número no intervalo [0, 250]");
    ui->aprHelpPreco->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->aprHelpPreco->setToolTip("O preço deve ser um de 0 a 1000 reais");
    ui->aprHelpSala->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->aprHelpSala->setToolTip("O número da sala é um valor no intervalo [1, 10]");
    ui->aprHelpHorario->setPixmap(pix.scaled(35,35,Qt::KeepAspectRatio));
    ui->aprHelpHorario->setToolTip("O horário deve estar no formato HH:MM\n"
                                   "HH é número de 07 a 22\n"
                                   "MM é 00, 15, 30 ou 45");
    ui->labelCreated->setText("");
}

viewEventos::~viewEventos()
{
    delete ui;
}

void viewEventos::executar(CPF cpf) {
    // Ao executar a view limpar os campos de evento e apresentação
    viewEventos::aprlineclean();
    viewEventos::eventolineclean();
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

// ---------------------------------------------------------------
// Lógica da view
void viewEventos::on_btnPesquisarReal_clicked()
{
    Cidade cidade;
    Estado estado;
    Data dataIncio;
    Data dataFim;
    // Retirar tamanho quando pesquisar estiver pronto
    list<Evento> listaEventos;
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
    int i=0;
    for (auto evento: listaEventos) {
        ui->tableEventos->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(evento.getCodigo().getValor())));
        ui->tableEventos->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(evento.getNome().getValor())));
        ui->tableEventos->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(evento.getCidade().getValor())));
        ui->tableEventos->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(evento.getEstado().getValor())));
        ui->tableEventos->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(evento.getClasse().getValor())));
        ui->tableEventos->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(evento.getFaixa().getValor())));
        ui->tableEventos->setItem(i, 6, new QTableWidgetItem("Link para Apresentações"));
        i++;
    }

    ui->tableEventos->update();
}

// Adiciona a informação do evento para posteriormente inserir no BD
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
        ui->labelCreated->setText("Agora você pode começar a inserir as apresentações!");
        listApresentacao.clear();
    } catch(...){
        cout << "erro adicionar evento" << endl;
    }
}

// Troca a view para adicionar a apresentção
void viewEventos::on_btnCriar_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// Adiciona apresentacoes na lista de apresentações para posteriormente adiciona-las
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
     ui->labelCreated->setText("Apresentação criada com sucesso!");
     this->aprlineclean();
    } catch (...) {
        ui->labelCreated->setText("Erro ao criar apresentação, tente novamente ou conclua a criação do evento!");
        cout << "Erro ao adicionar Apresentação" << endl;
    }
}

// Criar de fato o evento com as apresentações associadas
void viewEventos::on_btnConcluirApr_clicked()
{
    try {
        ui->labelCreated->setText("Evento criado com sucesso, clique em Home!");
        modelEventos->criarEvento(cpfUsuarioLogado, eventoADD, listApresentacao);
    } catch (...) {

        cout << "Erro ao criar Evento" << endl;
    }
}

// Método no qual quando clicar na última célua da tabela Eventos -> mostrar tabela apresentação
void viewEventos::on_tableEventos_cellClicked(int row, int column)
{
    int ULTIMA_COLUNA = 6;
    list<Apresentacao> listaApresentacao;
    if (column == ULTIMA_COLUNA) {
        CodigoDeEvento codigo;
        codigo.setValor( ui->tableEventos->itemAt(row, 0)->text().toStdString()) ;
        modelEventos->mostrarApresentacao(listaApresentacao, codigo);

        // Adicionar na tabela
        ui->tableApresentacao->clearContents();
        ui->tableApresentacao->setRowCount(listaApresentacao.size());
        int i=0;
        for (auto apresentacao : listaApresentacao) {
            ui->tableApresentacao->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(apresentacao.getCodigo().getValor())));
            ui->tableApresentacao->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(apresentacao.getData().getValor())));
            ui->tableApresentacao->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(apresentacao.getHorario().getValor())));
            ui->tableApresentacao->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(apresentacao.getPreco().getValor())));
            ui->tableApresentacao->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(apresentacao.getNumeroDeSala().getValor())));
            ui->tableApresentacao->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(apresentacao.getDisponibilidade().getValor())));
            i++;
        }
        ui->tableApresentacao->update();
        ui->stackedWidget->setCurrentIndex(4);

    }
}
//------------------------------------------------------------------

// -----------------------------------------------------------------
// Métodos para auxiliar usuário por tipos corretos
void viewEventos::on_clineCodigo_editingFinished()
{
    CodigoDeEvento codigo;
    try {
        codigo.setValor(ui->clineCodigo->text().toStdString());
        ui->checkCodigo->setStyleSheet("color:#7d7");
        ui->checkCodigo->setText("✓");
    } catch (...) {
        ui->checkCodigo->setStyleSheet("color:#f00");
        ui->checkCodigo->setText("x");
    }
}

void viewEventos::on_clineNome_editingFinished()
{
    NomeDeEvento nome;
    try {
        nome.setValor(ui->clineNome->text().toStdString());
        ui->checkNome->setStyleSheet("color:#7d7");
        ui->checkNome->setText("✓");
    } catch (...) {
        ui->checkNome->setStyleSheet("color:#f00");
        ui->checkNome->setText("x");
    }
}

void viewEventos::on_clineCidade_editingFinished()
{
    Cidade cidade;
    try {
        cidade.setValor(ui->clineCidade->text().toStdString());
        ui->checkCidade->setStyleSheet("color:#7d7");
        ui->checkCidade->setText("✓");
    } catch (...) {
        ui->checkCidade->setStyleSheet("color:#f00");
        ui->checkCidade->setText("x");
    }
}

void viewEventos::on_clineEstado_editingFinished()
{
    Estado estado;
    try {
        estado.setValor(ui->clineEstado->text().toStdString());
        ui->checkEstado->setStyleSheet("color:#7d7");
        ui->checkEstado->setText("✓");
    } catch (...) {
        ui->checkEstado->setStyleSheet("color:#f00");
        ui->checkEstado->setText("x");
    }

}

void viewEventos::on_clineClasse_editingFinished()
{
    ClasseDeEvento classe;
    try {
        classe.setValor(ui->clineClasse->text().toStdString());
        ui->checkClasse->setStyleSheet("color:#7d7");
        ui->checkClasse->setText("✓");
    } catch (...) {
        ui->checkClasse->setStyleSheet("color:#f00");
        ui->checkClasse->setText("x");
    }
}

void viewEventos::on_clineFaixa_editingFinished()
{
    FaixaEtaria faixa;
    try {
        faixa.setValor(ui->clineFaixa->text().toStdString());
        ui->checkFaixa->setStyleSheet("color:#7d7");
        ui->checkFaixa->setText("✓");
    } catch (...) {
        ui->checkFaixa->setStyleSheet("color:#f00");
        ui->checkFaixa->setText("x");
    }
}

void viewEventos::on_alineData_editingFinished()
{
    Data data;
    try {
        data.setValor(ui->alineData->text().toStdString());
        ui->aprCheckData->setStyleSheet("color:#7d7");
        ui->aprCheckData->setText("✓");
    } catch (...) {
        ui->aprCheckData->setStyleSheet("color:#f00");
        ui->aprCheckData->setText("x");
    }
}

void viewEventos::on_alineHorario_editingFinished()
{
    Horario horario;
    try {
        horario.setValor(ui->alineHorario->text().toStdString());
        ui->aprCheckHor->setStyleSheet("color:#7d7");
        ui->aprCheckHor->setText("✓");
    } catch (...) {
        ui->aprCheckHor->setStyleSheet("color:#f00");
        ui->aprCheckHor->setText("x");
    }
}

void viewEventos::on_alineCodigo_editingFinished()
{
    CodigoDeApresentacao codigo;
    try {
        codigo.setValor(ui->alineCodigo->text().toStdString());
        ui->aprCheckCod->setStyleSheet("color:#7d7");
        ui->aprCheckCod->setText("✓");
    } catch (...) {
        ui->aprCheckCod->setStyleSheet("color:#f00");
        ui->aprCheckCod->setText("x");
    }
}

void viewEventos::on_alinePreco_editingFinished()
{
    Preco preco;
    try {
        preco.setValor(ui->alinePreco->text().toStdString());
        ui->aprCheckPreco->setStyleSheet("color:#7d7");
        ui->aprCheckPreco->setText("✓");
    } catch (...) {
        ui->aprCheckPreco->setStyleSheet("color:#f00");
        ui->aprCheckPreco->setText("x");
    }
}

void viewEventos::on_alineSala_editingFinished()
{
    NumeroDeSala sala;
    try {
        sala.setValor(ui->alineSala->text().toStdString());
        ui->aprCheckSala->setStyleSheet("color:#7d7");
        ui->aprCheckSala->setText("✓");
    } catch (...) {
        ui->aprCheckSala->setStyleSheet("color:#f00");
        ui->aprCheckSala->setText("x");
    }
}

void viewEventos::on_alineDisponibilidade_editingFinished()
{
    Disponibilidade disponibilidade;
    try {
        disponibilidade.setValor(ui->alineDisponibilidade->text().toStdString());
        ui->aprCheckDisp->setStyleSheet("color:#7d7");
        ui->aprCheckDisp->setText("✓");
    } catch (...) {
        ui->aprCheckDisp->setStyleSheet("color:#f00");
        ui->aprCheckDisp->setText("x");
    }
}
//---------------------------------------------------------------------

// -------------------------------------------------------------------
// Métodos para limpar view
void viewEventos::eventolineclean(){
    ui->clineNome->setText("");
    ui->checkNome->setText("");
    ui->clineFaixa->setText("");
    ui->checkFaixa->setText("");
    ui->clineCidade->setText("");
    ui->checkCidade->setText("");
    ui->clineClasse->setText("");
    ui->checkClasse->setText("");
    ui->clineCodigo->setText("");
    ui->checkCodigo->setText("");
    ui->clineEstado->setText("");
    ui->checkEstado->setText("");
}

void viewEventos::aprlineclean(){
    QTime time = QTime::fromString("00:00", "hh:mm");
    QDate date = QDate::fromString("01/01/00", "dd/MM/yy");
    // Reiniciando valores das linetext
    ui->alineData->setDate(date);
    ui->alineSala->setText("");
    ui->alinePreco->setText("");
    ui->alineCodigo->setText("");
    ui->alineDisponibilidade->setText("");
    ui->alineHorario->setTime(time);
    // Reiniciando Check
    ui->aprCheckCod->setText("");
    ui->aprCheckHor->setText("");
    ui->aprCheckData->setText("");
    ui->aprCheckSala->setText("");
    ui->aprCheckDisp->setText("");
    ui->aprCheckPreco->setText("");
}
//---------------------------------------------------------------------


void viewEventos::on_btnPesquisar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void viewEventos::on_buttonHome_clicked()
{
    this->close();
}

void viewEventos::on_pushButton_clicked()
{
    this->close();
}
