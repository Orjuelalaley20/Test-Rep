/* Ejemplo: matriz.c
   Crea el numero de procesos que recibe por argv y cada proceso va a imprimir un cierto numero de filas de la matriz


*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
main(int argc, char *argv[])

{
  if (argc != 2)
  {
    perror("error numero de argumentos erroneos");
    exit(1);
  }

  int status, i, nprocesos, cuantos, sum = 0, inicio = 0, final = 0;
  int matriz[6][6] = {{1, 1, 1, 1, 1, 1}, {2, 2, 2, 2, 2, 2}, {3, 3, 3, 3, 3, 3}, {4, 4, 4, 4, 4, 4}, {5, 5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}};
  pid_t childpid;

  nprocesos = atoi(argv[1]);
  cuantos = 6 / nprocesos;

  if (6 % nprocesos != 0)
  {
    perror("El numero ingresado no es divisible por 6");
    exit(1);
  }

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      printf("%i ", matriz[i][j]);
    }
    printf("\n");
    
  }
  

  for (i = 0; i < nprocesos; ++i)
  { // Creaci�n de los procesos.

    if ((childpid = fork()) < 0)
    {
      perror("fork:");
      exit(0);
    }

    // colocar aqui el c�digo de los hijos
    if (childpid == 0)
    {
      for (int i = inicio; i < cuantos + final; i++)
      {
        for (int j = 0; j < 6; j++)
        {
          sum +=  matriz[i][j];
        }
      }
      printf("Proceso # %i, suma %i \n", getpid(), sum);

      exit(0);
    }
    for (int i = inicio; i < cuantos + final; i++)
    {
      inicio = i;
    }
    inicio++;

    final = inicio;
  }
  // El padre espera por todos los hijos que creo.
  for (i = 0; i < nprocesos; ++i)
    wait(&status);
}