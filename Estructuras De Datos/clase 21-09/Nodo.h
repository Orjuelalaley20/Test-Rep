#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
using namespace  std;

enum Color {ROJO, NEGRO};
struct Nodo
{
    int dato;
    bool color;
    Nodo *izquierdo, *derecho,*padre;
    Nodo(int dato)
    {
        this->dato = dato;
        izquierdo = derecho = padre = nullptr;
        this->color = ROJO;
    }
};
#endif

