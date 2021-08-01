#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
//SEBASTIAN ORJUELA SANCHEZ
//ISABELLA BLANCO
using namespace std;
struct Titulares
{

    char *nombre = new char[100];
    char *nacimiento = new char[11];
    int fijo;
    int celular;
    char *dirr = new char[10];
};

struct Cuenta
{
    int saldo;
    bool estado;
    char fecha[11];
    int num_cuenta;
    char *tipo = new char[10];
    Titulares *titular = new Titulares [10];
    int consecutivo;
    int tit;
    int sobregir;
};

/*
Nombre:Crear_cuentas 
Función: Crear por consola cuentas dentro del archivo para posterior ser leidas
Entradas : La funcion recibe la informacion de usuario por consola
Salida: El archivo con una nueva cuenta lista para su lectura
*/

void Crear_cuentas()
{
    Cuenta cuenta_nueva;
    char temp[50];
    int opcion, opcionb,numtitu;
    cout << "El estado de su cuenta empieza como ACTIVA"<<endl;
    ofstream entrada("cuentas.txt", ios::app);
    cout << "Ingrese la cantidad de saldo con el que desea iniciar: ";
    cin >> cuenta_nueva.saldo;
    cout <<"Desea que su cuenta sea ahorros o corriente"<<"\n";
    cout <<"1. Corriente"<<"\n";
    cout <<"2. Ahorros"<<"\n";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    system ("clear");
    switch (opcion)
    {
        case 1:
            strcpy(cuenta_nueva.tipo , "corriente");
            cuenta_nueva.num_cuenta = 0;
            cout <<"Cuantos titulares quiere que tenga la cuenta : ";
            cin >> numtitu;
            cin.ignore();
            for (int i = 0; i < numtitu; i++)   
            {

                cout << "Ingrese su nombre: ";
                cin.getline((cuenta_nueva.titular + i)->nombre, 50, '\n');
                cout << "Ingrese su fecha de nacimiento (aaaa-mm-dd): ";
                cin>>(cuenta_nueva.titular + i)->nacimiento;
                cout << "Ingrese su telefono fijo: ";
                cin >> (cuenta_nueva.titular + i)->fijo;
                cout << "Ingrese su celular: ";
                cin >> (cuenta_nueva.titular + i)->celular;
                cin.ignore();
                cout << "Ingrese su direccion: ";
                cin.getline((cuenta_nueva.titular + i)->dirr, 10, '\n');

            }
            entrada <<'\n';
            entrada <<"#Cuenta\n";
            entrada<<"#Saldo------Tipo------Tarjeta/Sobregiro"<<"\n";
            entrada<<cuenta_nueva.saldo<<"------"<<cuenta_nueva.tipo<<"------"<<cuenta_nueva.num_cuenta;
            entrada<<"\n";
            entrada<<"#Titulares"<<"\n";
            entrada<<"#Nombre------fecha Nacimiento----TelFijo-----Celular---Direccion"<<"\n";
            for (int i = 0; i < numtitu; i++)
            {

                entrada<<(cuenta_nueva.titular + i)->nombre<<" *"<<(cuenta_nueva.titular + i)->nacimiento<<" *"<<(cuenta_nueva.titular + i)->fijo<<" *"<<(cuenta_nueva.titular + i)->celular<<" *"<<(cuenta_nueva.titular + i)->dirr<<"\n";
            }
             system ("clear");
            break;     
        case 2:
            strcpy(cuenta_nueva.tipo , "ahorros");
            cuenta_nueva.num_cuenta = rand()%(999999-111111)+111111;
            cout <<"Cuantos titulares quiere que tenga la cuenta : ";
            cin >> numtitu;
            cin.ignore();
            for (int i = 0; i < numtitu; i++)   
            {
                cout << "Ingrese su nombre: ";
                cin.getline((cuenta_nueva.titular + i)->nombre, 50, '\n');
                cout << "Ingrese su fecha de nacimiento (aaaa-mm-dd): ";
                cin>>(cuenta_nueva.titular + i)->nacimiento;
                cout << "Ingrese su telefono fijo: ";
                cin >> (cuenta_nueva.titular + i)->fijo;
                cout << "Ingrese su celular: ";
                cin >> (cuenta_nueva.titular + i)->celular;
                cin.ignore();
                cout << "Ingrese su direccion: ";
                cin.getline((cuenta_nueva.titular + i)->dirr, 10, '\n');
            }
            entrada <<'\n';
            entrada <<"#Cuenta\n";
            entrada<<"#Saldo------Tipo------Tarjeta/Sobregiro"<<"\n";
            entrada<<cuenta_nueva.saldo<<"------"<<cuenta_nueva.tipo<<"------"<<cuenta_nueva.num_cuenta;
            entrada<<"\n";
            entrada<<"#Titulares"<<"\n";
            entrada<<"#Nombre------fecha Nacimiento----TelFijo-----Celular---Direccion"<<"\n";
            for (int i = 0; i < numtitu; i++)
            {
                entrada<<(cuenta_nueva.titular + i)->nombre<<" *"<<(cuenta_nueva.titular + i)->nacimiento<<" *"<<(cuenta_nueva.titular + i)->fijo<<" *"<<(cuenta_nueva.titular + i)->celular<<" *"<<(cuenta_nueva.titular + i)->dirr<<"\n";
            }
            system ("clear");
            break;
        default:
            cout << "Opcion no valida";
            break;
    }   
    entrada<<"0";
    system("clear");
}
/*
Nombre:Capturar 
Función: Capturar los datos de archivo
Entradas : La funcion captura los datos del archivo
Salida: Los datos son guardados en un vector de estructuras dinamicamente
*/
void Capturar (Cuenta *Reg_C)
{
    fstream archC ("cuentas.txt", ios::in);
    char *linea =new char [300];
    char *info_tok = new char [300];
    char *temp = new char[30];
    int conta = 0; 
    int i = 0, j = 0, k = 0;
    if(!archC)
    {
        cout<<"Error en la apertura del archivo"<<endl;
        cout<<"chupapimuñaño"<<endl;
    }
    else
    {
        while(archC) 
        {
            archC.getline(linea, 300, '\n');

            if (*(linea + 0) != '#' && *(linea + 0) != '0')
            {
                //Si conta es 3 los siguientes datos que esten en la cadena van a ser guardados 
                if(conta == 3)
                {
                    info_tok  = strtok(linea, "*");
                    while ((info_tok != NULL))
                    {   
                        
                        strcpy(((Reg_C+j)->titular + k)->nombre, info_tok);
                        info_tok = strtok(NULL, "*");
                        strcpy(((Reg_C+j)->titular + k)->nacimiento, info_tok);
                        info_tok = strtok(NULL, "*");
                        strcpy(temp, info_tok);
                        ((Reg_C+j)->titular + k)->fijo = atoi(temp);
                        info_tok = strtok(NULL, "*");
                        strcpy(temp, info_tok);
                        ((Reg_C+j)->titular + k)->celular = atoi(temp);
                        info_tok = strtok(NULL, "*");
                        strcpy(((Reg_C+j)->titular + k)->dirr, info_tok);
                        info_tok = strtok(NULL, "*");
                        k++;
                    }
                    (Reg_C + i)->tit = k;
                    
                } 
                else
                {
                    info_tok  = strtok(linea, "-");
                    while (info_tok != NULL)
                    {
                        strcpy(temp, info_tok);
                        (Reg_C+i)->saldo= atoi(temp);
                        conta++;
                        info_tok = strtok(NULL, "-");
                        strcpy((Reg_C+i)->tipo, info_tok);
                        conta++;
                        info_tok = strtok(NULL, "-");
                        strcpy(temp, info_tok);
                        (Reg_C+i)->num_cuenta = atoi(temp);
                        conta++;
                        info_tok = strtok(NULL, "-");
                    }
                }
            }
            if(*(linea+0)=='0')
            {
                (Reg_C + i)->consecutivo = i+1;
                i++;
                j++;
                k = 0;
                conta = 0;
            } 
        }
        
        archC.close();
        delete [] info_tok; 
        delete [] linea;
        delete [] temp;
    }
}
/*
Nombre:Consignar 
Función: Consignar un monto dentro del saldo del usuario
Entradas : el valor a consignar
Salida: La funcion saca el saldo total del usuario 
*/
void Consignar(Cuenta *Reg_C)
{
    bool bandera = false;
    int monto, saldot, entradaC;
    char tipoC [] = "ahorros";
    char tipoC2[] = "corriente";
    cout << "Digite el numero de su cuenta: ";
    cin>>entradaC;
    for (int i = 0; i < (Reg_C + i)->consecutivo; i++)
    {   
        if(entradaC == (Reg_C+ i)->num_cuenta)
        {
            bandera = true;
            if ((strcmp((Reg_C + i)->tipo, tipoC) == 0) && (bandera == true))
            {
                cout << "Ingrese cual es el monto a consignar: ";
                cin >> monto;

                saldot = monto + (Reg_C + i)->saldo;
                (Reg_C + i)->saldo = saldot;
                cout << "Su nuevo saldo es:" << (Reg_C + i)->saldo<<"\n";
            }
            if((strcmp((Reg_C + i)->tipo, tipoC2) == 0) && (bandera == true))
            {
                cout << "Ingrese cual es el monto a consignar : ";
                cin >> monto;

                if (monto > (Reg_C + i)->num_cuenta)
                {
                    saldot = monto - (Reg_C + i)->num_cuenta;
                    (Reg_C + i)->saldo = saldot;
                    cout << "Su nuevo saldo es: "<<(Reg_C + i)->saldo<<"\n";
                }
                else
                {
                    saldot = (Reg_C + i)->num_cuenta - monto;
                    (Reg_C + i)->saldo = saldot;
                    cout << "Su nuevo saldo es: "<<(Reg_C + i)->saldo<<"\n";
                }
            }
        }
    }
    if(!bandera)
        cout <<"no se encontro la cuenta";
}
/*
Nombre:Retirar 
Función: Disminuir el saldo de la cuenta 
Entradas : el valor a retirar
Salida: La funcion saca el saldo total del usuario 
*/
void Retirar (Cuenta *Reg_C)
{
    bool bandera = false;
    int monto, saldot, entradaC;
    char tipoC [] = "ahorros";
    char tipoC2[] = "corriente";
    cout << "Digite el numero de su cuenta: ";
    cin>>entradaC;
    for (int i = 0; i < (Reg_C + i)->consecutivo; i++)
    {
        if(entradaC == (Reg_C+ i)->num_cuenta)
        {
            bandera = true;
            if ((strcmp((Reg_C + i)->tipo, tipoC) == 0) && (bandera))
            {
                cout << "Ingrese cual es el monto a retirar: ";
                cin >> monto;

                if (monto <= (Reg_C + i)->saldo)
                {
                    saldot = (Reg_C + i)->saldo - monto;
                    (Reg_C + i)->saldo = saldot;
                    cout << "Su nuevo saldo es:" << (Reg_C + i)->saldo<<endl;
                }
                else
                {
                    cout << "No tiene fondos para retirar"<<endl;
                }
            }
            if((strcmp((Reg_C + i)->tipo, tipoC2) == 0) && (bandera))
            {
                cout << "Ingrese cual es el monto a retirar: ";
                cin >> monto;

                if (monto <= (Reg_C + i)->saldo)
                {
                    cout << (Reg_C + i)->saldo;
                    saldot = (Reg_C + i)->saldo - monto;
                    cout << "Su nuevo saldo es: "<<saldot;
                }
                else
                {   
                    cout << (Reg_C + i)->num_cuenta;
                    (Reg_C + i)-> num_cuenta = monto - Reg_C->saldo;
                    saldot = 0;
                    cout << "Su nuevo saldo es: "<<saldot;
                    cout << "Su sobregiro a quedado asi: "<< (Reg_C + i) -> num_cuenta;
                }
            }
        }
    }
    if(!bandera)
        cout <<"no se encontro la cuenta"<<endl;
}

void Transferir (Cuenta *Reg_C)
{
    bool bandera = false;
    int enviar, saldot, entradaC, entradaB, cant;
    cout << "Digite el numero de su cuenta: ";
    cin>>entradaC;
    cout << "Ingrese la cuenta a la que quieres transferir: ";
    cin >>entradaB;
    for (int i = 0; i < (Reg_C+i)->consecutivo; i++)
    {
        for (int j = 0; j < (Reg_C+j)->consecutivo; j++)
        {
            if((entradaC == (Reg_C+ i)->num_cuenta)&&(entradaB == (Reg_C+ j)->num_cuenta))
            {
                bandera = true;
                if (bandera)
                {
                    cout << "Ingrese la cantidad de dinero que desea transferir: ";
                    cin >> cant;
                    if (cant <= (Reg_C +i)->saldo)
                    {
                        (Reg_C +i)->saldo = (Reg_C +i)->saldo - cant;
                        enviar = cant;
                        (Reg_C + j)->saldo = (Reg_C + j)->saldo +enviar;
                        cout << "Su nuevo saldo es:" << (Reg_C + i)->saldo<<endl;
                    }
                    else
                        cout << "No tiene fondos para transferir"<<endl;
                }
            }
        }
    }
    if(!bandera)
        cout <<"no se encontraron las cuentas"<<endl;

    delete [] Reg_C;   
}

void Edad(Cuenta *Reg_C)
{
    int entradaC, temp, total, fechaN, fechaA = 2021;
    char *info_tok = new char [300];
    cout <<"Digite el numero de cuenta del que desea saber la informacion: ";
    cin >> entradaC;
    for (int i = 0; i < (Reg_C + i)->consecutivo; i++)
    {   
        if(entradaC == (Reg_C+ i)->num_cuenta)
        {
            for (int k = 0; k < (Reg_C + i)->tit ; k++)
            {
                
                info_tok  = strtok(((Reg_C+ i)->titular + k)->nacimiento, "-");
                fechaN = atoi(info_tok);
                cout << "Titular: " << ((Reg_C+i)->titular + k)->nombre  << ", edad : "<< fechaA - fechaN << " \n";
            }
        }
    }
}

void General(Cuenta *Reg_C)
{
    char imprimir[300];
    int i = 0;
    fstream salida ("informeGeneral.txt", ios::app);
    if (!salida)
    {
        cout<<"no se pudo entrar/crear el archivo binario ";
    }
    else
    {
        while(i != (Reg_C+ i)->consecutivo)
        {
            cout <<(Reg_C + i)->consecutivo;
            salida <<"#Cuenta "<<(Reg_C + i)->consecutivo <<"\n";
            salida<<"#Saldo------Tipo------Tarjeta/Sobregiro"<<"\n";
            salida<<(Reg_C + i)->saldo<<"------"<<(Reg_C + i)->tipo<<"------"<<(Reg_C + i)->num_cuenta;
            salida<<"\n";
            salida<<"#Titulares"<<"\n";
            salida<<"#Nombre------fecha Nacimiento----TelFijo-----Celular---Direccion"<<"\n";
            for (int j = 0; j <(Reg_C + i)->tit; j++)
            {
                salida<<((Reg_C + i)->titular + j)->nombre<<" *"<<((Reg_C + i)->titular + j)->nacimiento<<" *"<<((Reg_C + i)->titular + j)->fijo<<" *"<<((Reg_C + i)->titular + j)->celular<<" *"<<((Reg_C + i)->titular + j)->dirr<<"\n";
            }
            salida <<"0"<<"\n";
            i++;
        }
    }
    /*salida.getline(imprimir, 300, '\n');
    cout <<imprimir;*/
    salida.close(); 
}
int main()
{
    Cuenta *Reg_C = new Cuenta[5];
    int consecutivo = 0;
    int opcion;
    Capturar (Reg_C);
    do {
        system("clear");
        cout <<"---------- MENU DE JAVIBANK ------------\n";
        cout << "1. Crear cuentas y titulares\n";
        cout << "2. Consignar en una cuenta\n";
        cout << "3. Retirar de la cuenta\n";
        cout << "4. Transferir de una cuenta a otra\n";
        cout << "5. Mostrar titulares con su edad\n";
        cout << "6. Mostrar las cuentas que se abrieron antes de esa fecha\n";
        cout << "7. Mostrar toda la informacion de cada una de las cuentas del banco\n";
        cout << "8. Terminar programa";
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        system("clear");

        switch (opcion)
        {
            case 1:
                system("clear");
                Crear_cuentas();
                Capturar (Reg_C);
                break;
            case 2:
                Consignar(Reg_C);
                cin.get();
                break;
            case 3: 
                Retirar(Reg_C);
                cin.get();
                break;
            case 4:
                Transferir(Reg_C);
                cin.get();
                break;
             case 5:
                Edad(Reg_C);
                cin.get();  
                break;
            case 6:

                break;
            case 7:
                General(Reg_C);
                break;
            case 8:
                cout <<"el programa se va a cerrar. ";
                break;
            default:
                cout << "Opcion no valida";
                break;
        }
    }
    while (opcion != 8);
    return 0;
}
