#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    char *const argv2[] = {" ","2",NULL};
    if (argc != 1)
    {
        perror("error numero de argumentos erroneos");
        exit(0);
    }
    execv("./matriz", argv2);
    return 0;
}