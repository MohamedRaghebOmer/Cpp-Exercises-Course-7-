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

bool IsVowel(char Letter)
{
    string vowels = "aeiouAEIOU";
    return vowels.find(Letter) != string::npos;
}

void PrintVowels(string Sentence)
{
    for (short i = 0; i < Sentence.length(); i++)
    {
        if (IsVowel(Sentence[i]))
            cout << Sentence[i] << "   ";
    }
}

int main()
{
    string Sentence = ReadString();

    cout << "\nvowels in the string are : ";
    PrintVowels(Sentence);
    cout << endl;

    return 0;
}