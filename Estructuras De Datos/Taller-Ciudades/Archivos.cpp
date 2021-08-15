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
    actual = lista;
    while (actual != NULL)
    {
        cout << actual->dato<<" | \n";
        actual = actual->siguiente;
    }
}
void InsertarLista(Nodo *&lista, string n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n))
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
    mostrarlista(lista);
}
void menu()
{
    int opcion;
    Nodo *lista = NULL;
    ifstream entrada("ciudades.txt");
    string linea;
    do
    {
        cout <<"Menu\n";
        cout <<"1. leer archivo y cargar la lista\n";
        cout <<"2. Mostrar las ciudades en la lista\n";
        cout <<"3. salir";
    } while (opcion != 3);

    switch (opcion)
    {
    case 1:
        
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
        break;
    
    default:
        break;
    }
    
}
int main(int argc, char const *argv[])
{
    
    return 0;
}