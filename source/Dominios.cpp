// Pedro e Waliff
#include "../include/Dominios.h"


void Codigo::validar(string entrada) throw (invalid_argument){

}

void NomeDeEvento::validar(string entrada) throw (invalid_argument){

}

void Data::validar(string entrada) throw (invalid_argument){

}

void Horario::validar(string entrada) throw (invalid_argument){

}

void Preco::validar(string entrada) throw (invalid_argument){

}

void NumeroDeSala::validar(string entrada) throw (invalid_argument){

}

void Cidade::validar(string entrada) throw (invalid_argument){

}

void Estado::validar(string entrada) throw (invalid_argument){

}

void Disponibilidade::validar(string entrada) throw (invalid_argument){

}

void ClasseDeEvento::validar(string entrada) throw (invalid_argument){

}

void FaixaEtaria::validar(string entrada) throw (invalid_argument){

}

void CPF::validar(string entrada) throw (invalid_argument) {

    string CPFauxiliar;
    CPFauxiliar.resize(9);
    int digito1Validacao = 0, digito2Validacao = 0, contador = 0;


    if (entrada.size() != TAMANHO_CPF) {
        throw invalid_argument("Tamanho do CPF invalido");
    } else { // XXX.XXX.XXX-XX
        if (entrada[3] != '.' || entrada[7] != '.' || entrada[11] != '-') {
            throw invalid_argument("O CPF nao contem os digitos separadores");

        } else { // CPF no formato válido
            // Aloca o CPF em uma variável auxiliar, excluindo os digitos separadores, para cálculo do dígito verificador
            for (int j = 0; j < 11; j++) {
                // Quando for dígito separador, ignorar o dígito
                if (j == 3 || j == 7) {
                    j++;
                }
                CPFauxiliar[contador] = entrada[j];
                contador++;
            }

            for (int i = 0; i < 9; i++) {
                digito1Validacao += ((CPFauxiliar[i]) - '0') * (10 - i);
                digito2Validacao += (CPFauxiliar[8 - i] - '0') * (3 + i);
            }
            digito1Validacao = (digito1Validacao * 10) % 11;

            if (digito1Validacao == 10) {
                digito1Validacao = 0;
            }
            digito2Validacao += (entrada[TAMANHO_CPF - 2] - '0') * 2;
            digito2Validacao = (digito2Validacao * 10) % 11;
            if (digito2Validacao == 10) {
                digito2Validacao = 0;
            }
            if (digito1Validacao != entrada[TAMANHO_CPF - 2] - '0') {
                throw invalid_argument("Primeiro digito de verificacao invalido");
            }
            else if (digito2Validacao != entrada[TAMANHO_CPF - 1] - '0') {
                throw invalid_argument("Segundo digito de verificacao invalido");
            }
        }
    }
}

void Senha::validar(string entrada) throw (invalid_argument){

}

void NumeroDeCartaoDeCredito::validar(string entrada) throw (invalid_argument){
    int digitoVerificacao = 0, auxDigito = 0, somaDigitos = 0;
    if ( entrada.size() != TAMANHO_NUMERODECARTAO) {
        throw invalid_argument("Tamanho do Cartão Invalido");
    }
    else {
        // Atribui ao digitoVerificacao o ultimo numero do cartao
        digitoVerificacao = entrada[TAMANHO_NUMERODECARTAO - 1] - '0';
        for (int i=0; i < TAMANHO_NUMERODECARTAO - 1 ; i++) {
            // Quando estiver em uma posicao par
            if (i % 2 == 0) {
                // Multiplica o digito por 2
                auxDigito = (entrada[i] - '0') * 2;
                // Se o digito multiplicado por 2 for maior que 9
                if (auxDigito >  9) {
                    // Soma os algarismos do digito multiplicado por 2
                    somaDigitos += auxDigito - 9;
                }
                else {
                    // Soma os digitos
                    somaDigitos += auxDigito;
                }

            }
            // Quando estiver em posicao impar
            else {
                somaDigitos += entrada[i] - '0';
            }
        }

        if ((somaDigitos + digitoVerificacao) % 10 != 0) {
           throw invalid_argument("Numero Invalido Segundo o Algoritmo de Luhn");
        }
    }
}

void DataDeValidade::validar(string entrada) throw (invalid_argument){

}