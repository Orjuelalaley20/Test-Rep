#include <iostream>

using namespace std;
double B[100];

int fibonacci1(int n)
{
    if (B[n] == 0)
    {
        if (n == 0 || n == 1)
            return (1);
        else
            B[n] = (fibonacci1(n - 1) + fibonacci1(n - 2));
    }
    return B[n];
}

int main()

{

    int n;

    n = 40;

    for (int i = 1; i < n; i++)
    {
        cout << fibonacci1(i) << endl;
    }
    return 0;
}