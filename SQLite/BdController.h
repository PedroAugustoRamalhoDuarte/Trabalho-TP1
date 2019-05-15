#ifndef TRABALHOTP1_BDCONTROLLER_H
#define TRABALHOTP1_BDCONTROLLER_H

#include "../include/Entidades.h"
#include <iostream>
#include <sqlite3.h>

class BdController {
private:

    sqlite3* db;
    /* Criacao de tabelas */

    void criarTabelaUsuario();

    void criarTabelaIngresso();

    void criarTabelaEvento();

    void criarTabelaApresentacao();

    void static verificarErro(int status, char* mensagem);
public:

    void inserirUsuario(const Usuario &usuario,const CartaoDeCredito &cartaoDeCredito);

    void inserirIngresso(const Ingresso &ingresso, const CPF &cpf);

    void criarTabelas();

    BdController();

    virtual ~BdController();
};


#endif //TRABALHOTP1_BDCONTROLLER_H
