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

bool isTypical(int arr1[][3], int arr2[][3], short Rows, short Col)
{
	short Check = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				return false;
			}
		}
	}

	return true;
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

	if (isTypical(arr1, arr2, Rows, Col))
		cout << "\nYes, the arrays are typical! :-)" << endl;
	else
		cout << "\nNo, the arrays are not typical. :-(" << endl;

	return 0;
}