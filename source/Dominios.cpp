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

void CPF::validar(string entrada) throw (invalid_argument){
    int digito1Validacao = 0, digito2Validacao = 0, contador = 0;
    string CPFauxiliar;
    if (entrada.size() != TAMANHO_CPF) {
        throw invalid_argument("Tamanho do CPF invalido");
    }
    else { // XXX.XXX.XXX-XX
        if (entrada[3] != '.' || entrada[7] != '.' || entrada[11] != '-') {
            throw invalid_argument("O CPF nao contem os digitos separadores");

        }
        else { // CPF no formato válido
            // Aloca o CPF em uma variável auxiliar, excluindo os digitos separadores, para cálculo do dígito verificador
            for (int j = 0; j < 11; j++) {
                // Quando for dígito separador, ignorar o dígito
                if (j % 3 == 0) {
                    j++;
                }
                CPFauxiliar[contador] = entrada[j];
                contador++;
            }

            for (int i = 0; i < 9; i++) {
                digito1Validacao = ((CPFauxiliar[i]) - '0') * (10-i);
                digito2Validacao = (CPFauxiliar[8 - i] - '0') * (3 + i);
            }
            digito1Validacao = (digito1Validacao * 10) % 11;
            if (digito1Validacao == 10) {
                digito1Validacao = 0;
            }
            digito2Validacao = ((digito2Validacao + entrada[TAMANHO_CPF - 1] * 2) * 10) % 11;
            if (digito2Validacao == 10) {
                digito2Validacao = 0;
            }
            if (digito1Validacao != entrada[TAMANHO_CPF-1]) {
                throw invalid_argument("Primeiro digito de verificacao invalido");
            }
            else if (digito2Validacao != entrada[TAMANHO_CPF]) {
                throw invalid_argument("Segundo digito de verificacao invalido");
            }
        }
    }


}

void Senha::validar(string entrada) throw (invalid_argument){

}

void NumeroDeCartaoDeCredito::validar(string entrada) throw (invalid_argument){

}

void DataDeValidade::validar(string entrada) throw (invalid_argument){

}