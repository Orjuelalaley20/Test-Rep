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
        cout << "{";
        while (actual != NULL)
        {

            cout << actual->dato << " |  ";
            actual = actual->siguiente;
        }
        cout << "}\n";
    }
    void ordenar()
    {
        cola = NULL;
        Nodo *actual = cabeza;
        while (actual != NULL)
        {
            Nodo *siguiente = actual->siguiente;
            insertarordenado(actual);
            actual = siguiente;
        }
        cabeza = cola;
    }
    /*El algoritmo que utilizamos para hacer el ordenamiento de la lista fue Shell Sort
    porque este nos parecio que iba mas acorde a la logica de programacion que implementamos en el codigo
    */
    void insertarordenado(Nodo *nuevo_nodo)
    {
        if (cola == NULL || cola->dato >= nuevo_nodo->dato)
        {
            nuevo_nodo->siguiente = cola;
            cola = nuevo_nodo;
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
    void NuevoArchivo()
    {
        fstream salida("ciudadesOrdenadas.txt", ios::app);
        Nodo *actual = new Nodo();
        actual = cabeza;
        if (!salida)
        {
            cout << "no se pudo entrar/crear el archivo binario ";
        }
        else
        {
            while (actual != NULL)
            {
                salida << actual->dato << " \n";
                actual = actual->siguiente;
            }
            cout << "archivo creado con exito \n";
            salida.close();
        }
    }
    int Buscar(string nombusc)
    {
        Nodo *actual = new Nodo();
        actual = cabeza;
        int posicion = 0;
        while ((actual != NULL) && (actual->dato <= nombusc))
        {
            if (actual->dato == nombusc)
            {
                return posicion;
            }
            else
            {
                actual = actual->siguiente;
                posicion++;
            }
        }
        return 0;
    }
};
void menu()
{
    int opcion;
    ifstream entrada("ciudades.txt");
    string linea, nombrebusc;
    lista ciudades;
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
                        ciudades.InsertarLista(linea);
                    }
                    ciudades.mostrarlista();
                    cout << "\n";
                }
            }
            entrada.close();
            break;
        case 2:
            ciudades.ordenar();
            cout << "Lista ordenada" << endl;
            ciudades.mostrarlista();
            ciudades.NuevoArchivo();
            cout << "\n";
            break;
        case 3:
            cin.ignore();
            cout << "Ingrese el nombre de la ciudad la cual desea consultar su posicion : ";
            getline(cin, nombrebusc);
            system("clear");
            if (ciudades.Buscar(nombrebusc) != 0)
            {
                cout << "la posicion en la lista de la ciudad " << nombrebusc << " es : " << ciudades.Buscar(nombrebusc) << "\n";
            }
            else
                cout << "El nombre de la ciudad no se encuentra en la lista o esta mal escrito ";
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
