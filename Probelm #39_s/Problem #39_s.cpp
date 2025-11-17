#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "Enter String: ";
    getline(cin, Sentence);

    return Sentence;
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

string JoinString(vector <string> vWords, string Seprator)
{
    string Line = "";

    for (string Word : vWords)
    {
        Line += Word + Seprator;
    }

    Line.substr(Line.length() - Seprator.length(), Line.length());

    return Line;
}

int main()
{
    string Sentnece = ReadString();
    vector <string> vStorVector = SplitString(Sentnece);

    cout << "\nYour sentence after join: " << JoinString(vStorVector, ",");
    system("pause>0");
}