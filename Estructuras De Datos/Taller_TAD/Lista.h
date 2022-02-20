#define __LIST__H__
#include <list>
#include "Crockery_type.h"
using namespace std;

struct Lista
{
    string name;
};

list<Lista> l_size;
void addSize(string n_size);
void AddCrockery(string v_name, unsigned long v_);
unsigned long CountCrockery();
void Print();


