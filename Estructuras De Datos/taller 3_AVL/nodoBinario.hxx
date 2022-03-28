#include <queue>
#include <list>
// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>::nodoBinario() {
    this->dato = NULL;
}

// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>::nodoBinario(T& val){
    
}

// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>::nodoBinario(T& val, nodoBinario<T> *izq, nodoBinario<T> *der) {
}

// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>::~nodoBinario() {
    if (this->dato != NULL)
    {
        delete this->dato;
        this->dato = NULL;
    }
}

// ------------------------------------------------------------------------
template< class T >
bool nodoBinario<T>::esHoja() {
    return this->dato;
}

// ------------------------------------------------------------------------
template< class T >
T& nodoBinario<T>::obtenerDato() {
    return this->dato;
}

// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>* nodoBinario<T>::obtenerHijoIzq() {
    return this->hijoIzq
}

// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>* nodoBinario<T>::obtenerHijoDer() {
    return this->hijoDer;
}

// ------------------------------------------------------------------------
template< class T>
int nodoBinario<T>::obtenerAltura() {
    return (this->dato)->fijarAltura(int& h);
}


// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::fijarDato(T& val) {
    this->dato = val;
}

// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::fijarHijoIzq(nodoBinario<T> *izq) {
    this->hijoIzq = izq;
}

// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::fijarHijoDer(nodoBinario<T> *der) {
    this->hijoDer = der;
}

// ------------------------------------------------------------------------
template< class T>
void nodoBinario<T>::fijarAltura(int& h) {
    this->altura = h;
}

// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::preOrden(std::list< std::pair< T, int > >& listapre){
    if(this->hijoIzq != NULL){
        this->hijoIzq->preOrden(std::list< std::pair< T, int > >& listapre);
    }
    if(this->hijoDer != NULL){
        this->hijoDer->preOrden(std::list< std::pair< T, int > >& listapre);
    }
}


// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::inOrden(std::list< std::pair< T, int > >& listain) {
    if(this->hijoIzq != NULL){
        this->hijoIzq->inOrden(std::list< std::pair< T, int > >& listain);
    }
    if(this->hijoDer != NULL){
        this->hijoDer->inOrden(std::list< std::pair< T, int > >& listain);
    }
}

// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::inOrdenHasta(std::list< std::pair< T, int > >& lista, int tam, int nivel)
{
    if (this->raiz != NULL){
        this->raiz->inOrdenHasta(lista, tam, nivel+1);
    }
    if(lista.size()<tam){
        lista.push_back(std::make_pair(this->dato, nivel));
    }
}
// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::posOrden(std::list< std::pair< T, int > >& listapos) {
    if(this->hijoIzq != NULL){
        this->hijoIzq->posOrden(std::list< std::pair< T, int > >& listapos);
    }
    if(this->hijoDer != NULL){
        this->hijoDer->posOrden(std::list< std::pair< T, int > >& listapos);
    }
}

// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::nivelOrden() {
}

// ------------------------------------------------------------------------
template< class T >
bool nodoBinario<T>::buscar(T& val) {
    nodoBinario<T> *p = this;
    bool encontrar = false;
    while(p != NULL && encontrar == false){
        if(val < p->dato){
            p = p->hijoIzq
        }
        if(val > p->dato){
            p = p->hijoDer
        }
        encontrar = true;
    }
    return encontrar;

}

// ------------------------------------------------------------------------
template< class T >
bool nodoBinario<T>::insertar(T& val, nodoBinario<T> **nraiz) {
    bool respuesta = false;
{
    if(this->nraiz =! NULL){
        this->nraiz = new nodoBinario<T>(val);
        respuesta = true;
    }
    else{
        nodoBinario<T> **nraiz = this->nraiz;
        res = this->nraiz->insertar(val, nraiz);
        this->nraiz = nraiz;
    }
    return respuesta;
}
}


// ------------------------------------------------------------------------
template< class T >
bool nodoBinario<T>::eliminar(T& val, nodoBinario<T> **nraiz) {
      if (nraiz == NULL) {
        return;
    }
    else if (this->dato < hijoIzq) { //Si el valor es menor
        eliminar(dato->hijoIzq); // Busca por la izquierda
    }
    else if (this->dato > hijoDer) { // Si el valor es mayor
        eliminar(arbol->hijoDer); //Busca por la derecha
    }
    else {
        eliminar();
    }
  }

// ------------------------------------------------------------------------
template< class T >
T& nodoBinario<T>::minimo() {
    if (nodoBinario.size() == NULL) {
        return NULL;
    }
    if (nodoBinario()->hijoIzq) { // Si tiene hijo izquierdo
        return minimo(nodoBinario()->hijoIzq); // retorna el hijo izquierdo
    }
    else { // Si no tiene hijo izquierdo (significa que él es el más izquierdo)
        return nodoBinarioL(); // se retorna a sí mismo
    }
}

// ------------------------------------------------------------------------
template< class T >
T& nodoBinario<T>::maximo() {
    if (nodoBinario.size() == NULL) {
        return NULL;
    }
    if (nodoBinario()->hijoDer) { // Si tiene hijo derecho
        return minimo(ArbolAVL()->hijoDer); // retorna el hijo derecho
    }
    else {
        return ArbolAVL(); // se retorna a sí mismo
    }
}

// ------------------------------------------------------------------------
template< class T >
int nodoBinario<T>::tamano(int aux,int hijoDer,int hijoIzq,int media) {
    if(aux != NULL){
        hijoDer = tamano(aux->hijoDer)
        hijoIzq = tamano(aux->hijoIzq)
        media = tamano(aux->media)
    }
    return tamano(media);

}

// ------------------------------------------------------------------------
template< class T >
void nodoBinario<T>::actualizarAlturas() {
    int ai= -1;
    int ad= -1;
    if(this->hijoIzq == NULL && this->hijoDer == NULL){
        this->altura = 0;
    }
    if(this->hijoIzq != NULL){
        this->hijoIzq->actualizarAlturas();
        ai = this->hijoIzq->altura;
    }
   if(this->hijoDer != NULL){
        this->hijoDer->actualizarAlturas();
        ad = this->hijoDer->altura;
    }
    if(ai > id){
        this->altura = ai+1;
        this->altura = ad+1;
    }

}

// ------------------------------------------------------------------------
template< class T >
nodoBinario<T>* nodoBinario<T>::balanceoArbol() { }

// ------------------------------------------------------------------------
template< class T>
nodoBinario<T>* nodoBinario<T>::rotDerecha() {} 

// ------------------------------------------------------------------------
template< class T>
nodoBinario<T>* nodoBinario<T>::rotIzquierda() {}

// ------------------------------------------------------------------------
template< class T>
nodoBinario<T>* nodoBinario<T>::rotIzquierdaDerecha() {
}

// ------------------------------------------------------------------------
template< class T>
nodoBinario<T>* nodoBinario<T>::rotDerechaIzquierda() {} 

// eof - nodoBinario.hxx
