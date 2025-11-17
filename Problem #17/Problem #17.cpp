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

	cout << "please enter the number you want to check: ";
	cin >> Number;

	return Number;
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

	if ( isNumberExisted(arr, Rows, Col, Number) )
		cout << "\nYes, your number is existed! :-)" << endl;
	else
		cout << "\nNo, your number isn't existed. :-(" << endl;

	return 0;
}