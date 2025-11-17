#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "Write a Sentence: ";
    getline(cin, Sentence);

    return Sentence;
}

void PrintEachWordInLine(string Sentence)
{
    string Word;
    string Delim = " ";
    short Pos = 0;

    while ( ( Pos = Sentence.find(Delim) ) != string::npos )
    {
        Word = Sentence.substr(0, Pos); // store charcters from beging to delim

        if (Word != "")
        {
            cout << Word << endl;
        }

        Sentence.erase(0, Pos + Delim.length()); // erase printed word from string
    }

    if (Sentence != "")
    {
        cout << Sentence << endl; // Print the last word
    }
}

int main()
{
    string Sentence = ReadString();

    cout << "\nYour sentence words are:" << endl;
    PrintEachWordInLine(Sentence);

    return 0;
}