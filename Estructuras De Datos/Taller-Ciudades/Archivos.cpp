#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
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
    void ordenar()
    {
        Nodo *actual = cabeza;
        while (actual != NULL)
        {
            Nodo *siguiente = actual->siguiente;
            insertarordenado(actual);
            actual = siguiente;
        }
        cabeza = cola;
        
    }
    void insertarordenado(Nodo *nuevo_nodo)
    {
        if(cola == NULL || cola->dato >= nuevo_nodo->dato)
        {
            nuevo_nodo->siguiente = cola;
            cola =  nuevo_nodo;
        }
        else
        {
            Nodo *actual = cola;
            while (actual->siguiente != NULL && actual->siguiente->dato < nuevo_nodo->dato)
            {
                actual = actual->siguiente;
            }
            nuevo_nodo->siguiente = actual->siguiente;
            actual->siguiente = nuevo_nodo;
        }
        
        
    }
    void crearnuevoarch()
    {
        fstream salida("ciudadesOrdenadas.txt", ios::app);
        if (!salida)
        {
            cout << "no se pudo entrar/crear el archivo binario ";
        }
        else
        {
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
                    ciudades.mostrarlista();
                    cout << "\n";
                    ciudades.ordenar();
                    cout << "Lista ordenada" << endl;
                }
            }
            entrada.close();
            break;
        case 2:

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