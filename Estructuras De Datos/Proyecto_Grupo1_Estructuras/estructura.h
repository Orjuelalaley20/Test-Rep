#include <bits/stdc++.h>
using namespace std;

struct stDepartamento
{
    int codigo;
    string nombre;
};
struct stMunicipio
{
    stDepartamento departamento;
    int codigo;
    string nombre;
    string tipo;
};
struct stPoblado
{
    stMunicipio municipio;
    stDepartamento departamento;
    int codigo;
    string nombre;
    string tipo;
};
struct stDivipola
{
    vector<stDepartamento> Vdepartamentos;
    vector<stMunicipio> Vmunicipios;
    vector<stPoblado> Vpoblado;
 };
 struct stSistemaCuidades
 {
     vector<stDepartamento> Vdepartamentos;
     vector<stMunicipio> Vmunicipios;
 };
