#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    stack <char> pila;
    char expreInfija[100];
    char *apchar = expreInfija;
    cout <<"Digite la expresion aritmetica : ";
    cin >>expreInfija;
       while (!pila.empty())
    {
        cout <<pila.top();
        pila.pop();
    }
    cout <<" en binario \n";
    
    
    return 0;
}
