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

vector <string> SplitString(string Sentence, string Delim = " ")
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

string ReverseWordsInString(string Sentence)
{
    vector <string> vSentence;
    string S = "";

    vSentence = SplitString(Sentence, " ");
    vector <string>::iterator iter = vSentence.end();

    while (iter != vSentence.begin())
    {
        --iter;
        S += *iter + " ";
    }

    S = S.substr(0, S.length() - 1);
    return S;
}

int main()
{
    string Sentence = ReadString();

    cout << "\nString after reversing words:\n" << ReverseWordsInString(Sentence) << endl;

	return 0;
}