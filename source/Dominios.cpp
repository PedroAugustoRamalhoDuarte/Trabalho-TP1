// "Copyright [2019] <Pedro e Waliff>"
#include "../include/Dominios.h"


/* Construtores das Classes de Codigo*/
CodigoDeEvento::CodigoDeEvento() {
    this->TAMANHO_CODIGO = TAMANHO_CODIGO_EVENTO;
}

CodigoDeApresentacao::CodigoDeApresentacao() {
    this->TAMANHO_CODIGO = TAMANHO_CODIGO_APRESENTACAO;
}

CodigoDeIngresso::CodigoDeIngresso() {
    this->TAMANHO_CODIGO = TAMANHO_CODIGO_INGRESSO;
}

CodigoDeSeguranca::CodigoDeSeguranca() {
    this->TAMANHO_CODIGO = TAMANHO_CODIGO_SEGURANCA;
}

/* Metodos de validacao*/
void Codigo::validar(string entrada) {
    if (entrada.size() == this->TAMANHO_CODIGO) {
        for (char c : entrada) {
            if (!isdigit(c)) {
                throw invalid_argument("CODIGO INVALIDO");
            }
        }
    } else {
        throw invalid_argument("CODIGO INVALIDO");
    }
}

void NomeDeEvento::validar(string entrada) {
    // Variavel para checar se o caracter anterior e espaco
    bool isAnteriorEspaco = false, contemLetra = false;
    if (entrada.size() > TAMANHO_NOME_EVENTO) {
        throw invalid_argument("Formato Invalido");
    } else {
        for (char c : entrada) {
            // Se for um caracter valido
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
                || c == ' ' ||   (c >= '0' && c <= '9')) {
                // Se o caracter for espaco e o anterior tambem(2 espacos seguidos)
                if (isAnteriorEspaco && c == ' ')
                    throw invalid_argument("2 espacos seguidos");

                // Se o caracter for uma letra
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    contemLetra = true;
                }

                // Checa se o caracter atual e espaco
                isAnteriorEspaco = c == ' ';

            } else {
                throw invalid_argument("Caracter nao compativel para Nome do evento");
            }
        }
    }
    // Se o nome do evento nao conter letra
    if (!contemLetra)
        throw invalid_argument("Nome do envento nao contem letra");
}

void Preco::validar(string entrada) {
    // Procura um ponto na entrada
    auto pos = entrada.find(".");
    auto virg = entrada.find(",");
    // Se achar um ponto
    if (pos != string::npos && virg != string::npos){
        // Separa do começo ate o ponto
        string primeiraParte = entrada.substr(0, pos);
        // Do ponto ate o final
        string segundaParte = entrada.substr(pos + 1, entrada.size() - pos);
        // Junta as duas partes
        entrada = primeiraParte + segundaParte;
    }
    double preco = stod(entrada);
    if (preco < 0 || preco > 1000) {
        throw invalid_argument("Preco Invalido");
    }
}

void NumeroDeSala::validar(string entrada) {
    int numeroDeSala = stoi(entrada);
    if ( 1 > numeroDeSala || numeroDeSala > 10 ) {
        throw invalid_argument("Numero de Sala Invalido");
    }
}

void Cidade::validar(string entrada) {
    // Variavel para checar se o caracter anterior e espaco
    bool isAnteriorEspaco = false, isAnteriorLetra = false;
    if (entrada.size() > TAMANHO_CIDADE || entrada == "") {
        throw invalid_argument("Formato Invalido");
    } else {
        for (char c : entrada) {
            // Se for um caracter valido
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.' || c == ' ') {
                // Se o caracter for espaco e o anterior tambem(2 espacos seguidos)
                if (isAnteriorEspaco && c == ' ')
                    throw invalid_argument("2 espacos seguidos");

                // Se o caracter for ponto e o anterior nao for letra
                if (!isAnteriorLetra && c == '.')
                    throw invalid_argument("Ponto nao precedido por letra");

                // Checa se o caracter atual e espaco
                isAnteriorEspaco = c == ' ';
                // Checa se o caracter atual e letra
                isAnteriorLetra = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
            } else {
                throw invalid_argument("Caracter nao compativel para Cidade");
            }
        }
    }
}

void ClasseDeEvento::validar(string entrada) {
    if ( entrada != "1" && entrada != "2" && entrada != "3" && entrada != "4")
        throw invalid_argument("ClasseDeEventoInvalida");
}

void Senha::validar(string entrada) {
    bool contemDigit = false, contemLetraMaiuscula = false, contemLetraMinuscula = false;
    // lista para verificao de caracteres repetidos
    list <char> listaChar;
    if (entrada.size() < TAMANHO_SENHA || entrada.size() > (2*TAMANHO_SENHA)) {
        throw invalid_argument("Formato Invalido de Senha");
    } else {
        // Se for no tamanho valido
        for (char c : entrada) {
            // Para cada char na string de entrada
            // Se for inteiro
            if (c >='0' && c <='9') {
                contemDigit = true;
            } else if (c >= 'a' && c <= 'z') {
                // Se for letra minuscula
                contemLetraMinuscula = true;
            } else if (c >= 'A' && c <= 'Z') {
                // Se for letra maisculas
               contemLetraMaiuscula = true;
            } else {
                // Se nao for alphanumeric
                throw invalid_argument("Digito Invalido");
            }

            // Verifica se há char repetidos
            for (char caracterLista : listaChar) {
                if (c == caracterLista)
                    throw invalid_argument("Nao pode conter digitos repetidos");
            }

            // Adiciona o char na lista de Char anteriomente o
            listaChar.push_back(c);
        }
    }

    if (!contemDigit || !contemLetraMaiuscula ||!contemLetraMinuscula)
        throw invalid_argument("Senha muito facil");
}

void NumeroDeCartaoDeCredito::validar(string entrada) {
    int digitoVerificacao = 0, auxDigito = 0, somaDigitos = 0;
    if (entrada.size() != TAMANHO_NUMERODECARTAO) {
        throw invalid_argument("Tamanho do Cartão Invalido");
    } else {
        // Atribui ao digitoVerificacao o ultimo numero do cartao
        digitoVerificacao = entrada[TAMANHO_NUMERODECARTAO - 1] - '0';
        for (int i=0; i < TAMANHO_NUMERODECARTAO - 1 ; i++) {
            // Quando estiver em uma posicao par
            if (i % 2 == 0) {
                // Multiplica o digito por 2
                auxDigito = (entrada[i] - '0') * 2;
                // Se o digito multiplicado por 2 for maior que 9
                if (auxDigito >  9) {
                    // Soma os algarismos do digito multiplicado por 2
                    somaDigitos += auxDigito - 9;
                } else {
                    // Soma os digitos
                    somaDigitos += auxDigito;
                }
            } else {  // Quando estiver em posicao impar
                somaDigitos += entrada[i] - '0';
            }
        }

        if ((somaDigitos + digitoVerificacao) % 10 != 0) {
           throw invalid_argument("Numero Invalido Segundo o Algoritmo de Luhn");
        }
    }
}

void Data::validar(string entrada) {
    string dia, mes, ano;
    dia.resize(2); mes.resize(2); ano.resize(2);
    if (entrada.size() != TAMANHO_DATA) {
        throw invalid_argument("Tamanho de data invalido");
    } else if (!isdigit(entrada[0]) || !isdigit(entrada[1]) || !isdigit(entrada[3]) || !isdigit(entrada[4]) ||
              !isdigit(entrada[6]) || !isdigit(entrada[7]) || entrada[2] != '/' || entrada[5] != '/') {
        // Verificando se são valores numéricos e se as / estão nos lugares corretos
        throw invalid_argument("Formato de data invalido");
    }
    // Separando dia, mês e ano em variáveis auxiliares
    for (int i = 0; i < 8; i++) {
        if (i == 0 || i == 1) {
            dia[i] = entrada[i];
        }
        if (i == 3 || i == 4) {
            mes[i - 3] = entrada[i];
        }
        if (i == 6 || i == 7) {
            ano[i - 6] = entrada[i];
        }
    }
    if ((dia < "00" || dia > "31") || (mes < "00" || mes > "12") || (ano < "00" || ano > "99")) {
        throw invalid_argument("data invalida");
    }

    // Janeiro no máximo 29
    if (dia > "29" && mes == "02") {
        throw invalid_argument("Não pode ter fevereiro com dia maior que 29");
    } else if (dia <= "29" && mes == "02") {
        // Só é 29 se for ano bissexto
        if (dia == "29" && ((stoi(ano) % 4) != 0)) {
            throw invalid_argument("dia e 29 mas nao e ano bissexto");
        }
    }

    // Dia ate 30 mas nao são os meses de 30
    if ((dia <= "30") && (mes == "02" || mes == "04" || mes == "06" || mes == "09" || mes == "11")) {
    } else if ((dia <= "31") && (mes == "01" || mes == "03" || mes == "05" || mes == "07" || mes == "08"
    || mes == "10" || mes == "12")) {
    } else {
        throw invalid_argument("data invalida");
    }
}

void Horario::validar(string entrada) {
    string horas, minutos;
    horas.resize(2); minutos.resize(2);

    if (entrada.size() != 5) {
        throw invalid_argument("Tamanho invalido para horario");
    } else if (!isdigit(entrada[0]) || !isdigit(entrada[1]) || !isdigit(entrada[3]) || !isdigit(entrada[4])
              || entrada[2] != ':') {
        throw invalid_argument("Formato de horario errado");
    }
    for (int i = 0; i < 5; i++) {
        if (i == 0 || i == 1) {
            horas[i] = entrada[i];
        }
        // Atribuir nos dois primeiros espaços da string o ano
        if (i == 3 || i == 4) {
            minutos[i - 3] = entrada[i];
        }
    }
    if (horas < "07" || horas > "22") {
        throw invalid_argument("Horario invalido");
    }
    if (minutos != "00" && minutos != "15" && minutos != "30" && minutos != "45") {
        throw invalid_argument("Minutos invalido");
    }
}

void Estado::validar(string entrada) {
    if ((entrada != "AC") && (entrada != "AL") && (entrada != "AP") && (entrada != "AM") && (entrada != "BA") &&
       (entrada != "CE") && (entrada != "DF") && (entrada != "ES") && (entrada != "GO") && (entrada != "MA") &&
       (entrada != "MT") && (entrada != "MS") && (entrada != "MG") && (entrada != "PA") && (entrada != "PB") &&
       (entrada != "PR") && (entrada != "PE") && (entrada != "PI") && (entrada != "RJ") && (entrada != "RN") &&
       (entrada != "RS") && (entrada != "RO") && (entrada != "RR") && (entrada != "SC") && (entrada != "SP") &&
       (entrada != "SE") && (entrada != "TO")) {
        throw invalid_argument("valor de Estado invalido");
    }
}

void Disponibilidade::validar(string entrada) {
    // Verificando se a entrada é numérica
    for (char c : entrada) {
        if (!isdigit(c)) {
            throw invalid_argument("CODIGO INVALIDO");
        }
    }
    // Numero maior que o esperado e poderia dar erro no cast
    if ((entrada.size()) > 4)
        throw invalid_argument("Valor de disponibilidade invalido");

    if ((stoi(entrada) < 0 || (stoi(entrada) > 250))) {
        throw invalid_argument("Valor de disponibilidade invalido");
    }
}

void FaixaEtaria::validar(string entrada) {
    // Verificando o a quantidade de casas possui
    // se o tamanho for maior que 2 (maior digito, por exemplo 16) tamanho invalido
    switch (entrada.size()) {
        case 1:
            if (entrada != "L") {
                throw invalid_argument("Faixa etaria invalida");
            }
            break;
        case 2:
            if ((entrada[0]) != '1') {
                throw invalid_argument("Faixa etaria invalida");
            } else if (entrada[1] != '0' && entrada[1] != '2' && entrada[1] != '4'
            && entrada[1] != '6' && entrada[1] != '8') {
                throw invalid_argument("Faixa etaria invalida");
            }
            break;
        default:
            throw invalid_argument("Faixa etaria invalida");
    }
}

void CPF::validar(string entrada) {
    string CPFauxiliar;
    CPFauxiliar.resize(TAMANHO_CPF_AUXILIAR);
    int digito1Validacao = 0, digito2Validacao = 0, posicaoCPF = 0;


    if (entrada.size() != TAMANHO_CPF) {
        throw invalid_argument("Tamanho do CPF invalido");
    } else {
        if (entrada[3] != '.' || entrada[7] != '.' || entrada[11] != '-') {
            throw invalid_argument("O CPF nao contem os digitos separadores");

        } else {  // CPF no formato válido
            // Aloca o CPF em uma variável auxiliar, sem os digitos separadores, para cálculo do dígito verificador
            for (int originalCPF = 0; originalCPF < 11; originalCPF++) {
                // Quando for dígito separador, ignorar o dígito
                if (originalCPF == 3 || originalCPF == 7) {
                    originalCPF++;
                }
                if (!isdigit(entrada[originalCPF])) {
                    throw invalid_argument("CPF deve ser numérico");
                }
                CPFauxiliar[posicaoCPF] = entrada[originalCPF];
                posicaoCPF++;
            }

            for (int i = 0; i < 9; i++) {
                digito1Validacao += ((CPFauxiliar[i]) - '0') * (10 - i);
                digito2Validacao += (CPFauxiliar[8 - i] - '0') * (3 + i);
            }
            digito1Validacao = (digito1Validacao * 10) % 11;

            if (digito1Validacao == 10) {
                digito1Validacao = 0;
            }
            digito2Validacao += (entrada[PENULTIMO_DIGITO] - '0') * 2;
            digito2Validacao = (digito2Validacao * 10) % 11;
            if (digito2Validacao == 10) {
                digito2Validacao = 0;
            }
            if (digito1Validacao != entrada[PENULTIMO_DIGITO] - '0') {
                throw invalid_argument("Primeiro digito de verificacao invalido");
            } else if (digito2Validacao != entrada[ULTIMO_DIGITO] - '0') {
                throw invalid_argument("Segundo digito de verificacao invalido");
            }
        }
    }
}

void CPF::resetCPF(){
    this->valor = "";
}

void DataDeValidade::validar(string entrada) {
    string mes, ano;
    mes.resize(2); ano.resize(2);
    if (entrada.size() != TAMANHO_DATA) {
        throw invalid_argument("Tamanho de data invalido");
        // Verificando se são apenas números e as barras estão nos lugares corretos
    } else if (!isdigit(entrada[0]) || !isdigit(entrada[1]) || !isdigit(entrada[3]) || !isdigit(entrada[4])
            || entrada[2] != '/') {
        throw invalid_argument("Formato de data invalido");
    }
    // Atribuindo o mes e ano em variaveis auxiliares
    for (int i = 0; i < 5; i++) {
        if (i == 0 || i == 1) {
            mes[i] = entrada[i];
        }
        // Atribuir nos dois primeiros espaços da string o ano
        if (i == 3 || i == 4) {
            ano[i - 3] = entrada[i];
        }
    }
    if (mes < "0" || mes > "12") {
        throw invalid_argument("mes invalido");
    }
    if (ano < "00" || ano > "99") {
        throw invalid_argument("ano invalido");
    }
}
