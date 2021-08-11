#include <list>
#include <iostream>
using namespace std;
template <class T>
void imprimirLista(list<T> g)
{
    cout << "{";
    for (T elem : g)
    {
        cout << " | " << elem;
    }
    cout <<"}\n"; 
}
int main(int argc, char const *argv[])
{
    list<int> L1;
    list<string> L2;
    for (int i = 0; i < 10; i++)
    {
        L1.push_back(i); //adiciona elementos al final de la lista
    }
    imprimirLista(L1);
    L2.push_back("Sebastian");
    L2.push_back("Esteban");
    L2.push_back("Diana");
    L2.push_back("Sergio");
    imprimirLista(L2);
    L2.reverse();
    L1.sort();
    return 0;
}
