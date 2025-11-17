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

void FillArrayWithRandomNumbers(int arr[][3], short Rows, short Col)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			arr[i][j] = GenerateRandomNumber(1, 100);
		}
	}
}

void PrintArray(int arr[][3], short Rows, short Col)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			cout << setw(5) << arr[i][j];
		}

		cout << endl;
	}
}

int ColSum(int arr[][3], short ColIndex, short Rows)
{
	int SumOfOneCol = 0;

	for (short i = 0; i < Rows; i++)
	{
		SumOfOneCol += arr[i][ColIndex];
	}

	return SumOfOneCol;
}

void LoadSumToArray(int arr[][3], short Rows, short Col, int SumOfColumns[])
{
	for (short i = 0; i < Col; i++)
	{
		SumOfColumns[i] = ColSum(arr, i, Rows);
	}
}

void PrintColSum(int SumOfColumns[], short Col)
{
	for (short i = 0; i < Col; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << SumOfColumns[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3; // You can change the Rows value, but you can't change Col
	
	int arr[Rows][Col]; // If you want to change col, edit it in line 13, 24, 37, 49, 69
	int SumOfColumns[Col];

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "The following is a 3x3 random matrix:" << endl;
	PrintArray(arr, Rows, Col);

	LoadSumToArray(arr, Rows, Col, SumOfColumns);

	cout << "\nThe following are the sum of each col in the matrix:" << endl;
	PrintColSum(SumOfColumns, Col);

	return 0;
}
