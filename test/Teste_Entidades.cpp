//
// Created by pedro on 16/04/19.
//

#include "../include/catch.hpp"
#include "../include/Entidades.h"

TEST_CASE("Teste Usuario") {
    Usuario user;

    SECTION("Teste Set e Get CPF") {
        CPF cpf;
        string cpfValido = "088.106.744-05";
        cpf.setValor(cpfValido);
        user.setCpf(cpf);
        REQUIRE(user.getCpf().getValor() == cpfValido);
    }

    SECTION("Teste Set e Get Senha") {
        Senha senha;
        string senhaValida = "AC4bde";
        senha.setValor(senhaValida);
        user.setSenha(senha);
        REQUIRE(user.getSenha().getValor() == senhaValida);
    }
}

TEST_CASE("Teste Evento") {
}

TEST_CASE("Teste Apresentacao") {
}

TEST_CASE("Teste Ingresso") {
}

TEST_CASE("Teste Cartao de Credito") {
}