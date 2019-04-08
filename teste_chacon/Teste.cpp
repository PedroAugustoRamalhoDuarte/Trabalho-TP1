//
// Created by waliffcordeiro on 03/04/19.
//

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/Dominios.h"

TEST_CASE("Teste NumeroDeCartao"){
    NumeroDeCartaoDeCredito numeroDeCartaoDeCredito;

    SECTION("Numero invalido"){
        string NumeroInvalido = "4984088007587532";
        CHECK_THROWS(numeroDeCartaoDeCredito.setValor(NumeroInvalido));
    }

    SECTION("Numero valido"){
        string NumeroValido = "4984088007587535";
        REQUIRE_NOTHROW(numeroDeCartaoDeCredito.setValor(NumeroValido));
        CHECK(numeroDeCartaoDeCredito.getValor() ==  NumeroValido);
    }


}

TEST_CASE("Teste CodigoDeEvento") {
    CodigoDeEvento codigoDeEvento;

    SECTION("Codigo Invalido") {
        string codigoInvalido = "22";
        REQUIRE_THROWS(codigoDeEvento.setValor(codigoInvalido));
    }

    SECTION("Codigo valido"){
        string codigoValido = "123";
        REQUIRE_NOTHROW(codigoDeEvento.setValor(codigoValido));
        CHECK(codigoDeEvento.getValor() ==  codigoValido);
    }
}

TEST_CASE("Teste CodigoDeApresentacao") {
    CodigoDeApresentacao codigoDeApresentacao;

    SECTION("Codigo Invalido") {
        string codigoInvalido = "22";
        string codigoInvalidoLetra = "AAAA";
        REQUIRE_THROWS(codigoDeApresentacao.setValor(codigoInvalido));
        REQUIRE_THROWS(codigoDeApresentacao.setValor(codigoInvalidoLetra));
    }

    SECTION("Codigo valido"){
        string codigoValido = "1234";
        REQUIRE_NOTHROW(codigoDeApresentacao.setValor(codigoValido));
        CHECK(codigoDeApresentacao.getValor() ==  codigoValido);
    }
}

TEST_CASE("Teste CodigoDeIngresso") {
    CodigoDeIngresso codigoDeIngresso;

    SECTION("Codigo Invalido") {
        string codigoInvalido = "22";
        REQUIRE_THROWS(codigoDeIngresso.setValor(codigoInvalido));
    }

    SECTION("Codigo valido"){
        string codigoValido = "12345";
        REQUIRE_NOTHROW(codigoDeIngresso.setValor(codigoValido));
        CHECK(codigoDeIngresso.getValor() ==  codigoValido);
    }
}

TEST_CASE("Teste CodigoDeSeguranca") {
    CodigoDeSeguranca codigoDeSeguranca;

    SECTION("Codigo Invalido") {
        string codigoInvalido = "22";
        REQUIRE_THROWS(codigoDeSeguranca.setValor(codigoInvalido));
    }

    SECTION("Codigo valido"){
        string codigoValido = "123";
        REQUIRE_NOTHROW(codigoDeSeguranca.setValor(codigoValido));
        CHECK(codigoDeSeguranca.getValor() ==  codigoValido);
    }
}


TEST_CASE("Teste Classe De Evento") {
    ClasseDeEvento classeDeEvento;

    SECTION("Classe Invalida") {
        string classeInvalida = "5";
        REQUIRE_THROWS(classeDeEvento.setValor(classeInvalida));
    }

    SECTION("Classe valida"){
        string classeValida = "1";
        REQUIRE_NOTHROW(classeDeEvento.setValor(classeValida));
        CHECK(classeDeEvento.getValor() ==  classeValida);
    }
}

TEST_CASE("Teste Numero de Sala") {
    NumeroDeSala numeroDeSala;

    SECTION("Numero Invalido") {
        string numeroInvalido = "34";
        REQUIRE_THROWS(numeroDeSala.setValor(numeroInvalido));
    }

    SECTION("Numero valido"){
        string numeroValido = "3";
        REQUIRE_NOTHROW(numeroDeSala.setValor(numeroValido));
        CHECK(numeroDeSala.getValor() ==  numeroValido);
    }
}

TEST_CASE("Teste Preco") {
    Preco preco;

    SECTION("Preco Invalido") {
        string precoInvalido = "1031,2";
        REQUIRE_THROWS(preco.setValor(precoInvalido));
    }

    SECTION("Preco valido"){
        string precoValido = "100,00";
        REQUIRE_NOTHROW(preco.setValor(precoValido));
        CHECK(preco.getValor() ==  precoValido);
    }
}

TEST_CASE("Senha") {
    Senha senha;

    SECTION("Senha Invalida:") {
        string senhaInvalida;
        senhaInvalida.resize(6);
        SECTION("Com numero diferente de digitos") {
            senhaInvalida = "1Aa45";
            REQUIRE_THROWS(senha.setValor(senhaInvalida));
        }
        SECTION("Com caracter repetido") {
            senhaInvalida = "12aB55";
            REQUIRE_THROWS(senha.setValor(senhaInvalida));
        }
        SECTION("Somente letra") {
            senhaInvalida = "AbCdEF";
            REQUIRE_THROWS(senha.setValor(senhaInvalida));
        }
        SECTION("Somente numero") {
            senhaInvalida = "123456";
            REQUIRE_THROWS(senha.setValor(senhaInvalida));
        }
        SECTION("Sem letras maisculas") {
            senhaInvalida = "12345a";
            REQUIRE_THROWS(senha.setValor(senhaInvalida));
        }
        SECTION("Sem letras minusculas") {
            senhaInvalida = "12345A";
            REQUIRE_THROWS(senha.setValor(senhaInvalida));
        }
    }

    SECTION("Senha Valida"){
        string senhaValida = "1234Ab";
        REQUIRE_NOTHROW(senha.setValor(senhaValida));
        CHECK(senha.getValor() == senhaValida);
    }
}

TEST_CASE("Cidade") {
    Cidade cidade;

    SECTION("Cidade Invalida"){
        string cidadeInvalida;
        cidadeInvalida.resize(15);
        SECTION("Com numero diferentes de digitos") {
            cidadeInvalida = "Campinas";
            REQUIRE_THROWS(cidade.setValor(cidadeInvalida));
        }
        SECTION("2 espacos seguidos") {
            cidadeInvalida = "Campinas  plkjg";
            REQUIRE_THROWS(cidade.setValor(cidadeInvalida));
        }
        SECTION("ponto precedido de espaco") {
            cidadeInvalida = "Campinas .plkjg";
            REQUIRE_THROWS(cidade.setValor(cidadeInvalida));
        }
    }

    SECTION("Cidade Valida"){
        string cidadeValida = "Campinas Grande";
        REQUIRE_NOTHROW(cidade.setValor(cidadeValida));
    }
}

TEST_CASE("Nome de evento") {
    NomeDeEvento nomeDeEvento;

    SECTION("Nome de evento valido"){
        string nomeInvalido;
        nomeInvalido.resize(20);
        SECTION("Com numero diferentes de digitos") {
            nomeInvalido = "Calangada";
            REQUIRE_THROWS(nomeDeEvento.setValor(nomeInvalido));
        }
        SECTION("2 espacos seguidos") {
            nomeInvalido = "Calangada  ";
            REQUIRE_THROWS(nomeDeEvento.setValor(nomeInvalido));
        }
        SECTION("sem letras") {
            nomeInvalido = "1 2312 312 312231232";
            REQUIRE_THROWS(nomeDeEvento.setValor(nomeInvalido));
        }
    }

    SECTION("Nome de evento Valido"){
        string nomeValido = "Calangada 14 Med UnB";
        REQUIRE_NOTHROW(nomeDeEvento.setValor(nomeValido));
    }
}

TEST_CASE("Teste CPF"){
    CPF cpf;

    SECTION("CPF invalido"){
        string cpfInvalido1 = "088.106.744-01", cpfInvalido2 = "03X.321.D34-53", cpfInvalido3 = "32451231234578";
        CHECK_THROWS(cpf.setValor(cpfInvalido1));
        CHECK_THROWS(cpf.setValor(cpfInvalido2));
        CHECK_THROWS(cpf.setValor(cpfInvalido3));
    }

    SECTION("CPF valido"){
        string cpfValido1 = "088.106.744-05", cpfValido2 = "498.633.310-07", cpfValido3 = "071.063.140-56";
        REQUIRE_NOTHROW(cpf.setValor(cpfValido1));
        CHECK(cpf.getValor() ==  cpfValido1);
        REQUIRE_NOTHROW(cpf.setValor(cpfValido2));
        CHECK(cpf.getValor() ==  cpfValido2);
        REQUIRE_NOTHROW(cpf.setValor(cpfValido2));
        CHECK(cpf.getValor() ==  cpfValido2);
    }

}

TEST_CASE("Teste FaixaEtaria") {
    FaixaEtaria faixaEtaria;

    SECTION("Faixa etaria valida") {
        string faixaValida1 = "L", faixaValida2 = "10";
        CHECK_NOTHROW(faixaEtaria.setValor(faixaValida1));
        CHECK_NOTHROW(faixaEtaria.setValor(faixaValida2));
    }
    SECTION("Faixa etaria invalida") {
        string faixaInvalida1 = "M", faixaInvalida2 = "13";
        CHECK_THROWS(faixaEtaria.setValor(faixaInvalida1));
        CHECK_THROWS(faixaEtaria.setValor(faixaInvalida2));
    }
}

TEST_CASE("Disponibilidade") {
    Disponibilidade disponibilidade;

    SECTION("Disponibilidade valida") {
        string disponibilidadeValida1 = "0", disponibilidadeValida2 = "120";
        CHECK_NOTHROW(disponibilidade.setValor(disponibilidadeValida1));
        CHECK_NOTHROW(disponibilidade.setValor(disponibilidadeValida2));
    }
    SECTION("Disponibilidade invalida") {
        string disponibilidadeInvalida1 = "-1", disponibilidadeInvalida2 = "251", disponibilidadeInvalida3 = "AA";
        CHECK_THROWS(disponibilidade.setValor(disponibilidadeInvalida1));
        CHECK_THROWS(disponibilidade.setValor(disponibilidadeInvalida2));
        CHECK_THROWS(disponibilidade.setValor(disponibilidadeInvalida3));
    }
}

TEST_CASE("Estado") {
    Estado estado;

    SECTION("Estado valido") {
        string estadoValido1 = "GO", estadoValido2 = "BA", estadoValido3 = "DF";
        CHECK_NOTHROW(estado.setValor(estadoValido1));
        CHECK_NOTHROW(estado.setValor(estadoValido2));
        CHECK_NOTHROW(estado.setValor(estadoValido3));
    }
    SECTION("Estado invalido") {
        string estadoInvalido1 = "XX", estadoInvalido2 = "XY", estadoInvalido3 = "3";
        CHECK_THROWS(estado.setValor(estadoInvalido1));
        CHECK_THROWS(estado.setValor(estadoInvalido2));
        CHECK_THROWS(estado.setValor(estadoInvalido3));
    }
}

TEST_CASE("Data de Validade") {
    DataDeValidade data;

    SECTION("Data Valida") {
        string dataValida1 = "12/98", dataValida2 = "01/00", dataValida3 = "07/99";
        CHECK_NOTHROW(data.setValor(dataValida1));
        CHECK_NOTHROW(data.setValor(dataValida2));
        CHECK_NOTHROW(data.setValor(dataValida3));
    }
    SECTION("Data Invalida") {
        string dataInvalida1 = "1298", dataInvalida2 = "12-98", dataInvalida3 = "12/100", dataInvalida4 = "-12/00";
        CHECK_THROWS(data.setValor(dataInvalida1));
        CHECK_THROWS(data.setValor(dataInvalida2));
        CHECK_THROWS(data.setValor(dataInvalida3));
        CHECK_THROWS(data.setValor(dataInvalida4));
    }
}

TEST_CASE("Horario") {
    Horario horario;

    SECTION("Horario valido") {
        string horarioValido1 = "07:00", horarioValido2 = "07:45", horarioValido3 = "22:15";
        CHECK_NOTHROW(horario.setValor(horarioValido1));
        CHECK_NOTHROW(horario.setValor(horarioValido2));
        CHECK_NOTHROW(horario.setValor(horarioValido3));
    }
    SECTION("Horario invalido") {
        string horarioInvalido1 = "06:45", horarioInvalido2 = "07:46", horarioInvalido3 = "23:45";
        CHECK_THROWS(horario.setValor(horarioInvalido1));
        CHECK_THROWS(horario.setValor(horarioInvalido2));
        CHECK_THROWS(horario.setValor(horarioInvalido3));
    }
}

TEST_CASE("Data") {
    Data data;

    SECTION("Data valida") {
        string dataValida1 = "29/02/40", dataValida2 = "28/02/99", dataValida3 = "30/02/99";
    }
    SECTION("Data invalida") {
        string dataInvalida1 = "29/02/41", dataInvalida2 = "33/05/98", dataInvalida3 = "2/12/28";
    }
}