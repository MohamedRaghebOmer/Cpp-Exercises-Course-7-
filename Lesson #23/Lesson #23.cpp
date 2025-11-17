#include <iostream>
#include <string>
using namespace std;

string GetUserString()
{
    string UserInput;

    cout << "Please write your string below." << endl;
    getline(cin, UserInput);

    return UserInput;
}

void PrintFirstLetter(string Sentence)
{
    cout << "First letters of each word are: " << endl;
    cout << Sentence.front() << "   ";

    for (int i = 0; i < Sentence.length(); i++)
    {
        if (i + 1 < Sentence.length() && Sentence.at(i) == ' ' && Sentence.at(i + 1) != ' ')
        {
            cout << Sentence.at(i + 1) << "   ";
        }

    }
}

int main()
{
    PrintFirstLetter(GetUserString());

    return 0;
}