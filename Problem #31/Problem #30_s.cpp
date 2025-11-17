#include <iostream>
#include <string>
#include <cctype>
using namespace std;

enum enCase { MatchingCase, NotMatchingCase };

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

short CountLetterRepetion(string Sentence, char Letter, enCase Case)
{
    short Counter = 0;

    if (Case == enCase::MatchingCase)
    {
        for (short i = 0; i < Sentence.length(); i++)
        {
            if (Sentence[i] == Letter)
            {
                Counter++;
            }
        }
    }
    else if (Case == enCase::NotMatchingCase)    
    {
        Sentence = isupper(Letter) ? AllToCapittalLetters(Sentence) : AllToSmallLetters(Sentence);

        for (short i = 0; i < Sentence.length(); i++)
        {
            if (Sentence[i] == Letter)
            {
                Counter++;
            }
        }
    }
    
    return Counter;
}

int main()
{
    string Sentence = ReadString();
    char Letter = ReadChar();

    cout << "\nLetter '" << Letter << "' counter =  " << CountLetterRepetion(Sentence, Letter, enCase::MatchingCase) << endl;
    cout << "\nLetter '" << Letter << "' Or \'" << InvertCharCase(Letter) << "\' counter = " << CountLetterRepetion(Sentence, Letter, enCase::NotMatchingCase) << endl;
    return 0;
}