#include <iostream>
#include <list>

using namespace std;
struct grafo
{
    int v;
    bool **matrizAdy;
    grafo(int n)
    {
        v = n;
        matrizAdy = new bool *[v];
        for (int i = 0; i < v; i++)
        {
            matrizAdy[i] =  new bool[v];
            for (int j = 0; j < v; j++)
            {
                matrizAdy[i][j] = false;
            }
        }
        
    }
    void insertarAristas(int a, int b)
    {
        matrizAdy[a][b] = true;
    }
    void borrarAristas();
};
