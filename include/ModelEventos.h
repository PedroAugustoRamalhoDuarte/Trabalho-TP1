//
// Created by pedro on 13/06/19.
//

#ifndef TRABALHOTP1_MODELEVENTOS_H
#define TRABALHOTP1_MODELEVENTOS_H


#include "Model.h"

class ModelEventos : public Model, public ISEventos {
private:
    const static int LIMITE_EVENTOS = 10;
    const static int LIMITE_APRESENTACAO = 10;

    // Retorna True caso não possa mais criar eventos
    bool isLimiteEventos(CPF cpf);

    void adicionarApresentacoes(CodigoDeEvento codigo, list<Apresentacao> listaApresentacao);

    bool verificaDataApresentacao(list<Evento> &listaEventos, Data dataInicio, Data dataTermino);

    bool isUsuarioDono(CPF cpf,CodigoDeEvento codigo);

    bool jaVendeu(CodigoDeEvento codigo);

public:
    ModelEventos();

    void meusEventos(list<Evento> &listaEventos, CPF cpf) override;

    bool criarEvento(CPF cpf, Evento evento, list<Apresentacao> listaApresentacao) override;

    void alterarEvento(CPF cpf, Evento evento) override;

    bool descadastrarEvento(CPF cpf, CodigoDeEvento codigo) override;

    void pesquisarEventos(list<Evento> &listaEventos, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) override;

    void mostrarApresentacao(list<Apresentacao> &listaApresentacao, CodigoDeEvento codigoDeEvento) override;
};

#endif //TRABALHOTP1_MODELEVENTOS_H
