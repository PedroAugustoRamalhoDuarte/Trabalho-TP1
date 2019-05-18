#ifndef TRABALHOTP1_ENTIDADES_H
#define TRABALHOTP1_ENTIDADES_H

/**
 * @file Entidades.h
 * @brief Arquivos Header das Entidades
 *
 * @copyright Pedro Augusto
 * @copyright Waliff Cordeiro
 */

#include "Dominios.h"

/** @brief Classe usuario
 *
 *  Responsável pelo armazenamento dos usuários no sistema com os atributos: cpf e senha.
 *  @see CPF
 *  @see Senha
 */
class Usuario {
private:
    // Chave primaria
    CPF cpf; /**< CPF do usuário, Chave primária*/

    Senha senha;/**< atributo que armazena a senha do usuario */

public:
    /** @brief Construtor Default da classe Usuario
     *
     */
    Usuario();

    /** @brief Construtor que inicializa todos os atributos
     *
     * @param cpf
     * @param senha
     */
    Usuario(const CPF &cpf, const Senha &senha);
    /** @brief Retorna o atributo cpf
    *
    * @return Objeto do tipo CPF
    */
    const CPF getCpf() const;

    /**@brief Atribui ao cpf o valor passado por parâmetro
     *
     * @param codigo : Objeto do tipo CPF
     */
    void setCpf(const CPF &cpf);

    /** @brief Retorna o atributo senha
    *
    * @return Objeto do tipo Senha
    */
    const Senha &getSenha() const;

    /**@brief Atribui ao codigo a senha passado por parâmetro
     *
     * @param codigo : Objeto do tipo Senha
     */
    void setSenha(const Senha &senha);

};

/** @brief Classe evento
 *
 *  Responsável pelo armazenamento dos eventos no sistema com os atributos:codigo(chave primária),nome,
 *  cidade, estado, classe, faixa.
 */
class Evento {
private:
    // Chave primaria
    CodigoDeEvento codigo;/**< atributo que armazena o codigo do evento , Chave primária*/

    NomeDeEvento nome;/**< atributo que armazena o nome do evento*/

    Cidade cidade;/**< atributo que armazena a cidade do evento*/

    Estado estado;/**< atributo que armazena o estado do evento*/

    ClasseDeEvento classe;/**< atributo que armazena a classe do evento*/

    FaixaEtaria faixa;/**< atributo que armazena a faixa etária referente ao evento*/

public:
    /** @brief Construtor default da classe Evento
     *
     */
    Evento();

    /** @brief Construtor que inicializa todas as variaveis da classe evento
     *
     * @param codigo
     * @param nome
     * @param cidade
     * @param estado
     * @param classe
     * @param faixa
     */
    Evento(const CodigoDeEvento &codigo, const NomeDeEvento &nome, const Cidade &cidade, const Estado &estado,
           const ClasseDeEvento &classe, const FaixaEtaria &faixa);

    /** @brief Retorna o atributo codigo
     *
     * @return Objeto do tipo CodigoDeEvento
     */
    const CodigoDeEvento &getCodigo() const;

    /**@brief Atribui ao codigo o valor passado por parâmetro
     *
     * @param codigo : Objeto do tipo CodigoDeEvento
     */
    void setCodigo(const CodigoDeEvento &codigo);

    /** @brief Retorna o atributo nome
     *
     * @return Objeto do tipo NomeDeEvento
     */
    const NomeDeEvento &getNome() const;

    /**@brief Atribui ao nome o valor passado por parâmetro
     *
     * @param nome : Objeto do tipo NomeDeEvento
     */
    void setNome(const NomeDeEvento &nome);

    /** @brief Retorna o atributo cidade
     *
     * @return Objeto do tipo Cidade
     */
    const Cidade &getCidade() const;

    /**@brief Atribui à cidade o valor passado por parâmetro
     *
     * @param cidade : Objeto do tipo Cidade
     */
    void setCidade(const Cidade &cidade);

    /** @brief Retorna o atributo estado
     *
     * @return Objeto do tipo Estado
     */
    const Estado &getEstado() const;

    /**@brief Atribui ao estado o valor passado por parâmetro
     *
     * @param estado : Objeto do tipo Estado
     */
    void setEstado(const Estado &estado);

    /** @brief Retorna o atributo classe
     *
     * @return Objeto do tipo ClasseDeEvento
     */
    const ClasseDeEvento &getClasse() const;

    /**@brief Atribui à classe o valor passado por parâmetro
     *
     * @param classe : Objeto do tipo ClasseDeEvento
     */
    void setClasse(const ClasseDeEvento &classe);

    /** @brief Retorna o atributo faixaEtaria
     *
     * @return Objeto do tipo FaixaEtaria
     */
    const FaixaEtaria &getFaixa() const;


    /**@brief Atribui à faixa o valor passado por parâmetro
     *
     * @param faixa : Objeto do tipo FaixaEtaria
     */
    void setFaixa(const FaixaEtaria &faixa);
};

/** @brief Classe Apresentação
 *
 *  Responsável pelo armazenamento das apresentações no sistema com os atributos:codigo(chave primária), data, horário,
 *  preço. número da sala, disponibilidade
 */
class Apresentacao {
private:
    // Chave Primaria
    CodigoDeApresentacao codigo; /**< atributo que armazena o codigo da apresentação , Chave primária*/

    Data data; /**< atributo que armazena a data da apresentação*/

    Horario horario; /**< atributo que armazena o horário da apresentação */

    Preco preco; /**< atributo que armazena o preço da apresentação */

    NumeroDeSala numeroDeSala; /**< atributo que armazena o numero da sala da apresentação */

    Disponibilidade disponibilidade; /**< atributo que armazena a disponibilidade da apresentação */

public:
    /** @brief Construtor default da classe Apresentacao
     *
     */
    Apresentacao();

    /** @brief Construtor que inicializa todos os atributos
     *
     * @param codigo
     * @param data
     * @param horario
     * @param preco
     * @param numeroDeSala
     * @param disponibilidade
     */
    Apresentacao(const CodigoDeApresentacao &codigo, const Data &data, const Horario &horario, const Preco &preco,
                 const NumeroDeSala &numeroDeSala, const Disponibilidade &disponibilidade);

    const CodigoDeApresentacao &getCodigo() const;

    /** @brief Atribui ao codigo o valor passado por parâmetro
     *
     * @param codigo : Objeto do tipo CodigoDeApresentacao
     */
    void setCodigo(const CodigoDeApresentacao &codigo);

    /** @brief Retorna o atributo data
     *
     * @return Objeto do tipo Data
     */
    const Data &getData() const;

    /**@brief Atribui à data o valor passado por parâmetro
     *
     * @param data : Objeto do tipo Data
     */
    void setData(const Data &data);

    /** @brief Retorna o atributo horario
     *
     * @return Objeto do tipo Horario
     */
    const Horario &getHorario() const;

    /** @brief Atribui ao horário o valor passado por parâmetro
     *
     * @param horario : Objeto do tipo Horario
     */
    void setHorario(const Horario &horario);

    /** @brief Retorna o atributo preco
     *
     * @return Objeto do tipo Preco
     */
    const Preco &getPreco() const;

    /** @brief Atribui ao preço valor passado por parâmetro
     *
     * @param preco : Objeto do tipo Preco
     */
    void setPreco(const Preco &preco);

    /** @brief Retorna o atributo numeroDeSala
     *
     * @return Objeto do tipo NumeroDeSala
     */
    const NumeroDeSala &getNumeroDeSala() const;

    /** @brief Atribui ao numeroDeSala o valor passado por parâmetro
     *
     * @param numeroDeSala : Objeto do tipo NumeroDeSala
     */
    void setNumeroDeSala(const NumeroDeSala &numeroDeSala);

    /** @brief Retorna o atributo disponibilidade
     *
     * @return Objeto do tipo Disponibilidade
     */
    const Disponibilidade &getDisponibilidade() const;

    /**@brief Atribui à disponibilidade o valor passado por parâmetro
     *
     * @param disponibilidade : Objeto do tipo disponibilidade
     */
    void setDisponibilidade(const Disponibilidade &disponibilidade);
};


/** @brief Classe ingresso.
 *
 *  Responsável pelo armazenamento dos ingressos no sistema com o atributo:codigo(chave primária).
 */
class Ingresso {
private:
    // Chave Primaria
    CodigoDeIngresso codigo; /**< atributo que armazena o codigo do ingresso , Chave primária*/

public:
    /** @brief Construtor default da class Ingresso
     *
     */
    Ingresso();

    /** @brief Construtor que inicializa todos os atributos
     *
     * @param codigo
     */
    Ingresso(const CodigoDeIngresso &codigo);

    /** @brief Retorna o atributo codigo
     *
     * @return Objeto do tipo CodigoDeIngresso
     */
    const CodigoDeIngresso &getCodigo() const;

    /** @brief Atribui ao codigo o valor passado por parâmetro
     *
     * @param codigo : Objeto do tipo CodigoDeIngresso
     */
    void setCodigo(const CodigoDeIngresso &codigo);


};


/** @brief Classe Cartão de crédito.
 *
 *  Responsável pelo armazenamento dos cartões de créditos do sistema com o atributo: número, código de segurança e data
 *  de validade
 */
class CartaoDeCredito {
private:
    // Chave Primaria
    NumeroDeCartaoDeCredito numero; /**< atributo que armazena o número do cartão de crédito , Chave primária */

    CodigoDeSeguranca codigoDeSeguranca; /**< atributo que armazena o código de segurança */

    DataDeValidade dataDeValidade; /**< atributo que armazena a data de validade do cartão de crédito */

public:
    /** @brief Construtor default da classe CartaoDeCredito
     *
     */
    CartaoDeCredito();

    /** @brief Construtor que inicializa todos os atributos
     *
     * @param numero
     * @param codigoDeSeguranca
     * @param dataDeValidade
     */
    CartaoDeCredito(const NumeroDeCartaoDeCredito &numero, const CodigoDeSeguranca &codigoDeSeguranca,
                    const DataDeValidade &dataDeValidade);

    /** @brief Retorna o atributo numero
     *
     * @return Objeto do tipo NumeroDeCartaoDeCredito
     */
    const NumeroDeCartaoDeCredito &getNumero() const;

    /** @brief Atribui ao numero o valor passado por parâmetro
     *
     * @param numero : Objeto do tipo NumeroDeCartaoDeCredito
     */
    void setNumero(const NumeroDeCartaoDeCredito &numero);

    /** @brief Retorna o atributo codigoDeSeguranca
     *
     * @return Objeto do tipo CodigoDeSeguranca
     */
    const CodigoDeSeguranca &getCodigoDeSeguranca() const;

    /** @brief Atribui ao codigo o valor passado por parâmetro
     *
     * @param codigoDeSeguranca : Objeto do tipo CodigoDeSeguranca
     */
    void setCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca);

    /** @brief Retorna o atributo dataDeValidade
     *
     * @return Objeto do tipo DataDeValidade
     */
    const DataDeValidade &getDataDeValidade() const;

    /** @brief Atribui à dataDevalidade o valor passado por parâmetro
     *
     * @param dataDeValidade : Objeto do tipo DataDeValidade
     */
    void setDataDeValidade(const DataDeValidade &dataDeValidade);
};


// Definições dos metodos inline


// CPF
inline const CPF Usuario::getCpf() const {
    return cpf;
}

inline void Usuario::setCpf(const CPF &cpf) {
    Usuario::cpf = cpf;
}

inline const Senha &Usuario::getSenha() const {
    return senha;
}

inline void Usuario::setSenha(const Senha &senha) {
    Usuario::senha = senha;
}


// Evento
inline const CodigoDeEvento &Evento::getCodigo() const {
    return codigo;
}

inline void Evento::setCodigo(const CodigoDeEvento &codigo) {
    Evento::codigo = codigo;
}

inline const NomeDeEvento &Evento::getNome() const {
    return nome;
}

inline void Evento::setNome(const NomeDeEvento &nome) {
    Evento::nome = nome;
}

inline const Cidade &Evento::getCidade() const {
    return cidade;
}

inline void Evento::setCidade(const Cidade &cidade) {
    Evento::cidade = cidade;
}

inline const Estado &Evento::getEstado() const {
    return estado;
}

inline void Evento::setEstado(const Estado &estado) {
    Evento::estado = estado;
}

inline const ClasseDeEvento &Evento::getClasse() const {
    return classe;
}

inline void Evento::setClasse(const ClasseDeEvento &classe) {
    Evento::classe = classe;
}

inline const FaixaEtaria &Evento::getFaixa() const {
    return faixa;
}

inline void Evento::setFaixa(const FaixaEtaria &faixa) {
    Evento::faixa = faixa;
}


// Apresentacao

inline const CodigoDeApresentacao &Apresentacao::getCodigo() const {
    return codigo;
}

inline void Apresentacao::setCodigo(const CodigoDeApresentacao &codigo) {
    Apresentacao::codigo = codigo;
}

inline const Data &Apresentacao::getData() const {
    return data;
}

inline void Apresentacao::setData(const Data &data) {
    Apresentacao::data = data;
}

inline const Horario &Apresentacao::getHorario() const {
    return horario;
}

inline void Apresentacao::setHorario(const Horario &horario) {
    Apresentacao::horario = horario;
}

inline const Preco &Apresentacao::getPreco() const {
    return preco;
}

inline void Apresentacao::setPreco(const Preco &preco) {
    Apresentacao::preco = preco;
}

inline const NumeroDeSala &Apresentacao::getNumeroDeSala() const {
    return numeroDeSala;
}

inline void Apresentacao::setNumeroDeSala(const NumeroDeSala &numeroDeSala) {
    Apresentacao::numeroDeSala = numeroDeSala;
}

inline const Disponibilidade &Apresentacao::getDisponibilidade() const {
    return disponibilidade;
}

inline void Apresentacao::setDisponibilidade(const Disponibilidade &disponibilidade) {
    Apresentacao::disponibilidade = disponibilidade;
}

// Evento

inline const CodigoDeIngresso &Ingresso::getCodigo() const {
    return codigo;
}

inline void Ingresso::setCodigo(const CodigoDeIngresso &codigo) {
    Ingresso::codigo = codigo;
}



// Cartao de credito

inline const NumeroDeCartaoDeCredito &CartaoDeCredito::getNumero() const {
    return numero;
}

inline void CartaoDeCredito::setNumero(const NumeroDeCartaoDeCredito &numero) {
    CartaoDeCredito::numero = numero;
}

inline const CodigoDeSeguranca &CartaoDeCredito::getCodigoDeSeguranca() const {
    return codigoDeSeguranca;
}

inline void CartaoDeCredito::setCodigoDeSeguranca(const CodigoDeSeguranca &codigoDeSeguranca) {
    CartaoDeCredito::codigoDeSeguranca = codigoDeSeguranca;
}

inline const DataDeValidade &CartaoDeCredito::getDataDeValidade() const {
    return dataDeValidade;
}

inline void CartaoDeCredito::setDataDeValidade(const DataDeValidade &dataDeValidade) {
    CartaoDeCredito::dataDeValidade = dataDeValidade;
}


#endif //TRABALHOTP1_ENTIDADES_H
