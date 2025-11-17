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

void MultiplyMatrix(int arr1[][3], int arr2[][3], int arrResult[][3], short Rows, short Col)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			arrResult[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;

	int arr1[Rows][Col];
	int arr2[Rows][Col];
	int arrResult[Rows][Col];

	FillArrayWithRandomNumbers(arr1, Rows, Col);
	cout << "Matrix 1:" << endl;
	PrintArray(arr1, Rows, Col);

	FillArrayWithRandomNumbers(arr2, Rows, Col);
	cout << "\nMatrix 2:" << endl;
	PrintArray(arr2, Rows, Col);

	MultiplyMatrix(arr1, arr2, arrResult, Rows, Col);

	cout << "\nReslut:" << endl;
	PrintArray(arrResult, Rows, Col);

	return 0;
}