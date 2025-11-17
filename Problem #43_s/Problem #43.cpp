#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "What is String do you want to write?" << endl;
    getline(cin, Sentence);

    return Sentence;
}

string StringToReplace()
{
    string Word = "";

    cout << "\nWhat's the word you want to replace?" << endl;
    getline(cin, Word);

    return Word;
}

string ReplaceTo()
{
    string Word = "";

    cout << "\nWhat do you want to replace it with?" << endl;
    getline(cin, Word);

    return Word;
}

vector <string> SplitString(string Sentence, string Delim = " ")
{
    vector <string> vWord;

    short Pos = 0; // The position of Delim
    string Word = ""; // Empty string

    while ((Pos = Sentence.find(Delim)) != string::npos)
    {
        Word = Sentence.substr(0, Pos); // Stor word

        if (Word != "")
            vWord.push_back(Word);

        Sentence.erase(0, Pos + Delim.length()); // Delet printed word from string
    }

    if (Sentence != "")
        vWord.push_back(Sentence);

    return vWord;
}

string JoinString(vector <string> vWords, string Delim)
{
    string Line = "";

    for (string& Word : vWords)
    {
        Line += Word + Delim;
    }

    if (Line != "")
        Line = Line.substr(0, Line.length() - Delim.length());

    return Line;
}

string SentenceToLower(string Sentence)
{
    for (int i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = tolower(Sentence[i]);
    }

    return Sentence;
}

string ReplaceWordInString(string Sentence, string From, string To, bool MatchCase = true)
{
    vector <string> vString = SplitString(Sentence);

    for (string &Word : vString)
    {
        if (MatchCase)
        {
            if (Word == From)
            {
                Word = To;
            }
        }
        else
        {
            if (SentenceToLower(Word) == SentenceToLower(From))
            {
                Word = To;
            }
        }
    }

    return JoinString(vString, " ");
}

int main()
{
    string Sentence = ReadString();
    string From = StringToReplace();
    string To = ReplaceTo();

    cout << "\nReplace with match case: "
        << ReplaceWordInString(Sentence, From, To) << endl;

    cout << "Replace without match case: " <<
        ReplaceWordInString(Sentence, From, To, false) << endl;

    return 0;
}