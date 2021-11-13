#include "nodo.h"
#include <iostream>
using namespace std;
struct ArbolAVL
{
    Nodo *raiz;
    ArbolAVL()
    {
        raiz = nullptr;
    }
    void insertar(int info)
    {
        if (raiz == nullptr)
        {
            raiz = new Nodo();
            raiz->padre = nullptr;
            raiz->altura = 0;
            raiz->dato = info;
        }
        else
        {
            Nodo *nodoPadre = raiz;
            Nodo *nuevoNodo = new Nodo();
            nuevoNodo->dato = info;
            while (nodoPadre != nullptr)
            {
                if (info > nodoPadre->dato)
                {
                    if (nodoPadre->derecha == nullptr)
                    {
                        nuevoNodo->altura = 0;
                        nuevoNodo->padre = nodoPadre;
                        nodoPadre->derecha = nuevoNodo;
                        cout << "inserto el elemento " << info << " a la derecha \n";
                        break;
                    }
                    else
                        nodoPadre = nodoPadre->derecha;
                }
                else
                {
                    if (nodoPadre->izquierda == nullptr)
                    {
                        nuevoNodo->altura = 0;
                        nuevoNodo->padre = nodoPadre;
                        nodoPadre->izquierda = nuevoNodo;
                        cout << "inserto el elemento " << info << " a la izquierda \n";
                        break;
                    }
                    else
                        nodoPadre = nodoPadre->izquierda;
                }
            }
        }
    }
    void preorden(Nodo *aux)
    {
        if (aux == nullptr)
        {
            return;
        }
        cout << "--" << aux->dato;
        preorden(aux->izquierda);
        preorden(aux->derecha);
    }
};
