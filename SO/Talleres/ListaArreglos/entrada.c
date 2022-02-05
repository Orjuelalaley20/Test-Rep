/* Archivo entrada.c */

/* Rutinas para hacer Entrada Estandar */

#include <stdio.h>
#include <string.h>

/* mgetline
   Lee max caracteres de la proxima linea del archivo f 
   Retorna el n�mero de caracteres de la l�nea
*/
int mgetline (char *line, int max, FILE *f)
{

    if (fgets(line, max, f)== NULL)
       return(0);
    else return(strlen(line));

}
