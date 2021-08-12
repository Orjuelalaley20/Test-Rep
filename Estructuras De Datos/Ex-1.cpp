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

    while ((aux1 != NULL) && (aux1 -> dato < n ))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (Lista == aux1)
    {
        Lista = nuevo_nodo;
    }
    else
        aux2->siguiente =  nuevo_nodo;

    nuevo_nodo->siguiente = aux1;
    cout << "\t elemento "<<n<<" insertado a la lista correctamente\n";
}
int main(int argc, char const *argv[])
{
    nodo *lista = NULL;
    int dato;

    cout <<"digite un numero : ";
    cin >> dato;
    insertarLista(lista,dato);
    cout <<"digite un numero : ";
    cin >> dato;
    insertarLista(lista,dato);
    cout <<"digite un numero : ";
    cin >> dato;
    insertarLista(lista,dato);
    return 0;
}
