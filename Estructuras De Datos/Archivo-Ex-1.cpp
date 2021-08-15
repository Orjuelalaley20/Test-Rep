#include <iostream>
#include <fstream>

using namespace std;
enum TEmpresa  {claro, tigo, movistar, etb};
const char *nombreEmpresa[] = {"claro","Tigo", "Movistar", "ETB"};
struct Celular
{
    char numero[11];
    TEmpresa saldo;
    TEmpresa empresa;
    void escribir(Celular m)
    {
        cout << "numero : " <<m.numero<<"\n";
        cout << "empresa : " <<nombreEmpresa[m.empresa]<<"\n";
        cout << "Saldo :" <<m.saldo<<"\n";
    }
    TEmpresa empresa(char c)
    {
        TEmpresa result;
        switch (c)
        {
        case 'C':
            result =  claro;
            break;
        case 'M':
            result =  movistar;
        case 'E':
            result = etb;
        case 'T':
            result = tigo;
        default:
            break;
        }
    }
};
int main(int argc, char const *argv[])
{
    ifstream entrada("Celulares.txt");
    Celular celular;
    char caracter;
    if (!entrada)
    {
        cout <<"no se pudo abrir el archivo de texto";
        exit(EXIT_FAILURE);
    }
    else
    {   
        entrada >> celular.numero;
        while(!entrada.eof())
        {
            entrada >> caracter;
            //celular.empresa =  empresa(caracter);

            //entrada >> celular.saldo;

            //escribe(celular);
            entrada >> celular.numero;
        }
    }
    entrada.close();
    return 0;
}
