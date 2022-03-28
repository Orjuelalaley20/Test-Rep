#include "arbolAVL.h"
#include <iostream>

// ------------------------------------------------------------------------
template <class T>
ArbolAVL<T>::ArbolAVL()
{
    this->raiz = NULL;
}

// ------------------------------------------------------------------------
template <class T>
ArbolAVL<T>::ArbolAVL(T &val)
{
    this->raiz = new NodoBinarioAVL<T>(val);
}

// ------------------------------------------------------------------------
template <class T>
ArbolAVL<T>::~ArbolAVL()
{
    if (this->raiz != NULL)
    {
        delete this->raiz;
        this->raiz = NULL;
    }
}

// ------------------------------------------------------------------------
template <class T>
bool ArbolAVL<T>::esVacio()
{
    return (this->raiz == NULL);
}

// ------------------------------------------------------------------------
template <class T>
T &ArbolAVL<T>::datoRaiz()
{
    return (this->raiz)->obtenerDato();
}

// ------------------------------------------------------------------------
template <class T>
void ArbolAVL<T>::fijarRaiz(nodoBinario<T> *n_raiz)
{
    this->raiz = n_raiz;
}

//------------------------------------------------------------------------
template <class T>
nodoBinario<T> *ArbolAVL<T>::obtenerRaiz()
{
    return this->raiz;
}

// ------------------------------------------------------------------------
template <class T>
void ArbolAVL<T>::preOrden()
{
    if (this->raiz != NULL)
        this->raiz->preOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template <class T>
void ArbolAVL<T>::inOrden()
{
    if (this->raiz != NULL)
        this->raiz->inOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template <class T>
void ArbolAVL<T>::inOrdenHasta(std::list<std::pair<T, int>> &lista, int tam)
{
    if (this->raiz != NULL)
    {
        this->raiz->inOrdenHasta(lista, tam);
    }
    if (lista.size() < tam)
    {
        lista.push_back(std::make_pair(this->dato));
    }
}

// ------------------------------------------------------------------------
template <class T>
void ArbolAVL<T>::posOrden()
{
    if (this->raiz != NULL)
        this->raiz->posOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template <class T>
void ArbolAVL<T>::nivelOrden()
{
    if (this->raiz != NULL)
        this->raiz->nivelOrden();
    std::cout << std::endl;
}

// ------------------------------------------------------------------------
template <class T>
bool ArbolAVL<T>::buscar(T &val)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else if (raiz->dato == dato)
    {
        return raiz;
    }
    else if (raiz->dato < dato)
    {
        return buscar(dato, raiz->derecho);
    }
    else if (raiz->dato > dato)
    {
        return buscar(dato, raiz->izquierdo);
    }
}

// ------------------------------------------------------------------------
template <class T>
bool ArbolAVL<T>::insertar(T &val)
{
    bool res = false;
    if (this->raiz = !NULL)
    {
        this->raiz = new nodoBinario<T>(val);
        res = true;
    }
    else
    {
        nodoBinario<T> *nraiz = this->raiz;
        res = this->raiz->insertar(val, &nraiz);
        this->raiz = nraiz;
    }
    return res;
}

// ------------------------------------------------------------------------
template <class T>
bool ArbolAVL<T>::eliminar(T &val)
{
}

// ------------------------------------------------------------------------
template <class T>
T &ArbolAVL<T>::minimo()
{
    if (ArbolAVL.size() == NULL)
    {
        return NULL;
    }
    if (ArbolAVL()->izq)
    {                                   // Si tiene hijo izquierdo
        return minimo(ArbolAVL()->izq); // retorna el hijo izquierdo
    }
    else
    {                      // Si no tiene hijo izquierdo (significa que él es el más izquierdo)
        return ArbolAVL(); // se retorna a sí mismo
    }
}

// ------------------------------------------------------------------------
template <class T>
T &ArbolAVL<T>::maximo()
{
    if (ArbolAVL.size() == NULL)
    {
        return NULL;
    }
    if (ArbolAVL()->der)
    {                                   // Si tiene hijo derecho
        return minimo(ArbolAVL()->der); // retorna el hijo derecho
    }
    else
    {
        return ArbolAVL(); // se retorna a sí mismo
    }
}

// ------------------------------------------------------------------------
template <class T>
int ArbolAVL<T>::tamano(int aux, int der, int izq, int media)
{
    if (aux != NULL)
    {
        der = tamano(aux->der)
            izq = tamano(aux->izq)
                media = tamano(aux->media)
    }
    return tamano(media);
}

// ------------------------------------------------------------------------
template <class T>
int ArbolAVL<T>::altura()
{

    int alturaDerecha = 0;
    int alturaIzquierda = 0;
    int max = 0;

    if (alturaDerecha != nullptr)
    {
        alturaDerecha = altura(this->hijoDer);
    }

    if (alturaIzquierda != nullptr)
    {
        alturaIzquierda = altura(this->hijoIzq);
    }

    int alturatotal = max(alturaDerecha, alturaIzquierda);
    return alturatotal + 1;
}

// eof - ArbolAVL.hxx
