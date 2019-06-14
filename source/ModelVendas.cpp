#include "include/ModelVendas.h"

// --------------------------------------------------------------------------
// Model Serviço Vendas

// Construtor
ModelVendas::ModelVendas() : Model() {}

// Métodos da Interface de serviço de Ingressos
bool ModelVendas::adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) {
    // Logica para ver quantos eventos disponiveis
    comandoSQL = "SELECT disponibilidade FROM apresentacao WHERE codigo_apresentacao =";
    comandoSQL += "'" + codigo.getValor() + "';";
    listaResultados.clear();
    this->executar();
    int disponibilidade = stod(listaResultados.back());
    if (disponibilidade < quantidade) {
        return false;
    } else {
        // Compra os ingressos
        comandoSQL = "INSERT INTO ingresso (codigo_apresentacao, cpf_usuario, quantidade) VALUES (";
        comandoSQL += "'" + codigo.getValor() + "',";
        comandoSQL += "'" + cpf.getValor() + "',";
        comandoSQL += "'" + to_string(quantidade) + "');";
        this->executar();

        // Retira os ingressos comprados da disponibilidade
        comandoSQL = "UPDATE apresentacao SET disponibilidade = ";
        comandoSQL += "'" + to_string(disponibilidade - quantidade) + "' WHERE codigo_apresentacao = ";
        comandoSQL += "'" + codigo.getValor() + "';";
        this->executar();
    }

    return true;
}

void ModelVendas::vendasDoEvento(CodigoDeEvento codigoDeEvento,
                                 list<pair<CodigoDeApresentacao, int>> &tabelaQtdIngressos) {

    list<CodigoDeApresentacao> listaCodigoApr;
    comandoSQL = "SELECT (codigo_apresentacao) FROM apresentacao WHERE codigo_evento =";
    comandoSQL += "'" + codigoDeEvento.getValor() + "';";

    listaResultados.clear();
    this->executar();
    CodigoDeApresentacao codigoDeApresentacao;
    for (auto result : listaResultados) {
        codigoDeApresentacao.setValor(result);
        listaCodigoApr.push_back(codigoDeApresentacao);
    }
    for (auto apr : listaCodigoApr) {
        comandoSQL = "SELECT SUM(quantidade) FROM ingresso WHERE codigo_apresentacao =";
        comandoSQL += "'" + apr.getValor() + "'";
        listaResultados.clear();
        this->executar();
        if (!listaResultados.empty()) {
            tabelaQtdIngressos.push_back({apr, stod(listaResultados.back())});
            listaResultados.pop_back();
        } else {
            tabelaQtdIngressos.push_back({apr, 0});
        }
    }
}

void ModelVendas::listarApresentacao(list<CodigoDeApresentacao> &listCodigosApr) {
    comandoSQL = "SELECT codigo_apresentacao FROM apresentacao";
    listaResultados.clear();
    this->executar();
    for (auto codigo : listaResultados) {
        CodigoDeApresentacao codigoDeApresentacao;
        codigoDeApresentacao.setValor(codigo);
        listCodigosApr.push_back(codigoDeApresentacao);
    }
}


void ModelVendas::listarEventos(list<CodigoDeEvento> &listCodigoEve, CPF cpf) {
    comandoSQL = "SELECT codigo FROM evento where cpf_usuario =  ";
    comandoSQL += "'" + cpf.getValor() + "';";
    listaResultados.clear();
    this->executar();
    for (auto codigo : listaResultados) {
        CodigoDeEvento codigoDeEvento;
        codigoDeEvento.setValor(codigo);
        listCodigoEve.push_back(codigoDeEvento);
    }
}


void ModelVendas::vendasPorCpf(CodigoDeApresentacao codigoDeApresentacao, list<pair<CPF, int>> &tabelaCpfIngressos) {
    CPF cpf;
    string qte;
    comandoSQL = "SELECT cpf_usuario, quantidade FROM ingresso WHERE codigo_apresentacao = ";
    comandoSQL += "'" + codigoDeApresentacao.getValor() + "';";
    listaResultados.clear();
    this->executar();
    auto tam = listaResultados.size();
    for (int i = 0; i < tam; i++) {
        if (i % 2 == 1) {
            cpf.setValor(listaResultados.back());
            tabelaCpfIngressos.push_back({cpf, stod(qte)});
        } else {
            qte = listaResultados.back();
        }
        listaResultados.pop_back();
    }
}
