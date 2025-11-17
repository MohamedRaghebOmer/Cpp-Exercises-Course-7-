#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;

int GenerateRandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillArrayWithRandomNumbers(int arr1[][3], short Rows, short Col)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			arr1[i][j] = GenerateRandomNumber(1, 10);
		}
	}
}

void PrintArray(int arr[][3], short Rows, short Col)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			printf("%02d  ", arr[i][j]);
		}

		cout << endl;
	}
}

void PrintRowInArray(int arr[][3], short RowNumber, short Col)
{
	for (int i = 0; i < Col; i++)
	{
		printf("%02d  ", arr[RowNumber][i]);
	}
}

void PrintColInArray(int arr[][3], short ColNumber, short Raws)
{
	for (int i = 0; i < Raws; i++)
	{
		printf("%02d  ", arr[i][ColNumber]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;
	int arr[Rows][Col];

	FillArrayWithRandomNumbers(arr, Rows, Col);
	cout << "Array elements:" << endl;
	PrintArray(arr, Rows, Col);

	cout << "\nMedile Row in the Array:" << endl;
	PrintRowInArray(arr, Rows/2, Col);

	cout << "\n\nMedile Col in the Array:" << endl;
	PrintColInArray(arr, Col / 2, Rows);

	cout << endl;

    return 0;
}