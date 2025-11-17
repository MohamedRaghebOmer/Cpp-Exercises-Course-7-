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
			arr[i][j] = GenerateRandomNumber(0, 1);
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

bool isIdentity(int arr[][3], short Rows, short Col)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (i == j)
			{
				if (arr[i][j] != 1)
					return false;
			}
			else
			{
				if (arr[i][j] != 0)
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

	FillArrayWithRandomNumbers(arr1, Rows, Col);

	cout << "Array elements:" << endl;
	PrintArray(arr1, Rows, Col);

	if (isIdentity(arr1, Rows, Col))
		cout << "\nYes, the array is Identity! :-)" << endl;
	else
		cout << "\nNo, the array is NOT Identity. :-(" << endl;
	return 0;
}