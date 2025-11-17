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

int ReadNumberToCheck()
{
	int Number;

	cout << "Please enter a number to check: ";
	cin >> Number;

	return Number;
}

short CountNumberInArray(int arr[][3], short Rows, short Col, int Number)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (arr[i][j] == Number)
				Counter++;
		}
	}

	return Counter;
}

void PrintResult(int Counter, int Number)
{
	cout << "\nNumber " << Number << " appered " << Counter << " time(s) in the array" << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	const short Rows = 3, Col = 3;
	int arr[Rows][Col];

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "Array elements:" << endl;
	PrintArray(arr, Rows, Col);

	cout << endl;

	int Number = ReadNumberToCheck();
	int Counter = CountNumberInArray(arr, Rows, Col, Number);
	PrintResult(Counter, Number);


	return 0;
}