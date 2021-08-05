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
    lista()
    {
       cabeza = NULL;
       cola =  NULL;
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
        cout<< temp->dato<<endl;
        temp = temp->siguiente;
    }
    
}
};

int main(int argc, char const *argv[])
{
    lista primera;
    primera.Adicionar(100);
    primera.Adicionar(299);
    cout << "Tenemos una lista enlazada, ";
    return 0;
}

