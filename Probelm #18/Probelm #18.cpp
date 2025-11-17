#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

bool isNumberExisted(int arr[][3], short Rows, short Col, int NumberToCheck)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (arr[i][j] == NumberToCheck)
				return true;
		}
	}

	return false;
}

void PrintCommonNumbers(int arr1[][3], int arr2[][3], short Rows, short Col)

{
	int Number;

	for (short i = 0; i < Rows; i++) // Rows in arr1
	{
		for (short j = 0; j < Col; j++) // Col in arr1
		{
			Number = arr1[i][j];

			if ( isNumberExisted(arr2, Rows, Col, Number) )
			{
				cout << setw (3) << Number << "    ";
			}
			
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;
	int arr1[Rows][Col];
	int arr2[Rows][Col];

	FillArrayWithRandomNumbers(arr1, Rows, Col);
	FillArrayWithRandomNumbers(arr2, Rows, Col);

	cout << "Array1 elements:" << endl;
	PrintArray(arr1, Rows, Col);

	cout << "\nArray2 elements:" << endl;
	PrintArray(arr2, Rows, Col);

	cout << endl;

	PrintCommonNumbers(arr1, arr2, Rows, Col);

	return 0;
}