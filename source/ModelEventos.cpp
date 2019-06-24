#include "include/ModelEventos.h"

// --------------------------------------------------------------------------
// Model Servico Eventos

// Construtor
ModelEventos::ModelEventos() : Model() {}

// Metodos da Interface Serviço Eventos
void ModelEventos::meusEventos(list<Evento> &listaEventos, CPF cpf) {
    comandoSQL = "SELECT * FROM evento WHERE cpf_usuario = ";
    comandoSQL += "'" + cpf.getValor() + "';";
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
        faixa.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setFaixa(faixa);

        // Atribuindo a classe ao evento
        classe.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setClasse(classe);

        // Atribuindo o estado ao evento
        estado.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setEstado(estado);

        // Atribuindo a cidade ao evento
        cidade.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setCidade(cidade);


        // Atribuindo o nome ao evento
        nome.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setNome(nome);

        //Atribuindo o codigo ao evento
        codigo.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setCodigo(codigo);

        // Retirando o CPF, pois não é usado no Evento
        listaResultados.pop_back();


        listaEventos.push_back(*evento);

        delete evento;
    }
}

void ModelEventos::alterarEvento(CPF cpf, Evento evento) {
    comandoSQL = "UPDATE evento SET nome = ";
    comandoSQL += "'" + evento.getNome().getValor() + "', classe = ";
    comandoSQL += "'" + evento.getClasse().getValor() + "', faixa_etaria = ";
    comandoSQL += "'" + evento.getFaixa().getValor() + "', estado = ";
    comandoSQL += "'" + evento.getEstado().getValor() + "', cidade = ";
    comandoSQL += "'" + evento.getCidade().getValor() + "' WHERE codigo = ";
    comandoSQL += "'" + evento.getCodigo().getValor() + "';";
    this->executar();
}

bool ModelEventos::descadastrarEvento(CPF cpf, CodigoDeEvento codigo) {
    // Se chamar o método pela meus eventos o usuário já é o dono
    if (isUsuarioDono(cpf, codigo)) {
        if (!jaVendeu(codigo)) {
            // Excluindo o Evento
            comandoSQL = "DELETE from evento WHERE codigo = ";
            comandoSQL += "'" + codigo.getValor() + "';";
            this->executar();

            // Excluindo as apresentações do evento
            comandoSQL = "DELETE from apresentacao WHERE codigo_evento = ";
            comandoSQL += "'" + codigo.getValor() + "';";
            this->executar();
            return true;
        } else {
            // Erro ao descadastrar usuário já vendeu ingresso
            return false;
        }
    } else {
        return false;
    }
}

void ModelEventos::pesquisarEventos(list<Evento> &listaEventos, Data dataInicio, Data dataTermino, Cidade cidade,
                                    Estado estado) {
    comandoSQL = "SELECT * FROM evento WHERE cidade =";
    comandoSQL += "'" + cidade.getValor() + "' AND estado = ";
    comandoSQL += "'" + estado.getValor() + "';";
    listaResultados.clear();
    this->executar();
    int tam = (listaResultados.size() / 7);
    for (int i = 0; i < tam; i++) {
        auto evento = new Evento();
        CodigoDeEvento codigo;
        NomeDeEvento nome;
        Cidade cidadeAux;
        Estado estadoAux;
        ClasseDeEvento classe;
        FaixaEtaria faixa;

        // Atribundo a faixa etaria ao evento
        faixa.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setFaixa(faixa);

        // Atribuindo a classe ao evento
        classe.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setClasse(classe);

        // Atribuindo o estado ao evento
        estadoAux.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setEstado(estadoAux);

        // Atribuindo a cidade ao evento
        cidadeAux.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setCidade(cidadeAux);


        // Atribuindo o nome ao evento
        nome.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setNome(nome);

        //Atribuindo o codigo ao evento
        codigo.setValor(listaResultados.back());
        listaResultados.pop_back();
        evento->setCodigo(codigo);

        // Retirando o CPF, pois não é usado no Evento
        listaResultados.pop_back();


        listaEventos.push_back(*evento);

        delete evento;
    }

    // Falta Concluir a lógica
    this->verificaDataApresentacao(listaEventos, dataInicio, dataTermino);
}

void ModelEventos::mostrarApresentacao(list<Apresentacao> &listaApresentacao, CodigoDeEvento codigoDeEvento) {
    comandoSQL = "SELECT * FROM apresentacao WHERE codigo_evento =";
    comandoSQL += "'" + codigoDeEvento.getValor() + "' ;";

    // Limpando a lista de resultados
    listaResultados.clear();
    this->executar();
    int tam = (listaResultados.size() / 7);
    for (int i = 0; i < tam; i++) {
        auto apresentacao = new Apresentacao();
        CodigoDeApresentacao codigo;
        Data data;
        Horario horario;
        Preco preco;
        NumeroDeSala numeroDeSala;
        Disponibilidade disponibilidade;

        // Atribundo a disponibilidade a apresentacao
        disponibilidade.setValor(listaResultados.back());
        listaResultados.pop_back();
        apresentacao->setDisponibilidade(disponibilidade);

        // Atribuindo o numero de sala a apresentacao
        numeroDeSala.setValor(listaResultados.back());
        listaResultados.pop_back();
        apresentacao->setNumeroDeSala(numeroDeSala);

        // Atribuindo preco a apresentacao
        preco.setValor(listaResultados.back());
        listaResultados.pop_back();
        apresentacao->setPreco(preco);

        // Atribuindo  o horario a apresentacao
        horario.setValor(listaResultados.back());
        listaResultados.pop_back();
        apresentacao->setHorario(horario);

        // Atribuindo a data na apresentacao
        data.setValor(listaResultados.back());
        listaResultados.pop_back();
        apresentacao->setData(data);

        //Atribuindo o codigo a apresentacao
        codigo.setValor(listaResultados.back());
        listaResultados.pop_back();
        apresentacao->setCodigo(codigo);

        // Retirando o codigo de evento, pois não é usado na apresentacao
        listaResultados.pop_back();

        listaApresentacao.push_back(*apresentacao);

        delete apresentacao;
    }
}

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
        // Adiciona o evento no bd
        this->executar();

        // Adiciona as apresentações no bd
        adicionarApresentacoes(evento.getCodigo(), listaApresentacao);
        return true;
    } else {
        // Como mostrar para o usuario esse erro?
        cout << "Falha ao criar envento:Limite de eventos" << endl;
        return false;
    }
}

// Métodos Auxiliares
void ModelEventos::adicionarApresentacoes(CodigoDeEvento codigo, list<Apresentacao> listaApresentacao) {
    for (Apresentacao apresentacao: listaApresentacao) {
        comandoSQL = "INSERT INTO apresentacao VALUES (";
        comandoSQL += "'" + codigo.getValor() + "', ";
        comandoSQL += "'" + apresentacao.getCodigo().getValor() + "',";
        comandoSQL += "'" + apresentacao.getData().getValor() + "',";
        comandoSQL += "'" + apresentacao.getHorario().getValor() + "',";
        comandoSQL += "'" + apresentacao.getPreco().getValor() + "',";
        comandoSQL += "'" + apresentacao.getNumeroDeSala().getValor() + "',";
        comandoSQL += "'" + apresentacao.getDisponibilidade().getValor() + "');";
        this->executar();
    }
}

bool ModelEventos::isLimiteEventos(CPF cpf) {
    // Verifica se o usuario tem um numero maior ou igual de eventos permitidos
    comandoSQL = "SELECT COUNT(*) FROM evento WHERE cpf_usuario =";
    comandoSQL += "'" + cpf.getValor() + "';";

    this->executar();
    // Se tem menos evento que o limite
    if (atoi(listaResultados.back().c_str()) < LIMITE_EVENTOS) {
        listaResultados.clear();
        return true;
    } else {
        listaResultados.clear();
        return false;
    }

}

bool ModelEventos::isUsuarioDono(CPF cpf, CodigoDeEvento codigo) {
    comandoSQL = "SELECT (cpf_usuario) FROM evento WHERE codigo = ";
    comandoSQL += "'" + codigo.getValor() + "';";
    listaResultados.clear();
    this->executar();
    return listaResultados.back() == cpf.getValor();
}


bool ModelEventos::verificaDataApresentacao(list<Evento> &listaEventos, Data dataInicio, Data dataTermino) {
    for (auto evento : listaEventos) {
        comandoSQL = "SELECT * FROM apresentacao WHERE data >= ";
        comandoSQL += "'" + dataInicio.getValor() + "' AND data <= ";
        comandoSQL += "'" + dataTermino.getValor() + "' AND codigo_evento =";
        comandoSQL += "'" + evento.getCodigo().getValor() + "';";
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
    }

    return false;
}


bool ModelEventos::jaVendeu(CodigoDeEvento codigo) {
    list<CodigoDeApresentacao> listaCodigoApr;
    comandoSQL = "SELECT (codigo_apresentacao) FROM apresentacao WHERE codigo_evento =";
    comandoSQL += "'" + codigo.getValor() + "';";

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

    return false;
}