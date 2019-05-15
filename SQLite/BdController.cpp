//
// Created by pedro on 14/05/19.
//

#include "BdController.h"

BdController::BdController() {
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
void BdController::criarTabelaIngresso() {
    const char *sql;
    int status = 0;
    sql = "CREATE TABLE IF NOT EXISTS ingresso("
          "codigo_ingresso  INT PRIMARY KEY,"
          "codigo_apresentacao INT NOT NULL,"
          "cpf_usuario  VARCHAR(14) NOT NULL,"
          "FOREIGN KEY(codigo_apresentacao) REFERENCES apresentacao,"
          "FOREIGN KEY(cpf_usuario) REFERENCES usuario);";

    status = sqlite3_exec(db, sql, NULL, NULL, NULL);

    if (status != SQLITE_OK) {
        cout << "Falha ao criar tabela ingresso" << endl;
    } else {
        cout << "tabela ingresso criada com sucesso" << endl;
    }
}

void BdController::criarTabelaUsuario() {
    const char *sql;
    int status;

    sql = "CREATE TABLE IF NOT EXISTS usuario("
          "cpf VARCHAR(14) PRIMARY KEY,"
          "senha VARCHAR(6) NOT NULL,"
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

void BdController::criarTabelaEvento() {
    const char *sql;
    int status;

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

void BdController::criarTabelaApresentacao() {
    const char *sql;
    int status;

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

void BdController::criarTabelas() {
    // Testar se deu erro depois
    criarTabelaUsuario();
    criarTabelaEvento();
    criarTabelaApresentacao();
    criarTabelaIngresso();
}

BdController::~BdController() {
    sqlite3_close(db);
    db = nullptr;
}

void BdController::inserirIngresso(const Ingresso &ingresso, const CPF &cpf) {
    int status;
    char sql_stm[256];

    sprintf(sql_stm, "INSERT INTO ingresso VALUES(%s, \"%s\");", ingresso.getCodigo().getValor().c_str(),
            cpf.getValor().c_str());

    cout << sql_stm << endl;

    status = sqlite3_exec(db, sql_stm, NULL, NULL, NULL);

    if (status != SQLITE_OK) {
        cout << "Falha ao inserir ingresso" << endl;
    } else {
        cout << "Ingresso inserido com sucesso" << endl;
    }
}

void BdController::inserirUsuario(const Usuario &usuario, const CartaoDeCredito &cartaoDeCredito) {
    int status = SQLITE_OK;
    char sql_stm[256];
    sprintf(sql_stm, "INSERT INTO usuario VALUES(\"%s\", \"%s\");", usuario.getCpf().getValor().c_str(),
            usuario.getSenha().getValor().c_str());

    cout << sql_stm << endl;

    status = sqlite3_exec(db, sql_stm, nullptr, nullptr, nullptr);

    if (status != SQLITE_OK) {
        cout << "Falha ao inserir usuario" << endl;
    } else {
        cout << "Usuario inserido com sucesso" << endl;
    }
}

void BdController::verificarErro(int status, char *mensagem) {
    if (status != SQLITE_OK)
        return throw invalid_argument(mensagem);
}


