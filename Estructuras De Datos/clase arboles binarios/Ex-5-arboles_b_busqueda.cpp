#include <vector>
#include "ArbolAVL.h"
using namespace std;

int main()
{
    ArbolAVL arbol1;
    arbol1.insertar(53);
    arbol1.insertar(31);
    arbol1.insertar(12);
    arbol1.insertar(34);
    arbol1.insertar(57);
    arbol1.insertar(56);
    arbol1.insertar(69);
    arbol1.insertar(68);
    arbol1.insertar(80);
    arbol1.insertar(5);
    arbol1.preorden(arbol1.raiz);
    return 0;
}


