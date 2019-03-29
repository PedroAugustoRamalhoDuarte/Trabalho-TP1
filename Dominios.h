//
// Created by pedro on 28/03/19.
//

#ifndef TRABALHOTP1_DOMINIOS_H
#define TRABALHOTP1_DOMINIOS_H

#include <stdexcept>
#include <string>

using namespace std;

class Codigo {
private:
    int valor;

    const int TAMANHO_CODIGO;

    void validar(int) throw (invalid_argument);

public:

    void setValor(int) throw (invalid_argument);

    int getValor() const {
        return valor;
    }
};

class CodigoDeEvento : public Codigo {
private:
    const int TAMANHO_CODIGO = 3;
};

class CodigoDeApresentacao : public Codigo {
private:
    const int TAMANHO_CODIGO = 4;
};

class CodigoDeIngresso : public Codigo {
private:
    const int TAMANHO_CODIGO = 5;
};

class CodigoDeSeguranca : public Codigo {
private:
    const int TAMANHO_CODIGO = 3;
};


class NomeDeEvento {
private:
    string valor;

    /* 20 digitos, podem ser letras,numero ou espaço, pelo menos 1 letra
     * , não pode existir 2 ou mais espaços seguidos*/
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};


class Data {
private:
    string valor;

    // Dia (1 ~ 31) - Mês (1 ~ 12) - Ano (00 ~ 99). Considerar anos bissextos
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};

class Horario {

private:
    string valor;

    // HH:MM - HH (07 ~ 22) e MM(00, 15, 30 ou 45)
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};

class Preco {
private:
    double valor;

    void validar(double) throw (invalid_argument);

public:
    void setValor(double) throw (invalid_argument);

    double getValor() const {
        return valor;
    }
};

class NumeroDeSala {
private:
    short int valor;

    // 1 a 10
    void validar(short) throw (invalid_argument);

public:
    void setValor(short) throw (invalid_argument);

    short int getValor() const {
        return valor;
    }
};

class Cidade {
private:
    string valor;

    // 16 caracteres. Pode ser letra, espaço ou ponto. Pelo menos 1 letra, sem espaço seguido. 1 ponto é precedido por letra
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};

class Estado {
private:
    char valor[2];

    void validar(char[2]) throw (invalid_argument);

public:
    void setValor(char[2]) throw (invalid_argument);

    const char *getValor() const {
        return valor;
    }
};

class Disponibilidade {
private:
    short int valor;

    void validar(short) throw (invalid_argument);

public:
    void setValor(short) throw (invalid_argument);

    short getValor() const {
        return valor;
    }
};

class ClasseDeEvento {
private:
    char valor;

    // 1 - teatro | 2 - esporte | 3 - show nacional | 4 - show internacional
    void validar(char) throw (invalid_argument);

public:
    void setValor(char) throw (invalid_argument);

    char getValor() const {
        return valor;
    }
};


class FaixaEtaria {
private:
    char valor[2];

    void validar(char[2]) throw (invalid_argument);

public:
    void setValor(char[2]) throw (invalid_argument);

    const char *getValor() const {
        return valor;
    }
};

class CPF {
private:
    string valor;

    // validacao de cpf
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};

class Senha {
private:
    string valor;

    // 6 digitos (A – Z a – z), dígito (0 a 9).Nao pode haver caracteres repetidos, pelo menos uma letra maiuscula minuscula e um digito
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};


class NumeroDeCartaoDeCredito {
private:
    string valor;

    // 16 caracteres segundo o https://en.wikipedia.org/wiki/Luhn_algorithm
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};


class DataDeValidade{
private:
    string valor;

    // XX/YY XX de 0 a 12 YY de 00 a 99
    void validar(string) throw (invalid_argument);

public:
    void setValor(string) throw (invalid_argument);

    const string &getValor() const {
        return valor;
    }
};

#endif //TRABALHOTP1_DOMINIOS_H
