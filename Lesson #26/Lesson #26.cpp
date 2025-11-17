#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string UserInput;

    cout << "Please write your string:" << endl;
    getline(cin, UserInput);

    return UserInput;
}

string AllToCapittalLetters(string Sentence)
{
    for (int i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = toupper(Sentence[i]);
    }
    return Sentence;
}

string AllToSmallLetters(string Sentence)
{
    for (int i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = tolower(Sentence[i]);
    }
    return Sentence;
}

int main()
{
    string Sentence = ReadString();

    cout << "\nSentence after Capitalization all letters: " << endl;
    cout << AllToCapittalLetters(Sentence) << endl;

    cout << "\nSentence after Converte all letters to small: " << endl;
    cout << AllToSmallLetters(Sentence) << endl;

    return 0;
}