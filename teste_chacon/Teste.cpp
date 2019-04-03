#include "Teste.h"

//Definições de constantes.

//const int teste_chacon::SUCESSO;
//const int teste_chacon::FALHA;
//const string teste_chacon::VALOR_VALIDO;
//const string teste_chacon::VALOR_INVALIDO;

// EXEMPLO
// --------------------------------------------------------

// Definições de métodos da classe teste_chacon.

void TesteCPF::setUp(){
    objeto = new CPF();
    estado = SUCESSO;
}

void Teste::setUp(){
    objeto = new CPF();
    estado = SUCESSO;
}

void Teste::tearDown(){
    delete objeto;
}

void Teste::testarCenarioSucesso(){
    try{
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void Teste::testarCenarioFalha(){
    try{
        objeto->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int Teste::run(){
    setUp();
    //testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

