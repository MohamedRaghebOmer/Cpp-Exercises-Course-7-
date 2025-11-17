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
			printf("%02d  ", arr[i][j]);
		}

		cout << endl;
	}
}

int SumOfArray(int arr[][3], short Rows, short Col)
{
	int Sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			Sum +=  arr[i][j];
		}
	}

	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;
	int arr[Rows][Col];

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "The following is a 3x3 random matrix:" << endl;
	PrintArray(arr, Rows, Col);

	cout << "\nSum of the array is = " << SumOfArray(arr, Rows, Col) << endl;

	return 0;
}