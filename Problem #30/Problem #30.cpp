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

char ReadChar()
{
    char c;

    cout << "Please enter the character do you want to count: ";
    cin >> c;

    return c;
}

short CountLetterRepetition(string Sentence, char Letter)
{
    short Counter = 0;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] == Letter)
        {
           Counter++;
        }
    }

    return Counter;
}

int main()
{
    string Sentence = ReadString();
    char Letter = ReadChar();
    short LetterRepetion = CountLetterRepetition(Sentence, Letter);

    cout << "\nLetter '" << Letter << "' appeared " << LetterRepetion << " time(s).\n" << endl;

    return 0;
}