//
// Created by pedro on 14/05/19.
//

#include "../include/Model.h"

list<string> Model::listaResultados = {};

Model::Model() {
    cout << "Conectando..." << endl;
    int error = 0;
    error = sqlite3_open("example.db", &db);


    if (error) {

        cout << "DB Open Error: " << sqlite3_errmsg(db) << endl;

    } else {

        cout << "Opened Database Successfully!" << endl;
    }
}

/* Criação de Tabelas */
void Model::criarTabelaIngresso() {
    const char *sql;
    sql = "CREATE TABLE IF NOT EXISTS ingresso("
          "codigo_ingresso  INT PRIMARY KEY,"
          "codigo_apresentacao INT NOT NULL,"
          "cpf_usuario  VARCHAR(14) NOT NULL,"
          "FOREIGN KEY(codigo_apresentacao) REFERENCES apresentacao,"
          "FOREIGN KEY(cpf_usuario) REFERENCES usuario);";

    status = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    if (status != SQLITE_OK) {
        cout << "Falha ao criar tabela ingresso" << endl;
    } else {
        cout << "tabela ingresso criada com sucesso" << endl;
    }
}

void Model::criarTabelaUsuario() {
    const char *sql;

    sql = "CREATE TABLE IF NOT EXISTS usuario("
          "cpf VARCHAR(14) PRIMARY KEY,"
          "senha VARCHAR(12) NOT NULL,"
          "codigo_cartao INT NOT NULL,"
          "numero_cartao VARCHAR(16) NOT NULL,"
          "data_validade VARCHAR(5) NOT NULL);";

    status = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    if (status != SQLITE_OK) {
        cout << "Falha ao criar tabela usuarios" << endl;
    } else {
        cout << "Tabela usuario criada com sucesso" << endl;
    }
}

void Model::criarTabelaEvento() {
    const char *sql;

    sql = "CREATE TABLE IF NOT EXISTS evento("
          "cpf_usuario VARCHAR(14) NOT NULL,"
          "codigo int PRIMARY KEY,"
          "nome VARCHAR(20) NOT NULL,"
          "cidade VARCHAR(15) NOT NULL,"
          "estado VARCHAR(2) NOT NULL,"
          "classe SMALLINT(1) NOT NULL,"
          "faixa_etaria VARCHAR(2) NOT NULL,"
          "FOREIGN KEY(cpf_usuario) REFERENCES usuario);";

    status = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    if (status != SQLITE_OK) {
        cout << "Falha ao criar tabela evento" << endl;
    } else {
        cout << "Tabela evento criada com sucesso" << endl;
    }
}

void Model::criarTabelaApresentacao() {
    const char *sql;

    sql = "CREATE TABLE IF NOT EXISTS apresentacao("
          "codigo_evento int REFERENCES evento NOT NULL,"
          "codigo_apresentacao int PRIMARY KEY,"
          "data VARCHAR(8) NOT NULL,"
          "horario VARCHAR(15) NOT NULL,"
          "preco FLOAT NOT NULL,"
          "sala INT NOT NULL,"
          "disponibilidade INT NOT NULL,"
          "FOREIGN KEY(codigo_evento) REFERENCES evento);";

    status = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    if (status != SQLITE_OK) {
        cout << "Falha ao criar tabela apresentacao" << endl;
    } else {
        cout << "Tabela apresentacao criada com sucesso" << endl;
    }
}

/***********************************************************/

void Model::criarTabelas() {
    // Testar se deu erro depois
    criarTabelaUsuario();
    criarTabelaEvento();
    criarTabelaApresentacao();
    criarTabelaIngresso();
}

/*Model::~Model() {
    cout << "Closing DataBase... " << endl;
    sqlite3_close(db);
    db = nullptr;
}*/


void Model::executar() {
    status = sqlite3_exec(db, comandoSQL.c_str(), callback, nullptr, &mensagem);
    if (status != SQLITE_OK) {
        if (mensagem)
            free(mensagem);
        throw invalid_argument("Erro na execucao do comando SQL");
    }
}

int Model::callback(void *notUsed, int argc, char **argv, char **azColName) {
    int i;
    //cout << "ARGC:" << argc << endl;
    //cout << "ARGV:" << *argv << endl;
    //fprintf(stderr, "%s: ", (const char *) data);
    /*
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");*/

    for (i = 0; i < argc; i++) {
        listaResultados.push_back(argv[i]);
    }
    return 0;
}

// --------------------------------------------------------------------------
// Model Servico de Usuario

// Construtor
ModelUsuario::ModelUsuario() : Model() {
}

// Metodos da Interface Serviço Usuário
bool ModelUsuario::cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) {
    comandoSQL = "INSERT INTO usuario VALUES (";
    comandoSQL += "'" + usuario.getCpf().getValor() + "', ";
    comandoSQL += "'" + usuario.getSenha().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getCodigoDeSeguranca().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getNumero().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getDataDeValidade().getValor() + "');";
    try {
        cout << "Inserindo usuario :" << endl;
        this->executar();
        return true;
    } catch (invalid_argument &e) {
        return false;
    }
}

bool ModelUsuario::mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) {
    comandoSQL = "SELECT * FROM usuario WHERE cpf = ";
    comandoSQL += "'" + cpf.getValor() + "';";

    // Variaveis auxiliares
    CPF auxCpf;
    Senha auxSenha;
    NumeroDeCartaoDeCredito numero;
    CodigoDeSeguranca codigo;
    DataDeValidade validade;
    try {
        cout << "Procurando usuario : ";
        cout << cpf.getValor() << endl;
        this->executar();

        // Atribui a data de validade
        validade.setValor(listaResultados.back());
        listaResultados.pop_back();
        cartaoDeCredito->setDataDeValidade(validade);

        // Atribui o Numero de cartão
        numero.setValor(listaResultados.back());
        listaResultados.pop_back();
        cartaoDeCredito->setNumero(numero);

        // Atribui o Codigo de segurança
        codigo.setValor(listaResultados.back());
        listaResultados.pop_back();
        cartaoDeCredito->setCodigoDeSeguranca(codigo);

        // Atribui a senha
        auxSenha.setValor(listaResultados.back());
        listaResultados.pop_back();
        usuario->setSenha(auxSenha);

        // Atribui o cpf
        auxCpf.setValor(listaResultados.back());
        listaResultados.pop_back();
        usuario->setCpf(auxCpf);

        return true;
    } catch (invalid_argument &e) {
        cout << "Erro ao Procurar Usuario(Mostrar Model)";
        return false;
    }
}

bool ModelUsuario::excluirUsuario(CPF cpf) {
    comandoSQL = "DELETE FROM usuario WHERE cpf = ";
    comandoSQL += "'" + cpf.getValor() + "';";
    cout << "Excluindo Usuario : ";
    cout << cpf.getValor() << endl;
    try {
        this->executar();
        return true;
    } catch (...) {
        return false;
    }
}

// --------------------------------------------------------------------------
// Model Servico Autenticacao

ModelAutenticacao::ModelAutenticacao() : Model() {}

bool ModelAutenticacao::autenticar(CPF cpf, Senha senha) {
    comandoSQL = "SELECT senha FROM usuario WHERE cpf =";
    comandoSQL += "'" + cpf.getValor() + "';";
    cout << "Autenticando Usuario";
    cout << cpf.getValor() << endl;
    try {
        // Verificar se as senhas coincidem
        this->executar();
        if (listaResultados.back() == senha.getValor()) {
            listaResultados.clear();
            cout<<"autenticou";
            return true;
        } else {
            listaResultados.clear();
            cout<<"nao autenticou";
            return false;
        }

    } catch (...) {
        return false;
    }
}

// --------------------------------------------------------------------------
// Model Eventos Autenticacao

ModelEventos::ModelEventos() : Model() {}

// return: True se for menor que o limite, False se for maior que o limiete
bool ModelEventos::isLimiteEventos(CPF cpf) {
    // Verifica se o usuario tem um numero maior ou igual de eventos permitidos
    comandoSQL = "SELECT COUNT(*) FROM evento WHERE cpf_usuario =";
    comandoSQL += "'" + cpf.getValor() + "';";
    try {
        this->executar();
        // Se tem menos evento que o limite
        if (atoi(listaResultados.back().c_str()) < LIMITE_EVENTOS) {
            listaResultados.clear();
            return true;
        } else {
            listaResultados.clear();
            return false;
        }
    } catch (...) {
        return false;
    }
}

bool ModelEventos::criarEvento(CPF cpf, Evento evento, list<Apresentacao> listaApresentacao) {
    // Primeiramente verificar se o usuario nao possui mais que o limite de eventos
    if (this->isLimiteEventos(cpf) && listaApresentacao.size() <= LIMITE_APRESENTACAO) {
        comandoSQL = "INSERT INTO evento VALUES (";
        comandoSQL += "'" + cpf.getValor() + "', ";
        comandoSQL += "'" + evento.getCodigo().getValor() + "',";
        comandoSQL += "'" + evento.getNome().getValor() + "',";
        comandoSQL += "'" + evento.getCidade().getValor() + "',";
        comandoSQL += "'" + evento.getEstado().getValor() + "',";
        comandoSQL += "'" + evento.getClasse().getValor() + "',";
        comandoSQL += "'" + evento.getFaixa().getValor() + "');";
        // Adicionar apresentacoes depois
        try {
            // Executa o comando mysql
            this->executar();
            adicionarApresentacoes(evento.getCodigo(), listaApresentacao);
            return true;
        } catch (...) {
            // Se der falha ao executar o comando
            cout << "Falha ao criar evento" << endl;
            return false;
        }

    } else {
        // Como mostrar para o usuario esse erro?
        cout << "Falha ao criar envento:Limite de eventos" << endl;
        return false;
    }
}

bool ModelEventos::alterarEvento(CPF cpf, Evento evento) {
    return false;
}

bool ModelEventos::descadastrarEvento(CPF cpf, Evento evento) {
    return false;
}

bool ModelEventos::pesquisarEventos(list<Evento> &listaEventos, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) {
    return false;
}

void ModelEventos::adicionarApresentacoes(CodigoDeEvento codigo, list<Apresentacao> listaApresentacao) {
    for (Apresentacao apresentacao: listaApresentacao) {
        try {
            comandoSQL = "INSERT INTO apresentacao VALUES (";
            comandoSQL += "'" + codigo.getValor() + "', ";
            comandoSQL += "'" + apresentacao.getCodigo().getValor() + "',";
            comandoSQL += "'" + apresentacao.getData().getValor() + "',";
            comandoSQL += "'" + apresentacao.getHorario().getValor() + "',";
            comandoSQL += "'" + apresentacao.getPreco().getValor() + "',";
            comandoSQL += "'" + apresentacao.getNumeroDeSala().getValor() + "',";
            comandoSQL += "'" + apresentacao.getDisponibilidade().getValor() + "');";
            this->executar();
        } catch (...) {

        }
    }
}

// --------------------------------------------------------------------------
// Model Serviço Vendas
ModelVendas::ModelVendas() : Model() {}

bool ModelVendas::adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) {
    return false;
}
