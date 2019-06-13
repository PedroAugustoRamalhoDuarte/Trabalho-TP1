#include "include/ModelAutenticacao.h"

// --------------------------------------------------------------------------
// Model Servico Autenticacao

// Construtor
ModelAutenticacao::ModelAutenticacao() : Model() {}

// Métodos da Interface Serviço Autenticação
bool ModelAutenticacao::autenticar(CPF cpf, Senha senha) {
    comandoSQL = "SELECT senha FROM usuario WHERE cpf =";
    comandoSQL += "'" + cpf.getValor() + "';";
    cout << "Autenticando Usuario";
    cout << cpf.getValor() << endl;
    try {
        // Verificar se as senhas coincidem
        this->executar();
        if (listaResultados.back() == senha.getValor()) {
            listaResultados.clear();
            cout << "autenticou";
            return true;
        } else {
            listaResultados.clear();
            cout << "nao autenticou";
            return false;
        }

    } catch (...) {
        return false;
    }
}