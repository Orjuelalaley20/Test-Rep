#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *siguiente;
};

struct lista
{
    nodo *cabeza;
    nodo *cola;
    nodo *espacio;
    lista()
    {
        cabeza = NULL;

        cola = NULL;
    }
    void Adicionar(int valor)
    {
        nodo *temp = new nodo;
        temp->dato = valor;
        temp->siguiente = NULL;

        if (cabeza == NULL)
        {
            cabeza = temp;
            cola = temp;
        }
        else
        {
            cola->siguiente = temp;
            cola = cola->siguiente;
        }
    }

    void Mostrar()
    {
        nodo *temp = new nodo;
        temp = cabeza;
        while (temp != NULL)
        {
            cout << temp->dato << endl;
            temp = temp->siguiente;
        }
    }

    void BorrarPrimerdato()
    {
        if(cabeza ==  NULL)
        {
            
            cout <<"La lista esta vacia";
            return;
        }
    }
    void Insertarenlista(int Dato, int pos)
    {
        nodo *temp = new nodo;
        temp->dato = Dato;
        for (int i = 0; i < 10; i++)
        {
            /* code */
        }
        
        cout <<cabeza<<endl;
        cout <<cola<<endl;
    }
};


int main(int argc, char const *argv[])
{
    lista primera;
    int ops,valins;
    primera.Adicionar(100);
    primera.Adicionar(299);
    cout << "Tenemos una lista enlazada "<<endl;
    cout<<"digite el valor a insertar : ";
    cin >>valins;
    cout <<"digite el espacio donde desea ingresar el dato\n";
    cout <<"1. cabeza\n";
    cout <<"2. cola\n";
    cin >> ops;
    primera.Insertarenlista(valins,ops);
    return 0;
}
