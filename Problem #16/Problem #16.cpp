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
			arr[i][j] = GenerateRandomNumber(0, 10);
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

bool isSparceArray(int arr[][3], short Rows, short Col)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (arr[i][j] == 0)
				Counter++;
		}
	}

	return Counter > (Rows * Col) / 2;
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;
	int arr[Rows][Col];

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "Array elements:" << endl;
	PrintArray(arr, Rows, Col);

	if (isSparceArray(arr, Rows, Col))
		cout << "\nYes, this is a sparce array! :-)" << endl;
	else
		cout << "\nNo, this is Not a sparce array. :-(" << endl;

	return 0;
}