#include "include/ModelUsuario.h"

// --------------------------------------------------------------------------
// Model Servico de Usuario

// Construtor
ModelUsuario::ModelUsuario() : Model() {
}

// Metodos da Interface Serviço Usuário
void ModelUsuario::cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) {
    comandoSQL = "INSERT INTO usuario VALUES (";
    comandoSQL += "'" + usuario.getCpf().getValor() + "', ";
    comandoSQL += "'" + usuario.getSenha().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getCodigoDeSeguranca().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getNumero().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getDataDeValidade().getValor() + "');";
    this->executar();
}

void ModelUsuario::mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) {
    comandoSQL = "SELECT * FROM usuario WHERE cpf = ";
    comandoSQL += "'" + cpf.getValor() + "';";

    // Variaveis auxiliares
    CPF auxCpf;
    Senha auxSenha;
    NumeroDeCartaoDeCredito numero;
    CodigoDeSeguranca codigo;
    DataDeValidade validade;

    listaResultados.clear();
    this->executar();

    // Atribui a data de validade
    validade.setValor(listaResultados.back());
    listaResultados.pop_back();
    cartaoDeCredito->setDataDeValidade(validade);

    // Atribui o Numero de cartão
    numero.setValor(listaResultados.back());
    listaResultados.pop_back();
    cartaoDeCredito->setNumero(numero);

    // Atribui o Codigo de segurança
    codigo.setValor(listaResultados.back());
    listaResultados.pop_back();
    cartaoDeCredito->setCodigoDeSeguranca(codigo);

    // Atribui a senha
    auxSenha.setValor(listaResultados.back());
    listaResultados.pop_back();
    usuario->setSenha(auxSenha);

    // Atribui o cpf
    auxCpf.setValor(listaResultados.back());
    listaResultados.pop_back();
    usuario->setCpf(auxCpf);
}

bool ModelUsuario::excluirUsuario(CPF cpf) {
    if (!possuiEvento(cpf)) {
        comandoSQL = "DELETE FROM usuario WHERE cpf = ";
        comandoSQL += "'" + cpf.getValor() + "';";
        this->executar();
        return true;
    } else {
        return false;
    }
}

// Métodos Auxiliares
bool ModelUsuario::possuiEvento(CPF cpf) {
    comandoSQL = "SELECT COUNT(*) FROM evento WHERE cpf_usuario = ";
    comandoSQL += "'" + cpf.getValor() + "';";
    listaResultados.clear();
    this->executar();
    return stod(listaResultados.back()) > 0;
}
