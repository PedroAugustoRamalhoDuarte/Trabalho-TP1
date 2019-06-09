//
// Created by pedro on 15/05/19.
//

#include "include/viewUsuario.h"
#include "include/controladora.h"
#include <QApplication>
#include <QPushButton>
#include "./include/View.h"
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
    //control.executar();
    int result;
    while (1){
        control.executar();
        result = a.exec();
        cout << "CONTROL FLAG:";
        cout <<  control.flag << endl;
        //cout << result << endl;
        cout << "LOOP PRINCIPAL" << endl;
        if (result == 0 && control.flag == 1){
            control.flag = 0;
            //cout<<"test"<<endl;
            //cout<<control.flag<<endl;
        }
        else if(control.flag == 0 && result == 0){
            //cout<<"break";
            break;
        }
        else if (control.flag==0){
            //cout<<"break";
            break;
        }
    }
    return 0;
}
