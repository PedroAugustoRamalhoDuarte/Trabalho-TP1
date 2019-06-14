#include "include/ModelAutenticacao.h"

// --------------------------------------------------------------------------
// Model Servico Autenticacao

// Construtor
ModelAutenticacao::ModelAutenticacao() : Model() {}

// Métodos da Interface Serviço Autenticação
bool ModelAutenticacao::autenticar(CPF cpf, Senha senha) {
    comandoSQL = "SELECT senha FROM usuario WHERE cpf =";
    comandoSQL += "'" + cpf.getValor() + "';";

    listaResultados.clear();

    // Verificar se as senhas coincidem
    this->executar();
    if (listaResultados.back() == senha.getValor()) {
        listaResultados.clear();
        return true;
    } else {
        listaResultados.clear();
        return false;
    }
}
