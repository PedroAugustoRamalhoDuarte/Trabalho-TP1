//
// Created by pedro on 15/05/19.
//

#include "mainwindow.h"
#include "controladora.h"
#include <QApplication>
#include <QPushButton>
#include "./include/View.h"
int main(int argc, char *argv[])
{
    CPF cpf;
    QApplication a(argc, argv);

    Controladora control;
    control.show();
    a.exec();
    cout << "passou main" << endl;
    control.show();
    a.exec();

    return 0;
}
