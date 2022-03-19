#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void mostrarLista(list<int> lista,int ob){
    list<int>::iterator it;
    list<int>::iterator aux;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        
        /*for (; ; ++aux)
        {
            cout << *aux << endl;
        }*/
    }
}
int main(int argc, char const *argv[])
{
    list<int> lista;
    int ob = 10;
    lista.push_back(2);
    lista.push_back(5);
    lista.push_back(8);
    lista.push_back(11);
    mostrarLista(lista,ob);
    return 0;
}
