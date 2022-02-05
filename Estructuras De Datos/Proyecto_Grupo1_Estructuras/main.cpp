#include <bits/stdc++.h>
using namespace std;
#include "estructura.h"

void carga_divipola (){
    ifstream archivo("divipola.txt");
    char lineaActual[200];
    string linea;
    int totalD=0, totalM=0, totalC=0;
    if(!archivo){
        cout << " no se encuentra el archivo";
    }
    else{
        while(archivo){
            while(getline(archivo,linea)){
              if(linea == "DEPARTAMENTOS"){
                while(getline(archivo,linea) && linea != "MUNICIPIOS"){
                  totalD++;
                  strcpy(lineaActual,linea.c_str());
                }
              }
              else if(linea == "MUNICIPIOS"){
                while(getline(archivo,linea) && linea != "CENTROS POBLADOS"){
                  totalM++;
                  strcpy(lineaActual,linea.c_str());
                  cout << lineaActual;
                }
              }
              else if(linea == "CENTROS POBLADOS"){
                while(getline(archivo,linea)){
                  totalC++;
                  strcpy(lineaActual,linea.c_str());
                }
              }
            }
        }
        cout << "se cargo el archivo correctamente con " << totalD << " departamentos, " << totalM << " municipios y " << totalC << " centros poblados.\n";
    }
}

void carga_SC (){
    ifstream archivo("SC.txt");
    char lineaActual[200];
    string linea;
    int totalM=0, totalC=0;
    if(!archivo){
        cout << " no se encuentra el archivo";
    }
    else{
        while(archivo){
            while(getline(archivo,linea)){
              if(linea == "MUNICIPIOS"){
                while(getline(archivo,linea) && linea != "CENTROS POBLADOS"){
                  totalM++;
                  strcpy(lineaActual,linea.c_str());
                  cout << lineaActual;
                }
              }
              else if(linea == "CENTROS POBLADOS"){
                while(getline(archivo,linea)){
                  totalC++;
                  strcpy(lineaActual,linea.c_str());
                }
              }
            }
        }
        cout << "se cargo el archivo correctamente con " << totalM << " municipios y " << totalC << " centros poblados.\n";
    }
}
// void insertar (char* linea, stDepartamento Depa){

// }

 int main(){
     char comando[100];
     bool valido= true;
     do{
        cout << "**********BIENVENIDO DIVIPOLA COLOMBIA********** "<<endl;
     cout << " ->COMANDOS  PERMITIDOS "<< endl;
     cout <<" carga_divipola nombre_archivo" << endl;
     cout <<" listar_departamentos" << endl;
     cout <<" listar_municipios codigo_depto"<< endl;
     cout <<" listar_poblaciones codigo_municipio"<<endl;
     cout <<" info_sumaria codigo_depto"<<endl;
     cout <<" carga_SC  nombre_archivo"<<endl;
     cout <<" esta_en_sistema codigo_municipio"<<endl;
     cout <<" salida"<<endl;
    //while (valido==true){
        cout <<"$ ";
        cin>>comando;
        if(strncmp(comando,"salida",6) == 0){
            return 0;
        }

            //entrada de dato de la divipola
       if(strncmp(comando,"carga_divipola",14) == 0){
            carga_divipola();
        }
        //listar los departamentos
        if(strncmp(comando,"listar_departamentos",20) == 0){

        }
        //listar municipios
        if(strncmp(comando,"listar_municipios",17) == 0){

        }
        //listar poblaciones
         if(strncmp(comando,"listar_poblaciones",18) == 0){

        }
        //info_sumaria
         if(strncmp(comando,"info_sumaria",12) == 0){

        }
        //carga_SC
          if(strncmp(comando,"carga_SC",8) == 0){
            carga_SC();
        }
        //esta_en_sistema
          if(strncmp(comando,"esta_en_sistema",15) == 0){


        }
     }while(comando!="salida");


 }
