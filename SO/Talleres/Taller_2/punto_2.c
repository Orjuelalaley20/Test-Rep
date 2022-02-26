#include <stdio.h>
int main(int argc, char const *argv[])
{
    execl("/bin/ps", "ps", "-aux", NULL);
    return 0;
}