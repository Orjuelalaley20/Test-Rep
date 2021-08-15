#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Nodo
{
    string dato;
    Nodo *siguiente;
};
struct lista
{
    Nodo *cabeza;
    Nodo *cola;
    lista()
    {
        cabeza = NULL;
        cola = NULL;
    }
    void InsertarLista(string n)
    {
        Nodo *nuevo_nodo = new Nodo();
        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = NULL;
        if (cabeza == NULL)
        {
            cabeza = nuevo_nodo;
            cola = nuevo_nodo;
        }
        else
        {
            cola->siguiente = nuevo_nodo;
            cola = cola->siguiente;
        }
    }
    void mostrarlista()
    {
        Nodo *actual = new Nodo();
        actual = cabeza;
        while (actual != NULL)
        {
            cout << actual->dato << " | \n";
            actual = actual->siguiente;
        }
    }
};

void menu()
{
    int opcion;
    lista ciudades;
    ifstream entrada("ciudades.txt");
    string linea;
    do
    {
        cout << "Menu\n";
        cout << "1. leer archivo y cargar la lista\n";
        cout << "2. Mostrar las ciudades en la lista\n";
        cout << "3. salir\n";
        cout << "opcion :";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            if (!entrada)
            {
                cout << "no se pudo abrir el archivo de texto";
            }
            else
            {
                while (entrada)
                {
                    while (getline(entrada, linea))
                    {
                        ciudades.InsertarLista(linea);
                    }
                    cout << "Elementos "
                         << "insertados en la lista correctamente\n";
                }
            }
            entrada.close();
            break;
        case 2:
            ciudades.mostrarlista();
            cout << "\n";
            break;
        default:
            break;
        }
    } while (opcion != 3);
}
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}