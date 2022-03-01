#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
int main(int argc, char const *argv[])
{
    if (argc != 1)
  {
    perror("error numero de argumentos erroneos");
    exit(0);
  }

    execl("/bin/ps", "ps", "-aux", NULL);
    
    return 0;
}