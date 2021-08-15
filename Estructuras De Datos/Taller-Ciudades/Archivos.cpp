#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Nodo
{
    string dato;
    Nodo *siguiente;
};
void mostrarlista(Nodo *lista)
{
    Nodo *actual = new Nodo();

}
void InsertarLista(Nodo *&lista, string n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato > n))
    {
        aux2 =  aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
    
    
}

int main(int argc, char const *argv[])
{
    ifstream entrada("ciudades.txt");
    string linea;
    Nodo *lista = NULL;
    if (!entrada)
    {
        cout <<"no se pudo abrir el archivo de texto";
    }
    else
    {
        while (entrada)
        {
            while(getline(entrada,linea)){
                InsertarLista(lista,linea);
            }
            cout <<"Elementos " <<"insertados en la lista correctamente\n";
        }
    }
    entrada.close();
    return 0;
}