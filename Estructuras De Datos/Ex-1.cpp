#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *siguiente;
};

void insertarLista(nodo *&Lista, int n)
{
    nodo *nuevo_nodo =  new nodo();
    nuevo_nodo->dato = n;
    nodo *aux1 = Lista;
    nodo *aux2;
}


int main(int argc, char const *argv[])
{
    nodo *lista = NULL;
    return 0;
}
