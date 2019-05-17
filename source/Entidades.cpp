#include "../include/Entidades.h"

// Contrutores que incializam todos os atributos
Usuario::Usuario(const CPF &cpf, const Senha &senha) : cpf(cpf), senha(senha) {}

Evento::Evento(const CodigoDeEvento &codigo, const NomeDeEvento &nome, const Cidade &cidade, const Estado &estado,
               const ClasseDeEvento &classe, const FaixaEtaria &faixa) : codigo(codigo), nome(nome), cidade(cidade),
                                                                         estado(estado), classe(classe), faixa(faixa) {}

Apresentacao::Apresentacao(const CodigoDeApresentacao &codigo, const Data &data, const Horario &horario,
                           const Preco &preco, const NumeroDeSala &numeroDeSala, const Disponibilidade &disponibilidade)
        : codigo(codigo), data(data), horario(horario), preco(preco), numeroDeSala(numeroDeSala),
          disponibilidade(disponibilidade) {}

Ingresso::Ingresso(const CodigoDeIngresso &codigo) : codigo(codigo) {}

CartaoDeCredito::CartaoDeCredito(const NumeroDeCartaoDeCredito &numero, const CodigoDeSeguranca &codigoDeSeguranca,
                                 const DataDeValidade &dataDeValidade) : numero(numero),
                                                                         codigoDeSeguranca(codigoDeSeguranca),
                                                                         dataDeValidade(dataDeValidade) {}


// Construtores Default
Usuario::Usuario() = default;

Evento::Evento() = default;

Apresentacao::Apresentacao() = default;

Ingresso::Ingresso() = default;

CartaoDeCredito::CartaoDeCredito() = default;

