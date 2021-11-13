#include <bits/stdc++.h>
using namespace std;
struct Poblado{
    int cod;
    string nombre;
    double longi;
    double lati;
};

struct Municipio{
    int cod;
    string nombre;
    vector<Poblado>pob;
};

struct Departamento{
    int cod;
    string nombre;
    vector<Municipio>mun;
};
