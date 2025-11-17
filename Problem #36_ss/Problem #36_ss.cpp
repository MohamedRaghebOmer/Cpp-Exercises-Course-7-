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

short CountWords(string Sentence)
{
    short Pos = 0; // The position of Delim
    short Counter = 0;
    string Word = ""; // Empty string
    string Delim = " "; // Space

    while ((Pos = Sentence.find(Delim)) != string::npos)
    {
        Word = Sentence.substr(0, Pos); // Stor word

        if (Word != "")
            Counter++;

        Sentence.erase(0, Pos + Delim.length()); // Delet printed word from string
    }

    if (Sentence != "")
        Counter++;

    return Counter;
}

int main()
{
    string Sentence = ReadString();
    cout << "\nThere is [" << CountWords(Sentence) << "] Words in your sentence.";

    system("pause>0");
}