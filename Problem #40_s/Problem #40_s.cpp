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

string ReverseWordsInString(string Sentence)
{
    vector <string> vString = SplitString(Sentence);
    vector <string>::iterator iter = vString.end();
    string Line = "";

    while (iter != vString.begin())
    {
        --iter;
        Line += *iter + " ";
    }

    if (Line != "")
        Line = Line.substr(0, Line.length() - 1);

    return Line;
}

int main()
{
    string Sentence = ReadString();
    cout << "String after reversing words: " << ReverseWordsInString(Sentence) << endl;
    system("pause>0");
}