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
			arr[i][j] = GenerateRandomNumber(1, 10);
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
			Sum += arr[i][j];
		}
	}

	return Sum;
}

bool isEqual(int Sum1, int Sum2)
{
	return Sum1 == Sum2;
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;

	int arr1[Rows][Col];
	int arr2[Rows][Col];

	FillArrayWithRandomNumbers(arr1, Rows, Col);
	FillArrayWithRandomNumbers(arr2, Rows, Col);

	cout << "Array 1:" << endl;
	PrintArray(arr1, Rows, Col);

	cout << "\nArray 2:" << endl;
	PrintArray(arr2, Rows, Col);

	int Sum1 = SumOfArray(arr1, Rows, Col);
	int Sum2 = SumOfArray(arr2, Rows, Col);

	cout << "\nSum 1 = " << Sum1 << endl;
	cout << "Sum 2 = " << Sum2 << endl;

	if (isEqual(Sum1, Sum2))
		cout << "\nYes, the arrays are equal! :-)" << endl;
	else
		cout << "\nNo, the arrays are not equal. :-(" << endl;

	return 0;
}