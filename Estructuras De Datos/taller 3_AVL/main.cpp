#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "arbolAVL.h"
using namespace std;

typedef ArbolAVL<int> TarbolAVL;

//---------------------------------------------------------------

template <class TTree>
bool readTree(TTree &tree, string filename);

//--------------------------------------------------------------

int main()
{
  string archivo = "archivoPrueba.txt";
  TarbolAVL arbolAVL;
  bool llenar_arbol = ReadTree(arbolAVL,archivo);
  if (!llenar_arbol)
  {
    cout <<"error al usar : "<< archivo;
  }else{
    arbolAVL.altura();
  }
  
  return 0;
}
//------------------------------------------------------------------------------

template <class TTree>
bool ReadTree(TTree &tree, string filename)
{
  ifstream archivo(filename.c_str());
  string code;
  int value;
  bool status;
  if (!archivo)
  {
    return(false);
  }
  else
  {
    while (!archivo.eof())
    {
      archivo >> code >> value;
      if (code == 'A')
      {
        status = tree.insertar(value);
      }
      else if (code == 'E')
      {
        status = tree.eliminar(value);
      }
    }
    archivo.close();
    return(true);
  }
}