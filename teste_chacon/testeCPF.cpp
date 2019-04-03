//
// Created by waliffcordeiro on 03/04/19.
//

#include "../include/catch.hpp"
#include "../include/Dominios.h"

TEST_CASE("TESTEZINHO"){
    CPF cpf;
    CHECK_THROWS(cpf.setValor("088.106.744-05"));

}