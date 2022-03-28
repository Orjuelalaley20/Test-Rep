#ifndef __ARBOLAVL__H__
#define __ARBOLAVL__H__

#include <iostream>
#include "nodoBinario.h"
#include <list>
#include <utility>

template <class T>
class ArbolAVL
{
protected:
  NodoBinarioAVL<T> *raiz;

public:
  // constructores
  ArbolAVL();
  ArbolAVL(T &val);
  // destructor
  ~ArbolAVL();
  // manipuladores del arbol
  bool esVacio();
  T &datoRaiz();
  void fijarRaiz(nodoBinario<T> *n_raiz);
  nodoBinario<T> *obtenerRaiz();
  // operaciones del arbol
  void preOrden();
  void inOrden();
  void inOrdenHasta(std::list<std::pair<T, int>> &lista, int tam);
  void posOrden();
  void nivelOrden();
  bool buscar(T &val);
  bool insertar(T &val);
  bool eliminar(T &val);
  T &minimo();
  T &maximo();
  int altura();
  int tamano(int aux, int der, int izq, int media) int altura();
  int dato;
  Nodo *der;
  Nodo *izq;
  Nodo *padre;
};

#include "arbolAVL.hxx"

#endif // __ARBOLAVL__H__

// eof - ArbolAVL.h
