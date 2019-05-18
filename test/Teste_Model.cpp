//
// Created by pedro on 18/05/19.
//

#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../include/Model.h"

TEST_CASE("Teste das Models") {
    Model *model = new Model();
    model->criarTabelas();
    delete model;

    SECTION("Autenticacao") {
        // Cadastrando Usuario
        ModelUsuario *modelUsuario = new ModelUsuario();
        CPF cpf;
        Senha senha;
        NumeroDeCartaoDeCredito numero;
        CodigoDeSeguranca codigo;
        DataDeValidade data;
        cpf.setValor("105.214.720-83");
        senha.setValor("Abc9827");
        numero.setValor("5555666677778884");
        codigo.setValor("123");
        data.setValor("10/22");
        Usuario *user = new Usuario(cpf, senha);
        CartaoDeCredito *cartaoDeCredito =  new CartaoDeCredito(numero, codigo, data);
        modelUsuario->cadastrarUsuario(*user, *cartaoDeCredito);
        delete modelUsuario;

        // Autenticando Certo
        ModelAutenticacao *modelAutenticacao = new ModelAutenticacao();
        REQUIRE(modelAutenticacao->autenticar(cpf, senha) == true);
        delete modelAutenticacao;

        // Excluindo Usuario
        modelUsuario = new ModelUsuario();
        modelUsuario->excluirUsuario(cpf);
        delete modelUsuario;

        // Autenticando para falhar
        modelAutenticacao = new ModelAutenticacao;
        REQUIRE(modelAutenticacao->autenticar(cpf, senha) == false);
        delete modelAutenticacao;
    }
}