#include <iostream>
using namespace std;

void GenerateFibonacciArray(int Number)
{
    int Perv1 = 1, Perv2 = 0, Fibo = 0;
    
    cout << "1   ";
    
    for (int i = 2; i <= Number; i++)
    {
        Fibo = Perv1 + Perv2;
        cout << Fibo << "   ";
        Perv1 = Perv2;
        Perv2 = Fibo;
    }
}

int main()
{
    GenerateFibonacciArray(10);
    return 0;
}