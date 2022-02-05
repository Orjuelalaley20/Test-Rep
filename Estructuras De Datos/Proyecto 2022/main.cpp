#include <bits/stdc++.h>
#include "Funtions.cxx"
using namespace std;

int main()
{
    // Cadenas
    char comando[500];

    // Apuntadores
    char *cad;

    // Vectores
    vector<string> com;

    do
    {
        cout << "$ ";
        cin.getline(comando, 500);

        cad = strtok(comando, " ");
        while (cad != NULL)
        {
            com.push_back(cad);
            cad = strtok(NULL, " ");
        }

        if (com[0] == "cargar_imagen")
        {
            Cargar_imagen(com[1]);
            com.clear();
        }
        else if (com[0] == "ayuda")
        {
            Ayuda();
        }
        else if (com[0] == "salir")
        {
            cout << "  Termina la ejecucion de la aplicacion." << endl;
            com.clear();
            break;
        }
        else
        {
            cout << "  comando no existente" << endl;
            com.clear();
        }
    } while (com[0] != "salir");

    return 0;
}