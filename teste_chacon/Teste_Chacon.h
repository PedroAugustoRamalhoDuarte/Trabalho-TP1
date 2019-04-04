//
// Created by waliffcordeiro and peteroberto on 03/04/19.
//
#ifndef TRABALHOTP1_TESTE_H
#define TRABALHOTP1_TESTE_H

#include "../include/Dominios.h"

using namespace std;

// EXEMPLO
// --------------------------------------------------------

// teste_chacon de unidade de classe que representa um domínio.

class Teste {
protected:

    // Definições de constantes com o intuito de evitar numeros mágicos.

    const string VALOR_VALIDO;
    const string VALOR_INVALIDO;

    Dominio *objeto;         // Referência para o objeto a ser testado.

    int estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:

    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

    int run();
};

class TesteCPF : public Teste{
    void setUp();
    const string VALOR_VALIDO = "088.106.744-05";
    const string VALOR_INVALIDO = "088.106.744-89";
};

#endif //TRABALHOTP1_TESTE_H
