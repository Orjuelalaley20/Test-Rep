#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra[20];
    int n;
    scanf("%s",palabra);
    scanf("%d",&n);
    system("clear");
    for (int i = 0; i < ("%d",n) ; i++)
    {
        printf("%s\n", palabra);
    }
    printf("\n");
    return 0;
}
int mgetline(char *line, int max,FILE *f)
{
    if (fgets(line,max,f) == NULL)
    {
        return 0;
    }
    else
        return(strlen(line));
    
}