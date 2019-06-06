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
    //ISVendas* modelVendas = new ModelVendas();

    // Intanciando as interfaces de apresentação
    //IAVendas *viewsVendas = new class viewVendas() ;
    IAEventos *viewEventos = new class viewEventos();
    IAAutenticacao *viewAutenticacao = new class viewAutenticacao();
    IAUsuario *viewUsuario  = new class viewUsuario();

    // Setando as interfaces de serviço nas apresentações da controladora
    viewEventos->setModelEventos(modelEventos);
    viewAutenticacao->setModelAutenticacao(modelAutenticao);
    //viewsVendas->setModelVendas(modelVendas);
    viewUsuario->setModelUsuario(modelUsuario);

    // Setando as interfaces de apresentação
    controladora->setViewAutenticacao(viewAutenticacao);
    controladora->setViewEventos(viewEventos);
    controladora->setViewUsuario(viewUsuario);
    //controladora->setViewVendas(viewsVendas);


}
