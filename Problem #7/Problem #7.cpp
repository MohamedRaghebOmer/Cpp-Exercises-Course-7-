#include <iostream>
#include<iomanip>
using namespace std;

void FillArraySequential(int arr[][3], short Rows, short Col)
{
    int Counter = 1;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            arr[i][j] = Counter;
            Counter++;
        }
    }
}

void PrintArray(int arr[][3], short Rows, short Col)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << setw(5) << arr[i][j];
        }

        cout << endl;
    }
}

void TransposeArray(int arr[][3], int arrTransposed[][3], short Rows, short Col)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            arrTransposed[i][j] = arr[j][i];
        }
    }
}

int main()
{
    const short Rows = 3, Col = 3;

    int arr[Rows][Col];
    int arrTransposed[Rows][Col];

    FillArraySequential(arr, Rows, Col);

    cout << "The following is a 3x3 Sequential matrix:" << endl;
    PrintArray(arr, Rows, Col);

    TransposeArray(arr, arrTransposed, Rows, Col);

    cout << "\nArray after transposing: " << endl;
    PrintArray(arrTransposed, Rows, Col);

    return 0;
}