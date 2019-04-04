//
// Created by waliffcordeiro on 03/04/19.
//

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/Dominios.h"

TEST_CASE("Teste CPF"){
    CPF cpf;

    SECTION("CPF invalido"){
        string cpfInvalido = "088.106.744-01";
        CHECK_THROWS(cpf.setValor(cpfInvalido));
    }

    SECTION("CPF valido"){
        string cpfValido = "088.106.744-05";
        REQUIRE_NOTHROW(cpf.setValor(cpfValido));
        CHECK(cpf.getValor() ==  cpfValido);
    }

}


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