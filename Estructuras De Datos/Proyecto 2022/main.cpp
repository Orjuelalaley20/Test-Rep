#include <bits/stdc++.h>
using namespace std;

void Cargar_imagen(){

}
void Info_imagen(){
    
}
void Info_volumen(){

}
void proyeccion2D(){

}

void Ayuda(){
    cout << "**********BIENVENIDO DIVIPOLA COLOMBIA********** " << endl;
    cout << " ->COMANDOS  PERMITIDOS " << endl;
    cout << " carga_divipola nombre_archivo" << endl;
    cout << " listar_departamentos" << endl;
    cout << " listar_municipios codigo_depto" << endl;
    cout << " listar_poblaciones codigo_municipio" << endl;
    cout << " info_sumaria codigo_depto" << endl;
    cout << " carga_SC  nombre_archivo" << endl;
    cout << " esta_en_sistema codigo_municipio" << endl;
    cout << " salida" << endl;
}

int main()
{
    char comando[100];
    bool valido = true;
    do
    {
        cout << "$ ";
        cin >> comando;
        if (strncmp(comando, "salida", 6) == 0)
        {
            return 0;
        }
        if (strncmp(comando, "cargar_imagen", 13) == 0)
        {
            Cargar_imagen();
        }
        if (strncmp(comando, "info_imagen",11) == 0)
        {
            Info_imagen();
        }
        if (strncmp(comando, "info_volumen", 12) == 0)
        {
            Info_volumen();
        }
        if (strncmp(comando, "proyeccion2D", 12) == 0)
        {
            proyeccion2D();
        }
        if (strncmp(comando, "ayuda", 5) == 0)
        {
            Ayuda();
        }
    } while (comando != "salida");
}