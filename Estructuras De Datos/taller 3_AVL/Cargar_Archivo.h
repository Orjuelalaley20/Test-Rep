#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "arbolAVL.h"
#include <cstring>
using namespace std;




void CargarArchivo(string nomarchivo)
{
    char linea[20];
    TarbolAVL ArbolAVL;
    vector<string> vec;
    int conta = 0;
    int num = 0;
    const char *delim = " ";
    
    ifstream archivo(nomarchivo);
    string error = "error en la lectura del archivo";
    if (!archivo)
    {
        cout <<"no se pudo abrir el archivo";
    }else{
        while (archivo)
        {
            archivo.getline(linea, 20, '\n');

            if (linea[0] == 'A')
            {
                string s(1, linea[2]);
                num = stoi(s);

                
            }else if (linea[0] == 'E')
            {
                cout <<"eliminaito\n";
            }
        }
    }
    archivo.close();
}