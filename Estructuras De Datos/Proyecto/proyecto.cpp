#include <bits/stdc++.h>
#include "estructura.h"
using namespace std;
vector<Departamento> dept;
void cargar(string archivo)
{
    ifstream arch(archivo);
    char linea[100];
    char *lin;
    Departamento reg_D;
    Municipio reg_M;
    Poblado reg_P;
    vector<string> tempo;
    if (!arch)
    {
        cout << "No se pudo cargar correctamente la información desde " << archivo << " \n";
    }
    else
    {
        while (!arch.eof())
        {
            arch.getline(linea, 100, '\n');
            lin = strtok(linea, ",");
            while (lin != NULL)
            {
                tempo.push_back(lin);
                lin = strtok(NULL, ",");
            }
            
            cout << dept[reg_D.cod].cod;
            for (int i = 0; i < dept.size(); i++)
            {
                cout << i;
            }

            // reg_P.longi = stod(tempo[8]);
            // reg_P.lati = stod(tempo[7]);
            // reg_P.nombre = tempo[5];
            // reg_P.cod = stod(tempo[4]);
            // reg_M.pob.push_back(reg_P);
            // reg_M.nombre = tempo[3];
            // reg_M.cod = stoi(tempo[2]);
            // reg_D.mun.push_back(reg_M);
            // reg_D.nombre = tempo[1];
            // reg_D.cod = stoi(tempo[0]);
            // dept.push_back(reg_D);
            tempo.clear();
        }
        arch.close();
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
        if (comsep[0] == "carga_divipola")
        {
            cargar(comsep[1]);
            comsep.clear();
        }

        else if (comsep[0] == "ayuda")
        {
            cout << " carga_divipola nombre_archivo" << endl;
            cout << " listar_departamentos" << endl;
            cout << " listar_municipios codigo_depto" << endl;
            cout << " listar_poblaciones codigo_municipio" << endl;
            cout << " info_sumaria codigo_depto" << endl;
            cout << " carga_SC  nombre_archivo" << endl;
            cout << " esta_en_sistema codigo_municipio" << endl;
            cout << " salida" << endl;
            comsep.clear();
        }
        else
        {
            cout << "comando incorrecto\n";
        }

    } while (comsep[0] != "salir");

    return 0;
}
