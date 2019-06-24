#ifndef TRABALHOTP1_DOMINIOS_H
#define TRABALHOTP1_DOMINIOS_H

/**
 * @file Dominios.h
 * @brief Arquivos Header dos Domínios
 *
 * @copyright Pedro Augusto
 * @copyright Waliff Cordeiro
 */


#include <stdexcept>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <list>

using namespace std;

/** @brief Classe pai de todos os domínios da biblioteca.
 *
 * Esta classe passa de herança para as classes filhas os métodos set, get e um método virtual validar,
 * assim como o atributo valor
 *
 * */

class Dominio {
protected:

    string valor; /**< Atributo no qual é armazenado a informação da classe.*/

    /* @brief Método virtual validar
     *
     * Método de validação de formato, no qual varia de acordo com o domínio, em caso de formato inválido
     * é retornado throw
     *
     * @param entrada string que será validada
     * @throw invalid_argument caso não esteja no formato desejado
     *
     */

    virtual void validar(string entrada) = 0;

public:
    /** @brief Método Set.
     *
     * Método responsável pela atribuição do valor, nele é chamado o método validar que verifica se o valor está
     * no formato correto, se estiver será atribuido, caso contrário será retornado throw.
     *
     * @param entrada string que será validada para atribuição.
     * @throw invalid_argument caso não esteja no formato desejado.
     *
     * @see validar()
     */
    void setValor(const string &entrada) {
        validar(entrada);
        this->valor = entrada;
    }

    /** @brief Método Get
     *
     * Método responsável por retornar o valor
     *
     * @return valor
     */
    const string &getValor() const {
        return valor;
    }
};

/** @brief Classe abstrata pai dos Códigos.
 *
 * Classe que contêm o metódo validar que funciona para todos os tipos de códigos lista dos a seguir:
 * @see CodigoDeEvento
 * @see CodigoDeApresentacao
 * @see CodigoDeIngresso
 * @see CodigoDeSeguranca
 */
class Codigo : public Dominio {
protected:
    int TAMANHO_CODIGO = 0; /**< Variavel que armazena o tamanho do formato do codigo.*/

    /** @brief Metodo que valida certa entrada em formato de codigo
     *
     * O método verifica se a entrada tem o mesmo tamanho que o código a ser validado e verifica se todos os caracteres
     * da string entrada são do tipo inteiro
     * @param entrada uma string com o codigo para se validar.
     * @throws invalid_argument se a entrada não for do formato do código
     */

    void validar(string entrada) override;

};

/** @brief Classe que manipula os códigos de evento.
 *
 *   Classe filha de Codigo. Na qual a funcao é armazenar um codigo de evento de tamanho 3
 */
class CodigoDeEvento : public Codigo {
private:
    const static int TAMANHO_CODIGO_EVENTO = 3; /**< const que define o tamanho do codigo de evento.*/

public:
    /**
     * Construtor do Código De Evento.
     * Define o atributo tamanho_codigo para TAMANHO_CODIGO_EVENTO.
     */
    CodigoDeEvento();

};

/** @brief Classe que manipula os códigos de apresentacão.
 *
 *      Classe filha de Código. Na qual a funcao é armazenar um código de apresentação de tamanho 4
 *
 */
class CodigoDeApresentacao : public Codigo {
private:
    const static int TAMANHO_CODIGO_APRESENTACAO = 4; /**< const que define o tamanho do codigo de apresentacao.*/

public:
    /**
    * Construtor do Codigo De Apresentacao.
    * Define o atributo tamanho_codigo para TAMANHO_CODIGO_APRESENTACAO.
    */
    CodigoDeApresentacao();
};

/** @brief Classe que manipula os códigos de ingresso.
 *
 *      Classe filha de Código. Na qual a funcao é armazenar um código de ingresso de tamanho 5
 */
class CodigoDeIngresso : public Codigo {
private:
    const static int TAMANHO_CODIGO_INGRESSO = 5; /**< const que define o tamanho do código de ingresso.*/

public:
    /**
    * Construtor do Codigo De Ingresso.
    * Define o atributo tamanho_codigo para TAMANHO_CODIGO_INGRESSO.
    */
    CodigoDeIngresso();

};

/** @brief Classe que manipula os códigos de segurança.
 *
 *    Classe filha de Codigo. Na qual a funcao é armazenar um codigo de segurança de tamanho 3
 */
class CodigoDeSeguranca : public Codigo {
private:
    const static int TAMANHO_CODIGO_SEGURANCA = 3; /**< const que define o tamanho do codigo de Seguranca.*/

public:
    /**
    * Construtor do Codigo De Seguranca.
    * Define o atributo tamanho_codigo para TAMANHO_CODIGO_SEGURANCA.
    */
    CodigoDeSeguranca();

};

/** @brief Classe que manipula os nomes dos eventos do sistema
 *
 * Esta classe possui o método responsável pela validação do nome de evento. O valor de entrada deve estar
 * em um formato de modo que não exista 2 espaços consecutivos, o tamanho deve ser menor que TAMANHO_NOME_EVENTO,
 * o formato também deve conter pelo menos uma letra. Os caracteres permitidos são letras, digitos ou espaços
 *
 * */
class NomeDeEvento : public Dominio {
private:
    const static int TAMANHO_NOME_EVENTO = 20; /**< const que define o tamanho do nome de evento.*/

    /* @brief Metodo que valida se a entrada esta de acordo com o formato do nomeDeEvento.
     *
     * O Metodo verifica se na string de entrada há 2 espaços consecutivos, se o tamanho é menor ao TAMANHO_NOME_EVENTO
     * , se contém pelo menos uma letra, e se os caracteres da string não são letras,digitos ou espaços. Se uma das
     * condições anteriores forem descumpridas a string entrada não está no padrão estabelecido e é lançada uma exceção
     * do tipo invalid_argument.
     * @param entrada string a ser validada como NomeDeEvento.
     * @throws invalid_argument Caso a string de entrada não esteja no formato do NomeDeEvento.
     */
    void validar(string entrada) override;
};


/** @brief Classe que manipula os precos do sistema
 *
 * Esta classe possui o método responsável pela validação do preco. O valor de entrada deve ser um número
 * pertecente ao intervalo [0, 1000]
 * */
class Preco : public Dominio {
private:
    /*@brief Método que avalia se a entrada está no formato de Preço.
     *
     * O método verifica se a string entrada está em uma intervalo de 0 a 1000, caso não estiver, será lançada uma
     * exceção do tipo invalid_argument
     *
     * @param entrada string a ser validada como Preço;
     * @throws invalid_arguement caso a string entrada não esteja no formato do Preço.
     */
    void validar(string entrada) override;

};

/** @brief Classe que manipula os numeros de salas do sistema
 *
 * Esta classe possui o método responsável pela validação do numero de sala. O valor de entrada estar no intervalo
 * [1, 10] sendo aceito apenas caracteres numéricos
 * */
class NumeroDeSala : public Dominio {
private:

    /*@brief Método que avalia se a entrada está no formato do NumeroDeSala.
    *
    * O método verifica se a string entrada esta no intervalo de [1, 10], se não estiver é lançada uma exceção do tipo
    * invalid_argument
    *
    * @param entrada string a ser validada como NumeroDeSala;
    * @throws invalid_arguement caso a string entrada não esteja no formato do NumeroDeSala.
    */
    void validar(string entrada) override;
};

/** @brief Classe que manipula as cidades do sistema
 *
 * Esta classe possui o método responsável pela validação da cidade. O formato do valor deve ser uma string
 * com o tamanho igual a TAMANHO_CIDADE (15), só é permitido conter letra, espaço ou ponto. Não pode haver mais de 1
 * espaço consectivo e os pontos devem ser precedidos por pelo menos uma letra.
 *
 * @see validar()
 * */
class Cidade : public Dominio {
private:
    const static int TAMANHO_CIDADE = 15; /**< const que define o tamanho da Cidade.*/

    /*@brief Método que avalia se a entrada está no formato da Cidade.
     *
     * O método verifica se a string entrada menor do que TAMANHO_CIDADE, Se cada caractere da entrada é letra,
     * espaço ou ponto, se não há espaços seguidos e se cada ponto é precedido por uma letra.Se uma das condições
     * anteriores forem descumpridas a string entrada não está no padrão estabelecido e é lançada uma exceção
     * do tipo invalid_argument.
     *
     * @param entrada string a ser validada como Cidade;
     * @throws invalid_arguement caso a string entrada não esteja no formato da Cidade.
     */
    void validar(string entrada) override;
};

/** @brief Classe que manipula as classes de evento do sistema
 *
 * Esta classe possui o método responsável pela validação da classe de evento. O valor de entrada deve ser um
 * número pertecente ao intervalo [1, 4] sendo que:
 * 1 = TEATRO
 * 2 = ESPORTE
 * 3 = SHOW NACIONAL
 * 4 = SHOW INTERNACIONAL
 * */
class ClasseDeEvento : public Dominio {
private:
    /**@brief Método que avalia se a entrada está no formato da ClasseDeEvento.
     *
     * O método verifica se a string entrada é 1,2,3 ou 4. Sendo que O dígito 1 identifica TEATRO, 2identifica ESPORTE,
     * 3 identifica SHOW NACIONAL e 4 identifica SHOW INTERNACIONAL.
     *
     * @param entrada string a ser validada como ClasseDeEvento;
     * @throws invalid_arguement caso a string entrada não esteja no formato da ClasseDeEvento.
     */
    void validar(string entrada) override;
};


/** @brief Classe que manipula os senhas do sistema
 *
 * Esta classe possui o método responsável pela validação da senha. O valor de entrada deve ser uma string e seu
 * tamanho deve ser igual a TAMANHO_SENHA (6). Cada caracter deve ser letra ou digito. Não podem existir caracteres
 * repetidos. Deve existir pelo menos uma letra maiúscula, uma letra minúscula e um número.
 * */
class Senha : public Dominio {
private:
    const static int TAMANHO_SENHA = 6; /**< const que define o tamanho da Senha */
    /*@brief Método que avalia se a entrada está no formato da Senha.
    *
    * O método verifica se a string entrada é do tamanho do TAMANHO_SENHA, Se cada caractere da entrada é letra,
    * ou digito,se não há caracteres repetidos e se há pelo menos uma letra maiuscula, minuscula e um número. Se uma das
    * condições anteriores forem descumpridas a string entrada não está no padrão estabelecido e é lançada uma exceção
    * do tipo invalid_argument.
    *
    * @param entrada string a ser validada como Senha.
    * @throws invalid_arguement caso a string entrada não esteja no formato da Senha.
    */
    void validar(string entrada) override;
};


/** @brief Classe que manipula os números de cartões do sistema.
 *
 * O valor de entrada deve ser uma string com tamanho igual ao TAMANHO_NUMERODECARTAO (16), o formato da entrada deve
 * obedecer o algoritmo de Luhn, ou seja, deve ser um número de cartão existente.
 *
 * Esta classe possui o método responsável pela validação do número de cartão
 * */

class NumeroDeCartaoDeCredito : public Dominio {
private:
    const static int TAMANHO_NUMERODECARTAO = 16;

    /*@brief Método que avalia se a entrada está no formato do NumeroDeCartaoDeCredito.
    *
    * O método verifica se a string entrada é do tamanho do TAMANHO_NUMERODECARTAO e se obedece o algoritmo de Luhn
    *
    * @param entrada string a ser validada como NumeroDeCartaoDeCredito.
    * @throws invalid_arguement caso a string entrada não esteja no formato do NumeroDeCartaoDeCredito.
     */
    void validar(string entrada) override;
};

/** @brief Classe que manipula as datas do sistema
 *
 * Esta classe possui o método responsável pela validação da data. O valor de entrada deve ser uma string no formato
 * DD/MM/AA, sendo que só são aceitos datas válidas, verificando-se as condições dos anos bissextos.
 * */
class Data : public Dominio {
private:
    const static int TAMANHO_DATA = 8; /**< Uma constante definindo o tamanho que a estrutura de data deve ter XX/XX/XX */
    /* @brief Método responsável pela validação da Data
     *
     * Este método de validação separa a data em dia, mes e ano, após verificar se os dados são numéricos
     * verifica o intervalo de dias, meses e anos permitidos para uma data valida.
     * A validação também verifica os meses com 30 e 31 dias, assim como 28 para fevereiro e 29 em anos bissextos
     *
     * @param string uma entrada contendo a data DD/MM/AA
     * @throws invalid_argument se a entrada não for do formato do código ou se houver alguma data inválida
     * */
    void validar(string entrada) override;
};

/** @brief Classe que manipula os horarios do sistema
 *
 * Esta classe possui o método responsável pela validação do horário. O valor de entrada deve estar no formato
 * HH:MM. Os minutos válidos são: 00, 15, 30 ou 45. As horas válidas pertencem ao intervalo [7, 22]
 * */
class Horario : public Dominio {
private:
/* @brief Método responsável pela validação do horário
 *
 * Este método de validação separa o horário em horas e minutos, após verificar se os dados são numéricos
 * atribui em variáveis auxiliares as horas e os minutos, verifica também se as horas estão no intervalo de
 * 7 à 22 horas e se os minutos são 00, 15, 30 ou 45
 *
 * @param string uma entrada contendo o horário HH:MM
 * @throws invalid_argument se a entrada não for do formato do código ou se houver algum horário inválido
 * */
    void validar(string entrada) override;

};

/** @brief Classe que manipula os Estados do sistema
 *
 * Esta classe possui o método responsável pela validação do Estado. O valor de entrada deve ser a sigla de
 * algum Estado existente no Brasil
 * */
class Estado : public Dominio {
private:
/* @brief Método responsável pela validação do Estado
*
* Este método de validação seleciona o Estado válido dentro dos Estados possíveis
*
* @param string uma entrada contendo o Estado
* @throws invalid_argument se a entrada não for do formato do código ou se não houver o Estado em questão
* */
    void validar(string entrada) override;

};

/** @brief Classe que manipula a disponibilidade de ingressos do sistema.
 *
 *   O valor de entrada deve pertencer ao intervalo [0, 250] sendo que só são aceitos valores numéricos.
 * */
class Disponibilidade : public Dominio {
private:
/* @brief Método responsável pela validação da Disponibilidade
*
* Este método de validação verifica a Disponibilidade, sendo que esta deve estar entre [0, 250]
*
* @param string uma entrada contendo a Disponibilidade
* @throws invalid_argument se a entrada não for de formato válido ou se a Disponibilidade não respeitar o intervalo
* */
    void validar(string entrada) override;

};

/** @brief Classe que manipula as Faixas Etarias do sistema
 *
 * Esta classe possui o método responsável pela validação da Faixa Etaria. Sendo que esta deve estar entre as possíveis
 * faixas etárias: L, 10, 12, 14, 16 e 18
 * */
class FaixaEtaria : public Dominio {
private:
/* @brief Método responsável pela validação da Faixa Etária
*
* Este método de validação seleciona a Faixa Etária válida dentro das Faixas Etárias possíveis
*
* @param string uma entrada contendo a Faixa Etária
* @throws invalid_argument se a entrada não for do formato do código ou se não houver a Faixa Etária em questão
* */
    void validar(string entrada) override;
};

/** @brief Classe que manipula os CPF do sistema
 *
 * Esta classe possui o método responsável pela validação do CPF. O valor de entrada deve ser uma string no formato
 * XXX.XXX.XXX-XX, no qual X são números e os dois últimos dígitos são verificadores do CPF. O valor inserido deve
 * ser um CPF válido.
 * */
class CPF : public Dominio {
private:
    // validacao de cpf

    const static int TAMANHO_CPF = 14; /**< Uma constante definindo o tamanho que a estrutura do CPF deve ter XXX.XXX.XXX-XX */
    const static int TAMANHO_CPF_AUXILIAR = 9; /**< Uma constante definindo o tamanho que a estrutura do CPF auxiliar deve ter XXXXXXXXXXX */
    const static int ULTIMO_DIGITO = TAMANHO_CPF - 1; /**< Uma constante definindo o índice do último dígito do CPF */
    const static int PENULTIMO_DIGITO =
            TAMANHO_CPF - 2; /**< Uma constante definindo o índice do penultimo dígito do CPF */

    /* @brief Método responsável pela validação do CPF
    *
    * Este método de validação verifica o formato do CPF, após a verificação e a constatação de que todos os dígitos
    * são numéricos, verifica-se se o CPF é válido com base nos dígitos de verificação dos CPFS
    *
    * @param string uma entrada contendo o CPF
    * @throws invalid_argument se a entrada não for do formato do código ou se o CPF não for válido
    */
    void validar(string entrada) override;
public:

    void resetCPF();
};

/** @brief Classe que manipula a data de validade do sistema.
 *
 * Esta classe possui o método responsável pela validação da Data de Validade. O valor de entrada deve ser uma string
 * no formato MM/AA, sendo que o mês deve ser um valor numérico pertecente ao intervalo (0, 12] e o ano pertencente
 * ao intervalo [00,99]
 * */
class DataDeValidade : public Dominio {
private:

    const static int TAMANHO_DATA = 5; /**< Uma constante definindo o tamanho da estrutura da Data MM/AA*/
    /* @brief Método responsável pela validação da DataDeValidade
    *
    * Este método de validação atribui o mes e o ano em variáveis auxiliares, após verificar se os dados são numéricos
    * verifica-se se os meses estão no intervalo (0,12] e os anos estão no intervalo [00, 99]
    *
    * @param string uma entrada contendo a Data de Validade
    * @throws invalid_argument se a entrada não for do formato do código ou se não estiver no intervalo possível
    */
    void validar(string entrada) override;
};

#endif //TRABALHOTP1_DOMINIOS_H
