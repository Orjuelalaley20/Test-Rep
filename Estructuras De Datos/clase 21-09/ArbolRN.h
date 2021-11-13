#include "Nodo.h"
#include <iostream>
using namespace std;

struct ArbolRN
{
    Nodo *raiz;
    void insertar(int info)
    {
        Nodo *Nodonuevo = new Nodo(info);
        AjustarBalance(raiz, Nodonuevo);
    }
    void preorden(Nodo *aux)
    {
        if (aux == nullptr)
        {
            return;
        }
        cout << "-- " << aux->dato;
        preorden(aux->izquierdo);
        preorden(aux->derecho);
    }
    void rotarIzquierda(Nodo *&r, Nodo *&n);
    void rotarDerecha(Nodo *&r, Nodo *&n);
    void AjustarBalance(Nodo *&r, Nodo *&n);
    ArbolRN()
    {
        raiz = nullptr;
    }

    void inorden();
};

