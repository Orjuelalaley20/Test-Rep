#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct nodo
{
    int dato;
    nodo *siguiente;
};

int main(int argc, char const *argv[])
{
    ifstream entrada("ciudades.txt");
    char *linea =  new char[255];
    if (!entrada)
    {
        cout <<"no se pudo abrir el archivo de texto";
    }
    else
    {
        while (entrada)
        {
            entrada.getline(linea,300,'\n');
            cout << linea<<"\n";
        }
    }
    entrada.close();
    return 0;
}

