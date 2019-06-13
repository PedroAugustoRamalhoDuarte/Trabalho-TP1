//
// Created by pedro on 14/05/19.
//

#include "../include/Model.h"

list<string> Model::listaResultados = {};

Model::Model() {
    cout << "Conectando..." << endl;
    int error = 0;
    // Mudar quando for passar para o CodeBlocks
    error = sqlite3_open("../TrabalhoTP1/bd/example.db", &db);

    if (error) {

        cout << "DB Open Error: " << sqlite3_errmsg(db) << endl;

    } else {

        cout << "Opened Database Successfully!" << endl;
    }
}

// Criação de Tabelas
void Model::criarTabelaIngresso() {
    const char *sql;
    sql = "CREATE TABLE IF NOT EXISTS ingresso("
          "codigo_ingresso INTEGER PRIMARY KEY AUTOINCREMENT,"
          "codigo_apresentacao VARCHAR(10) NOT NULL,"
          "cpf_usuario  VARCHAR(14) NOT NULL,"
          "quantidade INTEGER NOT NULL,"
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
          "codigo_cartao VARCHAR(10) NOT NULL,"
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
          "codigo VARCHAR(10) PRIMARY KEY,"
          "nome VARCHAR(20) NOT NULL,"
          "cidade VARCHAR(15) NOT NULL,"
          "estado VARCHAR(2) NOT NULL,"
          "classe VARCHAR(1) NOT NULL,"
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
          "codigo_evento VARCHAR(10) REFERENCES evento NOT NULL,"
          "codigo_apresentacao VARCHAR(10) PRIMARY KEY,"
          "data VARCHAR(8) NOT NULL,"
          "horario VARCHAR(15) NOT NULL,"
          "preco VARCHAR(10) NOT NULL,"
          "sala VARCHAR(10) NOT NULL,"
          "disponibilidade VARCHAR(10) NOT NULL,"
          "FOREIGN KEY(codigo_evento) REFERENCES evento);";

    status = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);

    if (status != SQLITE_OK) {
        cout << "Falha ao criar tabela apresentacao" << endl;
    } else {
        cout << "Tabela apresentacao criada com sucesso" << endl;
    }
}

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
        if (*mensagem)
            cout << mensagem;
        //  free(mensagem);
        cout << "ERRO SQL" << endl;
        throw invalid_argument("Erro na execucao do comando SQL");
    }
}

int Model::callback(void *notUsed, int argc, char **argv, char **azColName) {
    int i;
    if (*argv == nullptr)
        return 0;
    for (i = 0; i < argc; i++) {
        listaResultados.push_back(argv[i]);
    }
    return 0;
}







