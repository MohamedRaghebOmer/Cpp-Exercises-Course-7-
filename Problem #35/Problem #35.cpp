#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "Enter a string: ";
    getline(cin, Sentence);

    return Sentence;
}

void PrintEachWordInLine(string Sentence)
{
    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ')
            cout << Sentence[i];
        else
            cout << endl;
    }
}

int main()
{
    string Sentence = ReadString();

    PrintEachWordInLine(Sentence);
    cout << endl;

	return 0;
}