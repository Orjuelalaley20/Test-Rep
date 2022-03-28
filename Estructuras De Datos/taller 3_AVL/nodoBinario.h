#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

#include <iostream>
#include <list>
#include <utility>

template< class T >
class nodoBinario {
  protected:
    T dato;
    nodoBinario<T> *hijoIzq;
    nodoBinario<T> *hijoDer;
    int altura;
  public:
    //constructores
    nodoBinario();
    nodoBinario(T& val);
    nodoBinario(T& val, nodoBinario<T> *izq, nodoBinario<T> *der);
    //destructor
    ~nodoBinario();
    //manipuladores del nodo
    bool esHoja();
    T& obtenerDato();
    nodoBinario<T>* obtenerHijoIzq();
    nodoBinario<T>* obtenerHijoDer();
    int obtenerAltura();
    void fijarDato(T& val);
    void fijarHijoIzq(nodoBinario<T> *izq);
    void fijarHijoDer(nodoBinario<T> *der);
    void fijarAltura(int& h);
    //operaciones del arbol
    void preOrden(std::list< std::pair< T, int > >& listapre);
    std::string nodoBinario<T>::preOrden();
    void inOrden(std::list< std::pair< T, int > >& listain);
    void inOrdenHasta(std::list< std::pair< T, int > >& lista, int tam, int nivel);
    void posOrden(std::list< std::pair< T, int > >& listapos);
    void nivelOrden();
    bool buscar(T& val);
    bool insertar(T& val, nodoBinario<T> **nraiz);
    bool eliminar(T& val, nodoBinario<T> **nraiz);
    T& minimo();
    T& maximo();
    int tamano(int aux,int hijoDer,int hijoIzq,int media);
    void actualizarAlturas();
    nodoBinario<T>* balanceoArbol ();
  private:
    nodoBinario<T>* rotDerecha();
    nodoBinario<T>* rotIzquierda();
    nodoBinario<T>* rotIzquierdaDerecha();
    nodoBinario<T>* rotDerechaIzquierda();
};
    
#include "nodoBinario.hxx"

#endif // __NODOBINARIO__H__

// eof - nodoBinario.h

