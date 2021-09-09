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
};

/*
comando: carga_divipola nombre_archivo
salida en pantalla:
(Archivo vacío) “nombre_archivo ” no contiene datos.
(carga exitosa) Se cargaron correctamente x departamentos, y municipios y z centros poblados
desde “nombre_archivo ”.
(problemas en la carga) No se pudo cargar correctamente la información desde “nombre_archivo 
descripción: Carga en una o más estructuras de datos en memoria el contenido del archivo 
identificado por nombre_archivo.
*/
void Capturar(list<string> departamentos)
{
    
    string linea;
    char cadena[300];
    ifstream entrada("ArchivosDivipola.txt");
    if (!entrada)
    {
        cout << "no se pudo abrir el archivo de texto";
    }
    else
    {

        getline(entrada, linea);
        if (linea == "D")
        {
            getline(entrada, linea);
            cout << "bandera";
        }
    }
    entrada.close();
}
void listar(list<string> lista)
{
        for (string n : lista)
        {
            cout << n << "\n";
        }
}
void menu()
{
    int opcion;
    list<string> departamentos;
    do
    {
        cout << "Menu\n";
        cout << "1. Cargar archivo Divipola\n";
        cout << "2. Listar Departamentos\n";
        cout << "3. Listar Municipios\n";
        cout << "4. Listar Poblaciones\n";
        cout << "5. Informacion Sumaria\n";
        cout << "6. Cargar archivo Sistema Ciudades\n";
        cout << "7. Esta en sistema\n";
        cout << "8. Salir\n";
        cout << "opcion :";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            Capturar(departamentos);
            break;
        case 2:
            
            listar(departamentos);
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            cout << "el programa se va a cerrar. \n";
            break;

        default:
            break;
        }
    } while (opcion != 8);
}

int main()
{

    menu();
    return 0;
}