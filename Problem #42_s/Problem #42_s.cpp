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

string SentenceToLower(string Sentence)
{
    for (int i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = tolower(Sentence[i]);
    }

    return Sentence;
}

string ReplaceWordInStringMacthCase(string Sentence, string From,string To)
{
    while (Sentence.find(From) != string::npos)
    {
        short StartPos = Sentence.find(From); // Position of first letter in the word
        short WordPositionInVector = 0;

        vector <string> vString = SplitString(Sentence);

        while (From != vString[WordPositionInVector])
            WordPositionInVector++; // Get word position in the vector

        Sentence.erase(StartPos, vString[WordPositionInVector].length()); // Delete word
        Sentence = Sentence.insert(StartPos, To); // Inserting the new word
    }

    return Sentence;
}

string ReplaceWordInStringDontMacthCase(string Sentence, string From, string To)
{
    Sentence = SentenceToLower(Sentence);
    From = SentenceToLower(From);

    while (Sentence.find(From) != string::npos)
    {
        short StartPos = Sentence.find(From); // Position of first letter in the word
        short WordPositionInVector = 0;

        vector <string> vString = SplitString(Sentence);

        while (From != vString[WordPositionInVector])
            WordPositionInVector++; // Get word position in the vector

        Sentence.erase(StartPos, vString[WordPositionInVector].length()); // Delete word
        Sentence = Sentence.insert(StartPos, To); // Inserting the new word
    }

    return Sentence;
}

int main()
{
    string Sentence = ReadString();
    string From = StringToReplace();
    string To = ReplaceTo();

    cout << "\nReplace with match case: "
        << ReplaceWordInStringMacthCase(Sentence, From, To) << endl;
   
    cout << "Replace without match case: " <<
        ReplaceWordInStringDontMacthCase(Sentence, From, To) << endl;

    return 0;
}