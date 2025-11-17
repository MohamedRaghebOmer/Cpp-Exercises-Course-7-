#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "Write a Sentence: ";
    getline(cin, Sentence);

    return Sentence;
}

vector <string> SplitString (string Sentence, string Delim = " ")
{
    vector<string> vString;
    string Word;
    short Pos = 0;

    while ((Pos = Sentence.find(Delim)) != string::npos)
    {
        Word = Sentence.substr(0, Pos); // store charcters from beging to delim

        if (Word != "")
        {
            vString.push_back(Word);
        }

        Sentence.erase(0, Pos + Delim.length()); // erase printed word from string
    }

    if (Sentence != "")
    {
        vString.push_back(Sentence);
    }

    return vString;
}

void PrintVector(vector <string> MyVector)
{
    for (string Word : MyVector)
    {
        cout << Word << endl;
    }
}

int main()
{
    string Sentence = ReadString();
    vector <string> S = SplitString(Sentence);

    cout << "\nTokens: " << S.size() << endl;
    PrintVector(S);

    return 0;
}