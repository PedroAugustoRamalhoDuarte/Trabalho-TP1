//
// Created by pedro on 13/06/19.
//

#include "include/ModelEventos.h"

// --------------------------------------------------------------------------
// Model Servico Eventos

// Construtor
ModelEventos::ModelEventos() : Model() {}

// Metodos da Interface Serviço Eventos
bool ModelEventos::meusEventos(list<Evento> &listaEventos, CPF cpf) {
    comandoSQL = "SELECT * FROM evento WHERE cpf_usuario = ";
    comandoSQL += "'" + cpf.getValor() + "';";
    try {
        listaResultados.clear();
        this->executar();
        int tam = (listaResultados.size() / 7);
        for (int i = 0; i < tam; i++) {
            auto evento = new Evento();
            CodigoDeEvento codigo;
            NomeDeEvento nome;
            Cidade cidade;
            Estado estado;
            ClasseDeEvento classe;
            FaixaEtaria faixa;

            // Atribundo a faixa etaria ao evento
            cout << "faixa: " << listaResultados.back() << endl;
            faixa.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setFaixa(faixa);

            // Atribuindo a classe ao evento
            cout << "classe: " << listaResultados.back() << endl;
            classe.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setClasse(classe);

            // Atribuindo o estado ao evento
            cout << "estado: " << listaResultados.back() << endl;
            estado.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setEstado(estado);

            // Atribuindo a cidade ao evento
            cout << "cidade: " << listaResultados.back() << endl;
            cidade.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setCidade(cidade);


            // Atribuindo o nome ao evento
            cout << "nome: " << listaResultados.back() << endl;
            nome.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setNome(nome);

            //Atribuindo o codigo ao evento
            cout << "codigo: " << listaResultados.back() << endl;
            codigo.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setCodigo(codigo);

            // Retirando o CPF, pois não é usado no Evento
            listaResultados.pop_back();


            listaEventos.push_back(*evento);

            delete evento;
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool ModelEventos::alterarEvento(CPF cpf, Evento evento) {
    comandoSQL = "UPDATE evento SET nome = ";
    comandoSQL += "'" + evento.getNome().getValor() + "', classe = ";
    comandoSQL += "'" + evento.getClasse().getValor() + "', faixa_etaria = ";
    comandoSQL += "'" + evento.getFaixa().getValor() + "', estado = ";
    comandoSQL += "'" + evento.getEstado().getValor() + "', cidade = ";
    comandoSQL += "'" + evento.getCidade().getValor() + "' WHERE codigo = ";
    comandoSQL += "'" + evento.getCodigo().getValor() + "';";
    try {
        this->executar();
        cout << "Evento alterando com sucesso " << endl;
        return true;
    } catch (...) {
        return false;
    }
}

bool ModelEventos::descadastrarEvento(CPF cpf, CodigoDeEvento codigo) {
    // Falta Logica de negocio
    if (isUsuarioDono(cpf, codigo)) {
        if (!jaVendeu(codigo)) {
            cout << "Antes de deletar Evento" << endl;
            comandoSQL = "DELETE from evento WHERE codigo = ";
            comandoSQL += "'" + codigo.getValor() + "';";
            try {
                this->executar();
                cout << "Evento Excluido com sucesso" << endl;
                comandoSQL = "DELETE from apresentacao WHERE codigo_evento = ";
                comandoSQL += "'" + codigo.getValor() + "';";
                this->executar();
                return true;
            } catch (...) {
                cout << "Falha ao excluir evento" << endl;
                return false;
            }
        } else {
            cout << "Falhha ao excluir enveto(Evento ja teve ingressos vendidos)" << endl;
        }

    } else {
        cout << "Falha ao excluir evento(Usuário não é dono do evento)" << endl;
        return false;
    }
}

bool ModelEventos::pesquisarEventos(list<Evento> &listaEventos, Data dataInicio, Data dataTermino, Cidade cidade,
                                    Estado estado) {
    comandoSQL = "SELECT * FROM evento WHERE cidade =";
    comandoSQL += "'" + cidade.getValor() + "' AND estado = ";
    comandoSQL += "'" + estado.getValor() + "';";
    try {
        cout << "PESQUISANDO EVENTO" << endl;
        listaResultados.clear();
        this->executar();
        cout << "PESQUISANDO EVENT1" << endl;
        int tam = (listaResultados.size() / 7);
        cout << "PESQUISANDO EVENTO2" << endl;
        for (int i = 0; i < tam; i++) {
            auto evento = new Evento();
            CodigoDeEvento codigo;
            NomeDeEvento nome;
            Cidade cidade;
            Estado estado;
            ClasseDeEvento classe;
            FaixaEtaria faixa;

            // Atribundo a faixa etaria ao evento
            cout << "faixa: " << listaResultados.back() << endl;
            faixa.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setFaixa(faixa);

            // Atribuindo a classe ao evento
            cout << "classe: " << listaResultados.back() << endl;
            classe.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setClasse(classe);

            // Atribuindo o estado ao evento
            cout << "estado: " << listaResultados.back() << endl;
            estado.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setEstado(estado);

            // Atribuindo a cidade ao evento
            cout << "cidade: " << listaResultados.back() << endl;
            cidade.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setCidade(cidade);


            // Atribuindo o nome ao evento
            cout << "nome: " << listaResultados.back() << endl;
            nome.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setNome(nome);

            //Atribuindo o codigo ao evento
            cout << "codigo: " << listaResultados.back() << endl;
            codigo.setValor(listaResultados.back());
            listaResultados.pop_back();
            evento->setCodigo(codigo);

            // Retirando o CPF, pois não é usado no Evento
            listaResultados.pop_back();


            listaEventos.push_back(*evento);

            delete evento;
        }
    } catch (...) {
        return false;
    }

    this->verificaDataApresentacao(listaEventos, dataInicio, dataTermino);

    return true;
}

bool ModelEventos::mostrarApresentacao(list<Apresentacao> &listaApresentacao, CodigoDeEvento codigoDeEvento) {
    comandoSQL = "SELECT * FROM apresentacao WHERE codigo_evento =";
    comandoSQL += "'" + codigoDeEvento.getValor() + "' ;";
    try {
        // Limpando a lista de resultados
        listaResultados.clear();
        cout << "PESQUISANDO EVENTO" << endl;
        this->executar();
        cout << "PESQUISANDO EVENT1" << endl;
        int tam = (listaResultados.size() / 7);
        cout << "PESQUISANDO EVENTO2" << endl;
        for (int i = 0; i < tam; i++) {
            auto apresentacao = new Apresentacao();
            CodigoDeApresentacao codigo;
            Data data;
            Horario horario;
            Preco preco;
            NumeroDeSala numeroDeSala;
            Disponibilidade disponibilidade;

            // Atribundo a disponibilidade a apresentacao
            cout << "Disponibilidade: " << listaResultados.back() << endl;
            disponibilidade.setValor(listaResultados.back());
            listaResultados.pop_back();
            apresentacao->setDisponibilidade(disponibilidade);

            // Atribuindo o numero de sala a apresentacao
            cout << "numeroDeSala: " << listaResultados.back() << endl;
            numeroDeSala.setValor(listaResultados.back());
            listaResultados.pop_back();
            apresentacao->setNumeroDeSala(numeroDeSala);

            // Atribuindo preco a apresentacao
            cout << "Preco: " << listaResultados.back() << endl;
            preco.setValor(listaResultados.back());
            listaResultados.pop_back();
            apresentacao->setPreco(preco);

            // Atribuindo  o horario a apresentacao
            cout << "Horario: " << listaResultados.back() << endl;
            horario.setValor(listaResultados.back());
            listaResultados.pop_back();
            apresentacao->setHorario(horario);

            // Atribuindo a data na apresentacao
            cout << "Data: " << listaResultados.back() << endl;
            data.setValor(listaResultados.back());
            listaResultados.pop_back();
            apresentacao->setData(data);

            // Gambiarra por enquanto
            string aux_cod;
            aux_cod = listaResultados.back();
            int str_length = listaResultados.back().length();
            for (int i = 0; i < 4 - str_length; i++)
                aux_cod = "0" + aux_cod;
            //Atribuindo o codigo a apresentacao
            cout << "codigo: " << aux_cod << endl;
            codigo.setValor(aux_cod);
            listaResultados.pop_back();
            apresentacao->setCodigo(codigo);


            // Retirando o codigo de evento, pois não é usado na apresentacao
            listaResultados.pop_back();

            listaApresentacao.push_back(*apresentacao);

            delete apresentacao;
        }
    } catch (...) {
        return false;
    }
    return false;
}

// Metodos auxiliares de Servico Eventos
bool ModelEventos::criarEvento(CPF cpf, Evento evento, list<Apresentacao> listaApresentacao) {
    // Primeiramente verificar se o usuario nao possui mais que o limite de eventos
    if (this->isLimiteEventos(cpf) && listaApresentacao.size() <= LIMITE_APRESENTACAO) {
        comandoSQL = "INSERT INTO evento VALUES (";
        comandoSQL += "'" + cpf.getValor() + "', ";
        comandoSQL += "'" + evento.getCodigo().getValor() + "',";
        comandoSQL += "'" + evento.getNome().getValor() + "',";
        comandoSQL += "'" + evento.getCidade().getValor() + "',";
        comandoSQL += "'" + evento.getEstado().getValor() + "',";
        comandoSQL += "'" + evento.getClasse().getValor() + "',";
        comandoSQL += "'" + evento.getFaixa().getValor() + "');";
        // Adicionar apresentacoes depois
        try {
            // Executa o comando mysql
            this->executar();
            adicionarApresentacoes(evento.getCodigo(), listaApresentacao);
            return true;
        } catch (...) {
            // Se der falha ao executar o comando
            cout << "Falha ao criar evento" << endl;
            return false;
        }

    } else {
        // Como mostrar para o usuario esse erro?
        cout << "Falha ao criar envento:Limite de eventos" << endl;
        return false;
    }
}

bool ModelEventos::verificaDataApresentacao(list<Evento> &listaEventos, Data dataInicio, Data dataTermino) {
    for (auto evento : listaEventos) {
        comandoSQL = "SELECT * FROM apresentacao WHERE data >= ";
        comandoSQL += "'" + dataInicio.getValor() + "' AND data <= ";
        comandoSQL += "'" + dataTermino.getValor() + "' AND codigo_evento =";
        comandoSQL += "'" + evento.getCodigo().getValor() + "';";
        try {
            this->executar();
            int tam = (listaResultados.size() / 7);
            for (int i = 0; i < tam; i++) {
                Apresentacao apresentacao;
                CodigoDeApresentacao codigo;
                Data data;
                Horario horario;
                Preco preco;
                NumeroDeSala numeroDeSala;
                Disponibilidade disponibilidade;
            }
        } catch (...) {

        }
    }

    return false;
}

void ModelEventos::adicionarApresentacoes(CodigoDeEvento codigo, list<Apresentacao> listaApresentacao) {
    for (Apresentacao apresentacao: listaApresentacao) {
        try {
            comandoSQL = "INSERT INTO apresentacao VALUES (";
            comandoSQL += "'" + codigo.getValor() + "', ";
            comandoSQL += "'" + apresentacao.getCodigo().getValor() + "',";
            comandoSQL += "'" + apresentacao.getData().getValor() + "',";
            comandoSQL += "'" + apresentacao.getHorario().getValor() + "',";
            comandoSQL += "'" + apresentacao.getPreco().getValor() + "',";
            comandoSQL += "'" + apresentacao.getNumeroDeSala().getValor() + "',";
            comandoSQL += "'" + apresentacao.getDisponibilidade().getValor() + "');";
            this->executar();
        } catch (...) {

        }
    }
}

bool ModelEventos::isLimiteEventos(CPF cpf) {
    // Verifica se o usuario tem um numero maior ou igual de eventos permitidos
    comandoSQL = "SELECT COUNT(*) FROM evento WHERE cpf_usuario =";
    comandoSQL += "'" + cpf.getValor() + "';";
    try {
        this->executar();
        // Se tem menos evento que o limite
        if (atoi(listaResultados.back().c_str()) < LIMITE_EVENTOS) {
            listaResultados.clear();
            return true;
        } else {
            listaResultados.clear();
            return false;
        }
    } catch (...) {
        return false;
    }
}

bool ModelEventos::isUsuarioDono(CPF cpf, CodigoDeEvento codigo) {
    comandoSQL = "SELECT (cpf_usuario) FROM evento WHERE codigo = ";
    comandoSQL += "'" + codigo.getValor() + "';";
    try {
        listaResultados.clear();
        this->executar();
        return listaResultados.back() == cpf.getValor();
    } catch (...) {
        return false;
    }
}

bool ModelEventos::jaVendeu(CodigoDeEvento codigo) {
    list<CodigoDeApresentacao> listaCodigoApr;
    comandoSQL = "SELECT (codigo_apresentacao) FROM apresentacao WHERE codigo_evento =";
    comandoSQL += "'" + codigo.getValor() + "';";
    try {
        listaResultados.clear();
        this->executar();
        CodigoDeApresentacao codigoDeApresentacao;
        for (int i = 0; i < listaResultados.size(); i++) {
            codigoDeApresentacao.setValor(listaResultados.back());
            listaCodigoApr.push_back(codigoDeApresentacao);
            listaResultados.pop_back();
        }

        for (auto apr : listaCodigoApr) {
            comandoSQL = "SELECT COUNT(*) FROM ingresso WHERE codigo_apresentacao =";
            comandoSQL += "'" + apr.getValor() + "'";
            listaResultados.clear();
            this->executar();
            cout << "Quantidade de Ingressos " << listaResultados.back() << endl;
            if (stod(listaResultados.back()) > 0) {
                return true;
            }
        }
    } catch (...) {
        return true;
    }
    return false;
}