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

string ReplaceWordInStringUsingBulidInFunction(string Sentence, string From, string To)
{
    short Pos = Sentence.find(From);

    while (Pos != string::npos)
    {
        Sentence.replace(Pos, From.length(), To);
        Pos = Sentence.find(From); // Find next word to replace
    }

    return Sentence;
}

int main()
{
    string Sentence = ReadString();
    string From = StringToReplace();
    string To = ReplaceTo();

    cout << "\nYour sentence after replace: " << ReplaceWordInStringUsingBulidInFunction(Sentence, From, To) << endl;
    return 0;
}
