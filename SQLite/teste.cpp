#include "BdController.h"
using namespace std;

// Compilar essa parada aq:  g++ teste.cpp BdController.cpp ../source/Entidades.cpp ../source/Dominios.cpp -l sqlite3
int main()
{
    auto* bdzin = new BdController();
    bdzin->criarTabelas();
    delete(bdzin);
    return 0;
}
