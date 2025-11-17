#include <iostream>
#include <cstdlib>
#include <ctime>
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
			arr[i][j] = GenerateRandomNumber(0, 100);
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

int GetMaxInArray(int arr[][3], short Rows, short Col)
{
	int BiggestNumberInArray = arr[0][0]; // Suppose that the first number is the bigger number

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (arr[i][j] > BiggestNumberInArray)
				BiggestNumberInArray = arr[i][j];
		}
	}

	return BiggestNumberInArray;
}

int GetMinInArray(int arr[][3], short Rows, short Col)
{
	int SmallestNumberInArray = arr[0][0]; // Suppose that the first number is the smallest number

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (arr[i][j] < SmallestNumberInArray)
				SmallestNumberInArray = arr[i][j];
		}
	}

	return SmallestNumberInArray;
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;
	int arr[Rows][Col];

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "Array elements:" << endl;
	PrintArray(arr, Rows, Col);

	int BiggestNumber = GetMaxInArray(arr, Rows, Col);
	int SmallerNumber = GetMinInArray(arr, Rows, Col);

	cout << "\nBiggest number in the array is : " << BiggestNumber << endl;
	cout << "\nSmallest number in the array is : " << SmallerNumber << endl;

	return 0;
}