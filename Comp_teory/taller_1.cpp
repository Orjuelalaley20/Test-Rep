#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char correo[318];
    int conta = 0;
    cout << "Introduzca el correo eletronico a analizar : ";
    cin >> correo;
    if (correo[0] == '!')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '#')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '"')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == ')')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '(')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == ',')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == ';')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == ':')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '<')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '>')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '[')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == ']')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '{')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '}')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '/')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '&')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '%')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '"')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '-')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '*')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '~')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '=')
    {
        cout << "buzon de correo eletronico no valido";
    }
    else if (correo[0] == '?')
    {
        cout << "buzon de correo eletronico no valido";
    }
    while (correo[conta] != '@')
    {
        if (correo[conta] == '!' || correo[conta] == '#' ||
        correo[conta] == '=' || correo[conta] =='"')
        {
            cout << "buzon de correo eletronico no valido";
            break;
        }
        conta++;
    }

    return 0;
}
