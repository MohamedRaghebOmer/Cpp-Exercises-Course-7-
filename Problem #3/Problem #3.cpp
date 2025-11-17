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

int RowSum(int arr[][3], short NumOfRow, short Col)
{
	int SumOfOneRow = 0;

	for (short i = 0; i < Col; i++)
	{
		SumOfOneRow += arr[NumOfRow][i];
	}

	return SumOfOneRow;
}

void LoadSumToArray(int arr[][3], short Rows, short Col, int SumOfRows[])
{
	for (short i = 0; i < Rows; i++)
	{
		SumOfRows[i] = RowSum(arr, i, Col);
	}
}

void PrintRowsSum(int SumOfRows[], short Rows)
{
	for (short i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << SumOfRows[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3; // You can change the Rows value, but you can't change Col
	int arr[Rows][Col]; // If you want to change col, edit it in line 13, 24, 37, 49, 69
	int SumOfRows[Rows];

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "The following is a 3x3 random matrix:" << endl;
	PrintArray(arr, Rows, Col);

	LoadSumToArray(arr, Rows, Col, SumOfRows);

	cout << "\nThe following are the sum of each row in the matrix:" << endl;
	PrintRowsSum(SumOfRows, Rows);

	return 0;
}
