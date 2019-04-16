#ifndef TRABALHOTP1_ENTIDADES_H
#define TRABALHOTP1_ENTIDADES_H

#include "Dominios.h"

/** @brief Classe Usuario
 *
 *  Responsável pelo armazenamento dos usuários no sistema com os atributos: cpf e senha.
 *  @see CPF
 *  @see Senha
 */
class Usuario {
private:
    // Chave primaria
    CPF cpf; /**< CPF do usuário, Chave primária*/

    Senha senha;/**< atributo que armazena a senha do usuario */


public:
    const CPF getCpf() const;

    void setCpf(const CPF &cpf);

    const Senha &getSenha() const;

    void setSenha(const Senha &senha);

};

/** @brief Classe Evento
 *
 *  Responsável pelo armazenamento dos eventos no sistema com os atributos:codigo(chave primária),nome,
 *  cidade, estado, classe, faixa.
 */
class Evento {
private:
    // Chave primaria
    CodigoDeEvento codigo;/**< atributo que armazena o codigo do evento , Chave primária*/

    NomeDeEvento nome;/**< atributo que armazena o nome do evento*/

    Cidade cidade;/**< atributo que armazena a cidade do evento*/

    Estado estado;/**< atributo que armazena o estado do evento*/

    ClasseDeEvento classe;/**< atributo que armazena a classe do evento*/

    FaixaEtaria faixa;/**< atributo que armazena a faixa etária referente ao evento*/

public:
    const CodigoDeEvento &getCodigo() const;

    void setCodigo(const CodigoDeEvento &codigo);

    const NomeDeEvento &getNome() const;

    void setNome(const NomeDeEvento &nome);

    const Cidade &getCidade() const;

    void setCidade(const Cidade &cidade);

    const Estado &getEstado() const;

    void setEstado(const Estado &estado);

    const ClasseDeEvento &getClasse() const;

    void setClasse(const ClasseDeEvento &classe);

    const FaixaEtaria &getFaixa() const;

    void setFaixa(const FaixaEtaria &faixa);
};

/** @brief Classe Apresentação
 *
 *  Responsável pelo armazenamento das apresentações no sistema com os atributos:codigo(chave primária), data, horário,
 *  preço. número da sala, disponibilidade
 */
class Apresentacao{
private:
    // Chave Primaria
    CodigoDeApresentacao codigo; /**< atributo que armazena o codigo da apresentação , Chave primária*/

    Data data; /**< atributo que armazena a data da apresentação*/

    Horario horario; /**< atributo que armazena o horário da apresentação */

    Preco preco; /**< atributo que armazena o preço da apresentação */

    NumeroDeSala numeroDeSala; /**< atributo que armazena o numero da sala da apresentação */

    Disponibilidade disponibilidade; /**< atributo que armazena a disponibilidade da apresentação */

public:
    const CodigoDeApresentacao &getCodigo() const;

    void setCodigo(const CodigoDeApresentacao &codigo);

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


/** @brief Classe Ingresso.
 *
 *  Responsável pelo armazenamento dos ingressos no sistema com o atributo:codigo(chave primária).
 */
class Ingresso {
private:
    // Chave Primaria
    CodigoDeIngresso codigo; /**< atributo que armazena o codigo do ingresso , Chave primária*/

public:
    const CodigoDeIngresso &getCodigo() const;

    void setCodigo(const CodigoDeIngresso &codigo);


};


/** @brief Classe Cartão de crédito.
 *
 *  Responsável pelo armazenamento dos cartões de créditos do sistema com o atributo: número, código de segurança e data
 *  de validade
 */
class CartaoDeCredito {
private:
    // Chave Primaria
    NumeroDeCartaoDeCredito numero; /**< atributo que armazena o número do cartão de crédito , Chave primária */

    CodigoDeSeguranca codigoDeSeguranca; /**< atributo que armazena o código de segurança */

    DataDeValidade dataDeValidade; /**< atributo que armazena a data de validade do cartão de crédito */

public:
    const NumeroDeCartaoDeCredito &getNumero() const;

    void setNumero(const NumeroDeCartaoDeCredito &numero);

    const CodigoDeSeguranca &getCodigoDeSeguranca() const;

    void setCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca);

    const DataDeValidade &getDataDeValidade() const;

    void setDataDeValidade(const DataDeValidade &dataDeValidade);
};


// Definições dos metodos inline


// CPF
inline const CPF Usuario::getCpf() const {
    return cpf;
}

inline void Usuario::setCpf(const CPF &cpf) {
    Usuario::cpf = cpf;
}

inline const Senha &Usuario::getSenha() const {
    return senha;
}

inline void Usuario::setSenha(const Senha &senha) {
    Usuario::senha = senha;
}

// Evento
inline const CodigoDeEvento &Evento::getCodigo() const {
    return codigo;
}

inline void Evento::setCodigo(const CodigoDeEvento &codigo) {
    Evento::codigo = codigo;
}

inline const NomeDeEvento &Evento::getNome() const {
    return nome;
}

inline void Evento::setNome(const NomeDeEvento &nome) {
    Evento::nome = nome;
}

inline const Cidade &Evento::getCidade() const {
    return cidade;
}

inline void Evento::setCidade(const Cidade &cidade) {
    Evento::cidade = cidade;
}

inline const Estado &Evento::getEstado() const {
    return estado;
}

inline void Evento::setEstado(const Estado &estado) {
    Evento::estado = estado;
}

inline const ClasseDeEvento &Evento::getClasse() const {
    return classe;
}

inline void Evento::setClasse(const ClasseDeEvento &classe) {
    Evento::classe = classe;
}

inline const FaixaEtaria &Evento::getFaixa() const {
    return faixa;
}

inline void Evento::setFaixa(const FaixaEtaria &faixa) {
    Evento::faixa = faixa;
}

// Apresentacao

inline const CodigoDeApresentacao &Apresentacao::getCodigo() const {
    return codigo;
}

inline void Apresentacao::setCodigo(const CodigoDeApresentacao &codigo) {
    Apresentacao::codigo = codigo;
}

inline const Data &Apresentacao::getData() const {
    return data;
}

inline void Apresentacao::setData(const Data &data) {
    Apresentacao::data = data;
}

inline const Horario &Apresentacao::getHorario() const {
    return horario;
}

inline void Apresentacao::setHorario(const Horario &horario) {
    Apresentacao::horario = horario;
}

inline const Preco &Apresentacao::getPreco() const {
    return preco;
}

inline void Apresentacao::setPreco(const Preco &preco) {
    Apresentacao::preco = preco;
}

inline const NumeroDeSala &Apresentacao::getNumeroDeSala() const {
    return numeroDeSala;
}

inline void Apresentacao::setNumeroDeSala(const NumeroDeSala &numeroDeSala) {
    Apresentacao::numeroDeSala = numeroDeSala;
}

inline const Disponibilidade &Apresentacao::getDisponibilidade() const {
    return disponibilidade;
}

inline void Apresentacao::setDisponibilidade(const Disponibilidade &disponibilidade) {
    Apresentacao::disponibilidade = disponibilidade;
}

// Evento

inline const CodigoDeIngresso &Ingresso::getCodigo() const {
    return codigo;
}

inline void Ingresso::setCodigo(const CodigoDeIngresso &codigo) {
    Ingresso::codigo = codigo;
}

// Cartao de credito

inline const NumeroDeCartaoDeCredito &CartaoDeCredito::getNumero() const {
    return numero;
}

inline void CartaoDeCredito::setNumero(const NumeroDeCartaoDeCredito &numero) {
    CartaoDeCredito::numero = numero;
}

inline const CodigoDeSeguranca &CartaoDeCredito::getCodigoDeSeguranca() const {
    return codigoDeSeguranca;
}

inline void CartaoDeCredito::setCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca) {
    CartaoDeCredito::codigoDeSeguranca = codigoDeSeguranca;
}

inline const DataDeValidade &CartaoDeCredito::getDataDeValidade() const {
    return dataDeValidade;
}

inline void CartaoDeCredito::setDataDeValidade(const DataDeValidade &dataDeValidade) {
    CartaoDeCredito::dataDeValidade = dataDeValidade;
}

#endif //TRABALHOTP1_ENTIDADES_H
