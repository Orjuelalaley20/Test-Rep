#ifndef __Crockery__H__
#include <string>
#define __Crockery__H__
using namespace std;

struct Crockery
{
  string name;
  unsigned long num_crockery;
};

void SetName(string n_nombre);
string GetCrockery();
unsigned long Get_NumCrockery();


#endif // libro
