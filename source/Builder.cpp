//
// Created by pedro on 03/06/19.
//

#include "include/Builder.h"

void Builder::build(Controladora* controladora) {
    // Abrindo a conexão com o database

    // Instanciando as interfaces de serviço
    ISAutenticacao* modelAutenticao = new ModelAutenticacao();
    ISUsuario* modelUsuario = new ModelUsuario();
    ISEventos* modelEventos = new ModelEventos();
    ISVendas* modelVendas = new ModelVendas();

    // Intanciando as interfaces de apresentação
    IAAutenticacao *viewAutenticacao = new class viewAutenticacao();
    IAUsuario *viewUsuario  = new class viewUsuario();
    IAEventos *viewEventos = new class viewEventos();
    IAVendas *viewsVendas = new class viewVendas();

    // Setando as interfaces de serviço nas apresentações da controladora
    viewAutenticacao->setModelAutenticacao(modelAutenticao);
    viewUsuario->setModelUsuario(modelUsuario);
    viewEventos->setModelEventos(modelEventos);
    viewsVendas->setModelVendas(modelVendas);


    // Setando as interfaces de apresentação
    controladora->setViewAutenticacao(viewAutenticacao);
    controladora->setViewUsuario(viewUsuario);
    controladora->setViewEventos(viewEventos);
    controladora->setViewVendas(viewsVendas);


}
