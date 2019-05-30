//
// Created by pedro on 15/05/19.
//

#include "include/viewUsuario.h"
#include "include/controladora.h"
#include <QApplication>
#include <QPushButton>
#include "./include/View.h"
int main(int argc, char *argv[])
{
    CPF cpf;
    QApplication a(argc, argv);

    Controladora control;
    control.show();
    while (1){
        control.show();
        if (!a.exec() && control.flag == 1)
            control.flag = 0;
        else if(!a.exec() && control.flag == 0)
            break;

    }
    return a.exec();
}
