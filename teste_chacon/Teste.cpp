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

    SECTION("CPF valido"){
        string cpfValido1 = "088.106.744-05", cpfValido2 = "498.633.310-07", cpfValido3 = "071.063.140-56";

        REQUIRE_NOTHROW(cpf.setValor(cpfValido1));
        REQUIRE(cpf.getValor() ==  cpfValido1);

        REQUIRE_NOTHROW(cpf.setValor(cpfValido2));
        REQUIRE(cpf.getValor() ==  cpfValido2);

        REQUIRE_NOTHROW(cpf.setValor(cpfValido2));
        REQUIRE(cpf.getValor() ==  cpfValido2);
    }

    SECTION("CPF invalido - digito verificador incoerente"){
        string cpfInvalido = "088.106.744-01", cpfValido;
        cpfValido = cpf.getValor();
        REQUIRE_THROWS(cpf.setValor(cpfInvalido));
        REQUIRE(cpfValido == cpf.getValor());
    }

    SECTION("CPF invalido - não é totalmente numérico") {
        string cpfInvalido = "03X.321.D34-53", cpfValido;
        REQUIRE_THROWS(cpf.setValor(cpfInvalido));
        REQUIRE(cpfValido == cpf.getValor());
    }

    SECTION("CPF invalido - sem os separadores") {
        string cpfInvalido = "32451231234578", cpfValido;
        REQUIRE_THROWS(cpf.setValor(cpfInvalido));
        REQUIRE(cpfValido == cpf.getValor());
    }

    SECTION("CPF invalido - mais caracteres que o permitido") {
        string cpfInvalido = "123.456.789-697", cpfValido;
        REQUIRE_THROWS(cpf.setValor(cpfInvalido));
        REQUIRE(cpfValido == cpf.getValor());
    }

    SECTION("CPF invalido - menos caracteres que o permitido") {
        string cpfInvalido = "123.456.789-6", cpfValido;
        REQUIRE_THROWS(cpf.setValor(cpfInvalido));
        REQUIRE(cpfValido == cpf.getValor());
    }
}

TEST_CASE("Teste FaixaEtaria") {
    FaixaEtaria faixaEtaria;

    SECTION("Faixa etaria valida") {
        string faixaValida1 = "L", faixaValida2 = "10";

        REQUIRE_NOTHROW(faixaEtaria.setValor(faixaValida1));
        REQUIRE(faixaEtaria.getValor() == faixaValida1);

        REQUIRE_NOTHROW(faixaEtaria.setValor(faixaValida2));
        REQUIRE(faixaEtaria.getValor() == faixaValida2);
    }
    SECTION("Faixa etaria invalida - caracter não permitido") {
        string faixaInvalida = "M", faixaValida;
        faixaValida = faixaEtaria.getValor();
        REQUIRE_THROWS(faixaEtaria.setValor(faixaInvalida));
        REQUIRE(faixaEtaria.getValor() == faixaValida);
    }
    SECTION("Faixa etaria invalida - valor não permitido") {
        string faixaInvalida = "13", faixaValida;
        faixaValida = faixaEtaria.getValor();
        REQUIRE_THROWS(faixaEtaria.setValor(faixaInvalida));
        REQUIRE(faixaEtaria.getValor() == faixaValida);
    }
}

TEST_CASE("Disponibilidade") {
    Disponibilidade disponibilidade;

    SECTION("Disponibilidade valida") {
        string disponibilidadeValida1 = "0", disponibilidadeValida2 = "120";

        REQUIRE_NOTHROW(disponibilidade.setValor(disponibilidadeValida1));
        REQUIRE(disponibilidade.getValor() == disponibilidadeValida1);

        REQUIRE_NOTHROW(disponibilidade.setValor(disponibilidadeValida2));
        REQUIRE(disponibilidade.getValor() == disponibilidadeValida2);
    }
    SECTION("Disponibilidade invalida - valor negativo") {
        string disponibilidadeInvalida = "-1", disponibilidadeValida;

        disponibilidadeValida = disponibilidade.getValor();
        REQUIRE_THROWS(disponibilidade.setValor(disponibilidadeInvalida));
        REQUIRE(disponibilidade.getValor() == disponibilidadeValida);
    }
    SECTION("Disponibilidade invalida - valor acima do permitido") {
        string disponibilidadeInvalida = "251", disponibilidadeValida;

        disponibilidadeValida = disponibilidade.getValor();
        REQUIRE_THROWS(disponibilidade.setValor(disponibilidadeInvalida));
        REQUIRE(disponibilidade.getValor() == disponibilidadeValida);
    }
    SECTION("Disponibilidade invalida - valor não numérico") {
        string disponibilidadeInvalida = "AA", disponibilidadeValida;

        disponibilidadeValida = disponibilidade.getValor();
        REQUIRE_THROWS(disponibilidade.setValor(disponibilidadeInvalida));
        REQUIRE(disponibilidade.getValor() == disponibilidadeValida);
    }
}

TEST_CASE("Estado") {
    Estado estado;

    SECTION("Estado valido") {
        string estadoValido1 = "GO", estadoValido2 = "BA", estadoValido3 = "DF";

        REQUIRE_NOTHROW(estado.setValor(estadoValido1));
        REQUIRE(estado.getValor() == estadoValido1);

        REQUIRE_NOTHROW(estado.setValor(estadoValido2));
        REQUIRE(estado.getValor() == estadoValido2);

        REQUIRE_NOTHROW(estado.setValor(estadoValido3));
        REQUIRE(estado.getValor() == estadoValido3);
    }
    SECTION("Estado invalido - não está entre os possíveis") {
        string estadoInvalido = "XX", estadoValido;

        estadoValido = estado.getValor();
        REQUIRE_THROWS(estado.setValor(estadoInvalido));
        REQUIRE(estado.getValor() == estadoValido);
    }
    SECTION("Estado invalido - Estado numérico") {
        string estadoInvalido = "3", estadoValido;

        estadoValido = estado.getValor();
        REQUIRE_THROWS(estado.setValor(estadoInvalido));
        REQUIRE(estado.getValor() == estadoValido);
    }
    SECTION("Estado invalido - Estado numérico com dois caracteres") {
        string estadoInvalido = "25", estadoValido;

        estadoValido = estado.getValor();
        REQUIRE_THROWS(estado.setValor(estadoInvalido));
        REQUIRE(estado.getValor() == estadoValido);
    }
}

TEST_CASE("Data de Validade") {
    DataDeValidade data;

    SECTION("Data Valida") {
        string dataValida1 = "12/98", dataValida2 = "01/00", dataValida3 = "07/99";

        REQUIRE_NOTHROW(data.setValor(dataValida1));
        REQUIRE(data.getValor() == dataValida1);

        REQUIRE_NOTHROW(data.setValor(dataValida2));
        REQUIRE(data.getValor() == dataValida2);

        REQUIRE_NOTHROW(data.setValor(dataValida3));
        REQUIRE(data.getValor() == dataValida3);
    }

    SECTION("Data Invalida - sem separador e tamanho inadequado") {
        string dataInvalida = "1298", dataValida;

        dataValida = data.getValor();
        REQUIRE_THROWS(data.setValor(dataInvalida));
        REQUIRE(data.getValor() == dataValida);
    }

    SECTION("Data Invalida - tamanho inadequado") {
        string dataInvalida = "12/980", dataValida;

        dataValida = data.getValor();
        REQUIRE_THROWS(data.setValor(dataInvalida));
        REQUIRE(data.getValor() == dataValida);
    }

    SECTION("Data Invalida - valor negativo") {
        string dataInvalida = "-12/55", dataValida;

        dataValida = data.getValor();
        REQUIRE_THROWS(data.setValor(dataInvalida));
        REQUIRE(data.getValor() == dataValida);
    }

    SECTION("Data Invalida - valor de mês acima do permitido") {
        string dataInvalida = "13/50", dataValida;

        dataValida = data.getValor();
        REQUIRE_THROWS(data.setValor(dataInvalida));
        REQUIRE(data.getValor() == dataValida);
    }
}

TEST_CASE("Horario") {
    Horario horario;

    SECTION("Horario valido") {
        string horarioValido1 = "07:00", horarioValido2 = "07:45", horarioValido3 = "22:15";

        REQUIRE_NOTHROW(horario.setValor(horarioValido1));
        REQUIRE(horario.getValor() == horarioValido1);

        REQUIRE_NOTHROW(horario.setValor(horarioValido2));
        REQUIRE(horario.getValor() == horarioValido2);

        REQUIRE_NOTHROW(horario.setValor(horarioValido3));
        REQUIRE(horario.getValor() == horarioValido3);
    }

    SECTION("Horario invalido - horario abaixo do permitido") {
        string horarioInvalido = "06:45", horarioValido;
        horarioValido = horario.getValor();
        REQUIRE_THROWS(horario.setValor(horarioInvalido));
        REQUIRE(horario.getValor() == horarioValido);
    }

    SECTION("Horario invalido - horario acima do permitido") {
        string horarioInvalido = "23:45", horarioValido;
        horarioValido = horario.getValor();
        REQUIRE_THROWS(horario.setValor(horarioInvalido));
        REQUIRE(horario.getValor() == horarioValido);
    }

    SECTION("Horario invalido - minuto não permitido") {
        string horarioInvalido = "12:44", horarioValido;
        horarioValido = horario.getValor();
        REQUIRE_THROWS(horario.setValor(horarioInvalido));
        REQUIRE(horario.getValor() == horarioValido);
    }

    SECTION("Horario invalido - formato invalido") {
        string horarioInvalido = "12/44", horarioValido;
        horarioValido = horario.getValor();
        REQUIRE_THROWS(horario.setValor(horarioInvalido));
        REQUIRE(horario.getValor() == horarioValido);
    }

    SECTION("Horario invalido - tamanho invalido") {
        string horarioInvalido = "12:344", horarioValido;
        horarioValido = horario.getValor();
        REQUIRE_THROWS(horario.setValor(horarioInvalido));
        REQUIRE(horario.getValor() == horarioValido);
    }
}

TEST_CASE("Data") {
    Data data;

    SECTION("Data valida") {
        string dataValida1 = "29/02/04", dataValida2 = "28/05/99", dataValida3 = "25/02/99", teste;

        REQUIRE_NOTHROW(data.setValor(dataValida1));
        REQUIRE(data.getValor() == dataValida1);

        REQUIRE_NOTHROW(data.setValor(dataValida2));;
        REQUIRE(data.getValor() == dataValida2);

        REQUIRE_NOTHROW(data.setValor(dataValida3));
        REQUIRE(data.getValor() == dataValida3);
    }

    SECTION("Data invalida - ano não bissexto, não permite dia 29 em fevereiro") {
        string dataInvalida = "29/02/41", dataValida;

        dataValida = data.getValor();
        CHECK_THROWS(data.setValor(dataInvalida));
        CHECK(data.getValor() == dataValida);
    }

    SECTION("Data invalida - dia invalido") {
        string dataInvalida = "33/03/41", dataValida;

        dataValida = data.getValor();
        CHECK_THROWS(data.setValor(dataInvalida));
        CHECK(data.getValor() == dataValida);
    }

    SECTION("Data invalida - mês invalido") {
        string dataInvalida = "25/13/41", dataValida;

        dataValida = data.getValor();
        CHECK_THROWS(data.setValor(dataInvalida));
        CHECK(data.getValor() == dataValida);
    }

    SECTION("Data invalida - formato invalido, separadores inadequados") {
        string dataInvalida = "25-12-41", dataValida;

        dataValida = data.getValor();
        CHECK_THROWS(data.setValor(dataInvalida));
        CHECK(data.getValor() == dataValida);
    }

    SECTION("Data invalida - formato e tamanho invalidos") {
        string dataInvalida = "25512541", dataValida;

        dataValida = data.getValor();
        CHECK_THROWS(data.setValor(dataInvalida));
        CHECK(data.getValor() == dataValida);
    }
}