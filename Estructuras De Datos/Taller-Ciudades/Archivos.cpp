#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <list>
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
};
// void ordenar()
// {
//     cola = NULL;
//     Nodo *actual = cabeza;
//     while (actual != NULL)
//     {
//         Nodo *siguiente = actual->siguiente;
//         insertarordenado(actual);
//         actual = siguiente;
//     }
//     cabeza = cola;
// }
// void insertarordenado(Nodo *nuevo_nodo)
// {
//     if (cola == NULL || cola->dato >= nuevo_nodo->dato)
//     {
//         nuevo_nodo->siguiente = cola;
//         cola = nuevo_nodo;
//     }
//     else
//     {
//         Nodo *actual = cola;
//         while (actual->siguiente != NULL && actual->siguiente->dato < nuevo_nodo->dato)
//         {
//             actual = actual->siguiente;
//         }
//         nuevo_nodo->siguiente = actual->siguiente;
//         actual->siguiente = nuevo_nodo;
//     }
// }
void NuevoArchivo(list<string> ciudades)
{
    fstream salida("ciudadesOrdenadas.txt", ios::app);
    if (!salida)
    {
        cout << "no se pudo entrar/crear el archivo binario ";
    }
    else
    {
       for (string n: ciudades)
       {
           salida << n <<" | ";
       }
        cout << "archivo creado \n";
        salida.close();
    }
}
// void Buscar(string nombusc)
// {
//     int conta = 0;
//     for (string e :)
//     {
//         if (e == nombusc)
//         {
//             cout << conta;
//         }
//         else
//             conta++;
//     }
// }
void menu()
{
    int opcion;
    ifstream entrada("ciudades.txt");
    string linea;
    list<string> ciudades;
    do
    {
        cout << "Menu\n";
        cout << "1. leer archivo y cargar la lista\n";
        cout << "2. Ordenar las ciudades en la lista e escribirlas en un nuevo archivo \n";
        cout << "3. Buscar ciudad\n";
        cout << "4. salir\n";
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
                        ciudades.push_back(linea);
                    }
                    cout << "{ ";

                    for (string d : ciudades)
                    {
                        cout << " | " << d;
                    }
                    cout << " }\n";
                }
            }
            entrada.close();
            break;
        case 2:
            ciudades.sort();
            cout << "Lista ordenada" << endl;
            for (string d : ciudades)
            {
                cout << " | " << d << "\n";
            }
            cout << "\n";
            NuevoArchivo(ciudades);
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (opcion != 4);
}
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}