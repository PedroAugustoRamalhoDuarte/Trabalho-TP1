// Created by pedro on 13/06/19.
//

#ifndef TRABALHOTP1_MODELVENDAS_H
#define TRABALHOTP1_MODELVENDAS_H


#include "Model.h"

class ModelVendas : public Model, public ISVendas {
public:
    void listarApresentacao(list<CodigoDeApresentacao> &listCodigosApr) override;

    void listarEventos(list<CodigoDeEvento> &listCodigoEve, CPF cpf) override;

    bool adquirirIngresso(CPF cpf, CodigoDeApresentacao codigo, int quantidade) override;

    void vendasDoEvento(CodigoDeEvento codigoDeEvento,
                        list<pair<CodigoDeApresentacao, int>> &tabelaQtdIngressos) override;

    void vendasPorCpf(CodigoDeApresentacao codigoDeApresentacao, list<pair<CPF, int>> &tabelaCpfIngressos) override;

    ModelVendas();
};

#endif //TRABALHOTP1_MODELVENDAS_H
