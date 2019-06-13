#include "include/ModelUsuario.h"

// --------------------------------------------------------------------------
// Model Servico de Usuario

// Construtor
ModelUsuario::ModelUsuario() : Model() {
}

// Metodos da Interface Serviço Usuário
bool ModelUsuario::cadastrarUsuario(Usuario usuario, CartaoDeCredito cartaoDeCredito) {
    comandoSQL = "INSERT INTO usuario VALUES (";
    comandoSQL += "'" + usuario.getCpf().getValor() + "', ";
    comandoSQL += "'" + usuario.getSenha().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getCodigoDeSeguranca().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getNumero().getValor() + "',";
    comandoSQL += "'" + cartaoDeCredito.getDataDeValidade().getValor() + "');";
    try {
        cout << "Inserindo usuario :" << endl;
        this->executar();
        return true;
    } catch (invalid_argument &e) {
        return false;
    }
}

bool ModelUsuario::mostrarUsuario(CPF cpf, Usuario *usuario, CartaoDeCredito *cartaoDeCredito) {
    comandoSQL = "SELECT * FROM usuario WHERE cpf = ";
    comandoSQL += "'" + cpf.getValor() + "';";

    // Variaveis auxiliares
    CPF auxCpf;
    Senha auxSenha;
    NumeroDeCartaoDeCredito numero;
    CodigoDeSeguranca codigo;
    DataDeValidade validade;
    try {
        cout << "Procurando usuario : ";
        cout << cpf.getValor() << endl;
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

        return true;
    } catch (invalid_argument &e) {
        cout << "Erro ao Procurar Usuario(Mostrar Model)";
        return false;
    }
}

bool ModelUsuario::excluirUsuario(CPF cpf) {
    comandoSQL = "DELETE FROM usuario WHERE cpf = ";
    comandoSQL += "'" + cpf.getValor() + "';";
    cout << "Excluindo Usuario : ";
    cout << cpf.getValor() << endl;
    try {
        this->executar();
        return true;
    } catch (...) {
        return false;
    }
}
