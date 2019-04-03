#include <iostream>
#include <stdio.h>
#include "../teste_chacon/Teste.h"
int main() {
    TesteCPF* teste = new TesteCPF();
    cout << teste->run();
    return 0;
}