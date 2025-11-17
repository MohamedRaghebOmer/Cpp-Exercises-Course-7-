#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "Enter String: ";
    getline(cin, Sentence);

    return Sentence;
}

void PrintEachWordInString(string Sentence)
{
    short Pos = 0; // The position of Delim
    string Word = ""; // Empty string
    string Delim = " "; // Space

    while ((Pos = Sentence.find(Delim)) != string::npos)
    {
        Word = Sentence.substr(0, Pos); // Stor word

        if (Word != "")
            cout << Word << endl;

        Sentence.erase(0, Pos + Delim.length()); // Delet printed word from string
    }

    if (Sentence != "")
        cout << Sentence << endl; // Print last word
}

int main()
{
    string Sentence = ReadString();
    PrintEachWordInString(Sentence);

    system("pause>0");
}