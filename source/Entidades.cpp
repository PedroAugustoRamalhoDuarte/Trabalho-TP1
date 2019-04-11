#include "../include/Entidades.h"

//-----------------------------------------------------
//-------------------------CPF-------------------------
//-----------------------------------------------------

const CPF &Usuario::getCpf() const {
    return cpf;
}

void Usuario::setCpf(const CPF &cpf) {
    Usuario::cpf = cpf;
}

const Senha &Usuario::getSenha() const {
    return senha;
}

void Usuario::setSenha(const Senha &senha) {
    Usuario::senha = senha;
}

Usuario::Usuario(const CPF &cpf, const Senha &senha) {
    this->cpf = cpf;
    this->senha = senha;
}

//-----------------------------------------------------
//-----------------------Evento------------------------
//-----------------------------------------------------

const CodigoDeEvento &Evento::getCodigoDeEvento() const {
    return codigoDeEvento;
}

void Evento::setCodigoDeEvento(const CodigoDeEvento &codigoDeEvento) {
    Evento::codigoDeEvento = codigoDeEvento;
}

const NomeDeEvento &Evento::getNomeDeEvento() const {
    return nomeDeEvento;
}

void Evento::setNomeDeEvento(const NomeDeEvento &nomeDeEvento) {
    Evento::nomeDeEvento = nomeDeEvento;
}

const Cidade &Evento::getCidade() const {
    return cidade;
}

void Evento::setCidade(const Cidade &cidade) {
    Evento::cidade = cidade;
}

const Estado &Evento::getEstado() const {
    return estado;
}

void Evento::setEstado(const Estado &estado) {
    Evento::estado = estado;
}

const ClasseDeEvento &Evento::getClasseDeEvento() const {
    return classeDeEvento;
}

void Evento::setClasseDeEvento(const ClasseDeEvento &classeDeEvento) {
    Evento::classeDeEvento = classeDeEvento;
}

const FaixaEtaria &Evento::getFaixaEtaria() const {
    return faixaEtaria;
}

void Evento::setFaixaEtaria(const FaixaEtaria &faixaEtaria) {
    Evento::faixaEtaria = faixaEtaria;
}

//-----------------------------------------------------
//--------------------Apresentação---------------------
//-----------------------------------------------------

const CodigoDeApresentacao &Apresentacao::getCodigoDeApresentacao() const {
    return codigoDeApresentacao;
}

void Apresentacao::setCodigoDeApresentacao(const CodigoDeApresentacao &codigoDeApresentacao) {
    Apresentacao::codigoDeApresentacao = codigoDeApresentacao;
}

const Data &Apresentacao::getData() const {
    return data;
}

void Apresentacao::setData(const Data &data) {
    Apresentacao::data = data;
}

const Horario &Apresentacao::getHorario() const {
    return horario;
}

void Apresentacao::setHorario(const Horario &horario) {
    Apresentacao::horario = horario;
}

const Preco &Apresentacao::getPreco() const {
    return preco;
}

void Apresentacao::setPreco(const Preco &preco) {
    Apresentacao::preco = preco;
}

const NumeroDeSala &Apresentacao::getNumeroDeSala() const {
    return numeroDeSala;
}

void Apresentacao::setNumeroDeSala(const NumeroDeSala &numeroDeSala) {
    Apresentacao::numeroDeSala = numeroDeSala;
}

const Disponibilidade &Apresentacao::getDisponibilidade() const {
    return disponibilidade;
}

void Apresentacao::setDisponibilidade(const Disponibilidade &disponibilidade) {
    Apresentacao::disponibilidade = disponibilidade;
}

//-----------------------------------------------------
//----------------------Ingresso-----------------------
//-----------------------------------------------------

const CodigoDeIngresso &Ingresso::getCodigoDeIngresso() const {
    return codigoDeIngresso;
}

void Ingresso::setCodigoDeIngresso(const CodigoDeIngresso &codigoDeIngresso) {
    Ingresso::codigoDeIngresso = codigoDeIngresso;
}

//-----------------------------------------------------
//-----------------CartãoDeCrédito---------------------
//-----------------------------------------------------

const NumeroDeCartaoDeCredito &CartaoDeCredito::getNumeroDeCartaoDeCredito() const {
    return numeroDeCartaoDeCredito;
}

void CartaoDeCredito::setNumeroDeCartaoDeCredito(const NumeroDeCartaoDeCredito &numeroDeCartaoDeCredito) {
    CartaoDeCredito::numeroDeCartaoDeCredito = numeroDeCartaoDeCredito;
}

const CodigoDeSeguranca &CartaoDeCredito::getCodigoDeSeguranca() const {
    return codigoDeSeguranca;
}

void CartaoDeCredito::setCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca) {
    CartaoDeCredito::codigoDeSeguranca = codigoDeSeguranca;
}

const DataDeValidade &CartaoDeCredito::getDataDeValidade() const {
    return dataDeValidade;
}

void CartaoDeCredito::setDataDeValidade(const DataDeValidade &dataDeValidade) {
    CartaoDeCredito::dataDeValidade = dataDeValidade;
}
