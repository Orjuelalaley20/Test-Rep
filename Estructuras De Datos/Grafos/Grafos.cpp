#include <iostream>
#include <list>

using namespace std;
struct grafo
{
    int v;
    list<int> *listAdy;
    grafo(int n)
    {
        v = n;
        listAdy = new list<int>[n];
    }
    void insertarAristas(int a, int b)
    {
        listAdy[a].push_back(b);
    }
    
};

void mostrarAristas(list <int> lista[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout <<i<<" --> ";
        list <int>:: iterator it;
        for (it = lista[i].begin(); it != lista[i].end();++it)
        {
            cout << *it << " --> ";
        }
        
    }
    
}
int main()
{
    grafo g1(5);
    g1.insertarAristas(0,1);
    g1.insertarAristas(0,4);
    g1.insertarAristas(1,4);
    g1.insertarAristas(1,2);
    g1.insertarAristas(1,3);
    g1.insertarAristas(2,1);
    g1.insertarAristas(2,3);
    g1.insertarAristas(1,3);

    cout <<"El conjunto V de vertices es: \n";

    cout <<"El conjunto A de es : \n";
    mostrarAristas(g1.listAdy, g1.v);
    return 0;
}
