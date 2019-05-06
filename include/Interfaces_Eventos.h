//
// Created by pedro on 06/05/19.
//

#ifndef TRABALHOTP1_INTERFACES_EVENTOS_H
#define TRABALHOTP1_INTERFACES_EVENTOS_H

#include "Dominios.h"
#include "Entidades.h"

class IAEventos {
public:
    virtual void executar() = 0;
};

class ISEventos {
public:
    virtual bool criarEvento(CPF cpf,Evento evento,Apresentacao* lista) = 0;
    virtual bool alterarEvento(CPF cpf, Evento evento) = 0;
    virtual bool descadastrarEvento(CPF, Evento) = 0;
    virtual bool pesquisarEventos(Evento&, Data dataInicio, Data dataTermino, Cidade cidade, Estado estado) = 0;
};
#endif //TRABALHOTP1_INTERFACES_EVENTOS_H
