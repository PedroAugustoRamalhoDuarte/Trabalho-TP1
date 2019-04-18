//
// Created by pedro on 16/04/19.
//

#include "../lib/catch.hpp"
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
    Evento evento;
    SECTION("Teste Set e Get codigo"){
        CodigoDeEvento codigoDeEvento;
        string codigoValido = "456";
        codigoDeEvento.setValor(codigoValido);
        evento.setCodigo(codigoDeEvento);
        REQUIRE(evento.getCodigo().getValor() == codigoValido);

    }

    SECTION("Teste Set e Get nome"){
        NomeDeEvento nomeDeEvento;
        string nomeValido = "Computaiada";
        nomeDeEvento.setValor(nomeValido);
        evento.setNome(nomeDeEvento);
        REQUIRE(evento.getNome().getValor() == nomeValido);
    }

    SECTION("Teste Set e Get cidade"){
        Cidade cidade;
        string cidadeValida = "Brasilia";
        cidade.setValor(cidadeValida);
        evento.setCidade(cidade);
        REQUIRE(evento.getCidade().getValor() == cidadeValida);
    }

    SECTION("Teste Set e Get estado"){
        Estado estado;
        string estadoValido = "RN";
        estado.setValor(estadoValido);
        evento.setEstado(estado);
        REQUIRE(evento.getEstado().getValor() == estadoValido);
    }

    SECTION("Teste Set e Get Classe"){
        ClasseDeEvento classeDeEvento;
        string classeValida = "2";
        classeDeEvento.setValor(classeValida);
        evento.setClasse(classeDeEvento);
        REQUIRE(evento.getClasse().getValor() == classeValida);
    }

    SECTION("Teste Set e Get Faixa"){
        FaixaEtaria faixaEtaria;
        string faixaValida = "L";
        faixaEtaria.setValor(faixaValida);
        evento.setFaixa(faixaEtaria);
        REQUIRE(evento.getFaixa().getValor() == faixaValida);
    }
}

TEST_CASE("Teste Apresentacao") {
    Apresentacao apresentacao;
    SECTION("Teste Set e Get codigo"){
        CodigoDeApresentacao codigoDeApresentacao;
        string codigoValido = "6532";
        codigoDeApresentacao.setValor(codigoValido);
        apresentacao.setCodigo(codigoDeApresentacao);
        REQUIRE(apresentacao.getCodigo().getValor() == codigoValido);

    }

    SECTION("Teste Set e Get data"){
        Data data;
        string dataValida = "23/12/36";
        data.setValor(dataValida);
        apresentacao.setData(data);
        REQUIRE(apresentacao.getData().getValor() == dataValida);
    }

    SECTION("Teste Set e Get horario"){
        Horario horario;
        string horarioValido = "10:15";
        horario.setValor(horarioValido);
        apresentacao.setHorario(horario);
        REQUIRE(apresentacao.getHorario().getValor() == horarioValido);
    }

    SECTION("Teste Set e Get preco"){
        Preco preco;
        string precoValido = "500";
        preco.setValor(precoValido);
        apresentacao.setPreco(preco);
        REQUIRE(apresentacao.getPreco().getValor() == precoValido);
    }

    SECTION("Teste Set e Get numeroDeSala"){
        NumeroDeSala numeroDeSala;
        string numeroDeSalaValido = "6";
        numeroDeSala.setValor(numeroDeSalaValido);
        apresentacao.setNumeroDeSala(numeroDeSala);
        REQUIRE(apresentacao.getNumeroDeSala().getValor() == numeroDeSalaValido);
    }
    
    SECTION("Teste Set e Get Disponibilidade"){
        Disponibilidade disponibilidade;
        string disponibilidadeValida = "100";
        disponibilidade.setValor(disponibilidadeValida);
        apresentacao.setDisponibilidade(disponibilidade);
        REQUIRE(apresentacao.getDisponibilidade().getValor() == disponibilidadeValida);
    }
}

TEST_CASE("Teste Ingresso") {
    Ingresso ingresso;
    
    SECTION("Teste Set e Get codigo"){
        CodigoDeIngresso codigoDeIngresso;
        string codigoValido = "54623";
        codigoDeIngresso.setValor(codigoValido);
        ingresso.setCodigo(codigoDeIngresso);
        REQUIRE(ingresso.getCodigo().getValor() == codigoValido);
    }
}

TEST_CASE("Teste Cartao de Credito") {
    CartaoDeCredito cartao;

    SECTION("Teste Set e Get numero"){
        NumeroDeCartaoDeCredito numero;
        string numeroValido = "4984088007587535";
        numero.setValor(numeroValido);
        cartao.setNumero(numero);
        REQUIRE(cartao.getNumero().getValor() == numeroValido);
    }
    
    SECTION("Teste Set e Get codigoDeSeguranca"){
        CodigoDeSeguranca codigoDeSeguranca;
        string codigoValido = "834";
        codigoDeSeguranca.setValor(codigoValido);
        cartao.setCodigoDeSeguranca(codigoDeSeguranca);
        REQUIRE(cartao.getCodigoDeSeguranca().getValor() == codigoValido);
    }
    
    SECTION("Teste Set e Get DataDeValidade"){
        DataDeValidade dataDeValidade;
        string dataDeValidadeValida = "03/21";
        dataDeValidade.setValor(dataDeValidadeValida);
        cartao.setDataDeValidade(dataDeValidade);
        REQUIRE(cartao.getDataDeValidade().getValor() == dataDeValidadeValida);
    }
}