//
// Created by pedro on 15/05/19.
//

#include "include/viewUsuario.h"
#include "include/controladora.h"
#include <QApplication>
#include <QPushButton>
#include "include/Builder.h"

int main(int argc, char *argv[])
{
    auto model = new Model();
    model->criarTabelas();

    CPF cpf;
    QApplication a(argc, argv);

    Controladora control;
    Builder builder;
    builder.build(&control);
    int result;
    while (1){
        control.executar();
        result = a.exec();
        if (result == 0 && control.isNotInMenu == 1){
            control.isNotInMenu = 0;
        }
        else if(control.isNotInMenu == 0 && result == 0){
            break;
        }
        else if (control.isNotInMenu==0){
            break;
        }
    }
    delete model;
    return 0;
}
