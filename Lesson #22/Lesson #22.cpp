#include <iostream>
using namespace std;

void GenerateFibonacciArray(int Number, int Prev1, int Prev2)
{
    if (Number > 0)
    {
        int Fibo = 0;

        cout << "1   ";

        Fibo = Prev1 + Prev2;
        cout << Fibo << "   ";
        Prev2 = Prev1;
        Prev1 = Fibo;
        GenerateFibonacciArray(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    GenerateFibonacciArray(10, 0, 1);
    return 0;
}