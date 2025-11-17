#include <iostream>
using namespace std;

void GenerateFibonacciArray(int arr[], int ArrSize)
{
    for (int i = 2; i < ArrSize; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

void PrintArray(int arr[], int ArrSize)
{
    for (int i = 0; i < ArrSize; i++)
    {
        cout << arr[i] << "   ";
    }

    cout << endl;
}

int main()
{
    const int ArrSize = 10;
    int arr[ArrSize];

    arr[0] = 1;
    arr[1] = 1;

    GenerateFibonacciArray(arr, ArrSize);
    PrintArray(arr, ArrSize);

    return 0;
}