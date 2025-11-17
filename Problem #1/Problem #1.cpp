#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;

int GenerateRandomNumber(short From, short To)
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
		for (short y = 0; y < Col; y++)
		{
			cout << setw(5) << arr[i][y];
		}

		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const short Rows = 3, Col = 3; // You can change the Rows value, but you can't change Col
	int arr[Rows][Col]; // If you want to change col, edit it in line 13, 24, 40

	FillArrayWithRandomNumbers(arr, Rows, Col);

	cout << "The following is a 3x3 random matrix: " << endl;
	PrintArray(arr, Rows, Col);

	return 0;
}
