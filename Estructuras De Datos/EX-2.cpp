#include <list>
#include <iostream>
using namespace std;
void imprimirLista(list<string> g)
{
    cout << "{";

    for (string d : g)
    {
        cout << " | " << d;
    }
    cout <<"}\n"; 
}

void buscar(list<string> g)
{
    string nombusc = "Sergio";
    int conta = 0;
    for (string e : g)
    {
        if (e == nombusc)
        {
            cout <<conta;
        }
        else
            conta++;
    }
}
int main(int argc, char const *argv[])
{
    list<string> L2;
    string nombre;
    L2.push_back("Sebastian");
    L2.push_back("Esteban");
    L2.push_back("Diana");
    L2.push_back("Sergio");
    imprimirLista(L2);
    buscar(L2);
    return 0;
}
