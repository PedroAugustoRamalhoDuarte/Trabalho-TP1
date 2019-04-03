#ifndef TRABALHOTP1_DOMINIOS_H
#define TRABALHOTP1_DOMINIOS_H

#include <stdexcept>
#include <string>

using namespace std;

class Dominio {
protected:
    string valor;

    virtual void validar(string entrada) throw (invalid_argument) = 0;

public:
    void setValor(string entrada) throw (invalid_argument){
        validar(entrada);
        this->valor = entrada;
    }

    const string &getValor() const {
        return valor;
    }
};


class Codigo : public Dominio {
private:

    const int TAMANHO_CODIGO = -1;

    void validar(string entrada) throw (invalid_argument);

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


class NomeDeEvento : public Dominio {
private:
    /* 20 digitos, podem ser letras,numero ou espaço, pelo menos 1 letra
     * , não pode existir 2 ou mais espaços seguidos*/
    void validar(string entrada) throw (invalid_argument);
};


class Data : public Dominio{
private:
    // Dia (1 ~ 31) - Mês (1 ~ 12) - Ano (00 ~ 99). Considerar anos bissextos
    void validar(string entrada) throw (invalid_argument);

};

class Horario : public Dominio{
private:
    // HH:MM - HH (07 ~ 22) e MM(00, 15, 30 ou 45)
    void validar(string entrada) throw (invalid_argument);

};

class Preco : public Dominio {
private:
    // 0 - 1000(double)
    void validar(string entrada) throw (invalid_argument);

};

class NumeroDeSala : public Dominio {
private:
    // 1 a 10
    void validar(string entrada) throw (invalid_argument);
};

class Cidade : public Dominio {
private:
    // 16 caracteres. Pode ser letra, espaço ou ponto. Pelo menos 1 letra, sem espaço seguido. 1 ponto é precedido por letra
    void validar(string entrada) throw (invalid_argument);
};

class Estado : public Dominio {
private:
    // AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE,
    //PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO
    void validar(string entrada) throw (invalid_argument);

};

class Disponibilidade: public Dominio {
private:
    void validar(string entrada) throw (invalid_argument);

};

class ClasseDeEvento : public Dominio {
private:
    // 1 - teatro | 2 - esporte | 3 - show nacional | 4 - show internacional
    void validar(string entrada) throw (invalid_argument);
};


class FaixaEtaria : public Dominio{
private:
    // L, 10, 12, 14, 16 ou 18
    void validar(string entrada) throw (invalid_argument);
};

class CPF : public Dominio{
private:
    // validacao de cpf
    void validar(string entrada) throw (invalid_argument);

};

class Senha : public Dominio{
private:
    // 6 digitos (A – Z a – z), dígito (0 a 9).Nao pode haver caracteres repetidos, pelo menos uma letra maiuscula minuscula e um digito
    void validar(string entrada) throw (invalid_argument);
};


class NumeroDeCartaoDeCredito : public Dominio {
private:
    // 16 caracteres segundo o https://en.wikipedia.org/wiki/Luhn_algorithm
    void validar(string entrada) throw (invalid_argument);
};


class DataDeValidade : public Dominio{
private:
    // XX/YY XX de 0 a 12 YY de 00 a 99
    void validar(string entrada) throw (invalid_argument);
};

#endif //TRABALHOTP1_DOMINIOS_H
