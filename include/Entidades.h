#ifndef TRABALHOTP1_ENTIDADES_H
#define TRABALHOTP1_ENTIDADES_H

#include "Dominios.h"

class Usuario {
private:
    // Chave primaria
    CPF cpf;

    Senha senha;
};


class Evento {
private:
    // Chave primaria
    CodigoDeEvento codigoDeEvento;

    NomeDeEvento nomeDeEvento;

    Cidade cidade;

    Estado estado;

    ClasseDeEvento classeDeEvento;

    FaixaEtaria faixaEtaria;
};


class Apresentacao{
private:
    // Chave Primaria
    CodigoDeApresentacao codigoDeApresentacao;

    Data data;

    Horario horario;

    Preco preco;

    NumeroDeSala numeroDeSala;

    Disponibilidade disponibilidade;
};


class Ingresso {
private:
    // Chave Primaria
    CodigoDeIngresso codigoDeIngresso;
};


class CartaoDeCredito {
private:
    // Chave Primaria
    NumeroDeCartaoDeCredito numeroDeCartaoDeCredito;

    CodigoDeSeguranca codigoDeSeguranca;

    DataDeValidade dataDeValidade;
};

#endif //TRABALHOTP1_ENTIDADES_H
