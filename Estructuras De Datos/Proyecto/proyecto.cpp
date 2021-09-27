#include <bits/stdc++.h>
#include "estructura.h"
using namespace std;
list<Departamento> dept;
void cargar(string archivo){

    ifstream arch(archivo);
    if (arch.is_open()){
        while (!arch.eof()){
        }
        arch.close();
    }
    else{
        cout << "no se puede establecer la comunicacion con el archivo ";
        system("pause");
    }
}
int main()
{
    char comando[200];
    char *cad;
    vector<string> comsep;
    do
    {
        cout << "$ ";
        cin.getline(comando, 200);
        cad = strtok(comando, " ");
        while (cad != NULL)
        {
            comsep.push_back(cad);
            cad = strtok(NULL, " ");
        }
        if(comsep[0] == "carga_divipola"){
            cargar(comsep[1]);
        }

    } while (comsep[0] != "salir");

    return 0;
}
