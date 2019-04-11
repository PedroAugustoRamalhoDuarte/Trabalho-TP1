#ifndef TRABALHOTP1_ENTIDADES_H
#define TRABALHOTP1_ENTIDADES_H

#include "Dominios.h"

class Usuario {
private:
    // Chave primaria
    CPF cpf;

    Senha senha;


public:
    Usuario(const CPF &cpf, const Senha &senha);

    const CPF &getCpf() const;

    void setCpf(const CPF &cpf);

    const Senha &getSenha() const;

    void setSenha(const Senha &senha);

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

public:
    const CodigoDeEvento &getCodigoDeEvento() const;

    void setCodigoDeEvento(const CodigoDeEvento &codigoDeEvento);

    const NomeDeEvento &getNomeDeEvento() const;

    void setNomeDeEvento(const NomeDeEvento &nomeDeEvento);

    const Cidade &getCidade() const;

    void setCidade(const Cidade &cidade);

    const Estado &getEstado() const;

    void setEstado(const Estado &estado);

    const ClasseDeEvento &getClasseDeEvento() const;

    void setClasseDeEvento(const ClasseDeEvento &classeDeEvento);

    const FaixaEtaria &getFaixaEtaria() const;

    void setFaixaEtaria(const FaixaEtaria &faixaEtaria);
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

public:
    const CodigoDeApresentacao &getCodigoDeApresentacao() const;

    void setCodigoDeApresentacao(const CodigoDeApresentacao &codigoDeApresentacao);

    const Data &getData() const;

    void setData(const Data &data);

    const Horario &getHorario() const;

    void setHorario(const Horario &horario);

    const Preco &getPreco() const;

    void setPreco(const Preco &preco);

    const NumeroDeSala &getNumeroDeSala() const;

    void setNumeroDeSala(const NumeroDeSala &numeroDeSala);

    const Disponibilidade &getDisponibilidade() const;

    void setDisponibilidade(const Disponibilidade &disponibilidade);
};


class Ingresso {
private:
    // Chave Primaria
    CodigoDeIngresso codigoDeIngresso;

public:
    const CodigoDeIngresso &getCodigoDeIngresso() const;

    void setCodigoDeIngresso(const CodigoDeIngresso &codigoDeIngresso);


};


class CartaoDeCredito {
private:
    // Chave Primaria
    NumeroDeCartaoDeCredito numeroDeCartaoDeCredito;

    CodigoDeSeguranca codigoDeSeguranca;

    DataDeValidade dataDeValidade;

public:
    const NumeroDeCartaoDeCredito &getNumeroDeCartaoDeCredito() const;

    void setNumeroDeCartaoDeCredito(const NumeroDeCartaoDeCredito &numeroDeCartaoDeCredito);

    const CodigoDeSeguranca &getCodigoDeSeguranca() const;

    void setCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca);

    const DataDeValidade &getDataDeValidade() const;

    void setDataDeValidade(const DataDeValidade &dataDeValidade);
};

#endif //TRABALHOTP1_ENTIDADES_H
