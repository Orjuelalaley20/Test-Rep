#include <vector>
#include "ArbolAVL.h"
using namespace std;

int main()
{
    ArbolAVL arbol1;

    arbol1.insertar(43);
    arbol1.insertar(22);
    arbol1.insertar(18);
    arbol1.preorden(arbol1.raiz);
    return 0;
}


