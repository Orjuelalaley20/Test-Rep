#include <stack>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> pila;
    int numDecimal = 27; 
    int base = 2;
    cout <<numDecimal << " en decimal = ";
    while (numDecimal != 0)
    {
        int residuo = numDecimal%base;
        int cociente = numDecimal/base;
        pila.push(residuo);
        numDecimal = cociente;
    }
    while (!pila.empty())
    {
        cout << pila.top();
        pila.pop();
    }
    cout << " en binario "<<endl;
    return 0;
}
