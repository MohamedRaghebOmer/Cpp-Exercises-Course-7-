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

char InvertCharCase(char C)
{
    return isupper(C) ? tolower(C) : toupper(C);
}

short CountLetterRepetion(string Sentence, char Letter, bool MatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (MatchCase)
        {
            if (Sentence[i] == Letter)
                Counter++;
        }
        else
        {
            char LowerSentenceChar = tolower(Sentence[i]);
            char LowerLetter = tolower(Letter);

            if (LowerSentenceChar == LowerLetter)
                Counter++;
        }
    }

    return Counter;
}

int main()
{
    string Sentence = ReadString();
    char Letter = ReadChar();

    cout << "\nLetter '" << Letter << "' counter =  " <<
    CountLetterRepetion(Sentence, Letter) << endl;

    cout << "\nLetter '" << Letter
    << "' Or \'" << InvertCharCase(Letter) 
    << "\' counter = " << CountLetterRepetion(Sentence, Letter, false) << endl;

    return 0;
}