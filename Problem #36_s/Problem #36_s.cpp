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

short CountWords(string Sentence)
{
    string Delim = " ";
    string Word;
    short Pos = 0;
    short Counter = 0;

    while ((Pos = Sentence.find(Delim)) != string::npos)
    {
        Word = Sentence.substr(0, Pos); // store charcters from beging to delim

        if (Word != "")
        {
            Counter++;
        } 

        Sentence.erase(0, Pos + Delim.length()); // erase Counted word from string
    }

    if (Sentence != "")
    {
        Counter++; // Count the last word
    }

    return Counter;
}

int main()
{
    string Sentence = ReadString();

    cout << "\nThe number of word in your string is: " << CountWords(Sentence) << endl;

    return 0;
}