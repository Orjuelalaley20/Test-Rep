#include <iostream>
#include <fstream>

using namespace std;

struct Celular
{
    char numero[11];
    float valor;
    char empresa;
};


int main(int argc, char const *argv[])
{
    ofstream archivo;
    archivo.open("archivo.txt");
    archivo << "primera linea\n";
    archivo << "segunda linea\n";
    archivo << "tercera linea\n";
    archivo.close();
    cout <<"archivo creado con exito !\n";
    cout <<"------------------------------\n";
    ifstream entrada("archivo.txt");
    char *linea = new char[30];
    if (!entrada)
    {
        cout <<"no se pudo abrir el archivo de texto";

    }
    else
    {
        while (entrada)
        {
            entrada.getline(linea,30,'\n');
            cout << linea<<"\n";
        }
    }
    entrada.close();

    return 0;
}
