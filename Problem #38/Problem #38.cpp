#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string TrimLeft(string Sentence)
{   
    for (int i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ')
            return Sentence.substr(i, Sentence.length() - 1);
    }

    return "";
}

string TrimRighet(string Sentence)
{
    for (int i = Sentence.length() - 1; i >= 0; i--)
    {
        if (Sentence[i] != ' ')
            return Sentence.substr(0, i + 1);
    }

    return "";
}

string Trim(string Sentence)
{
    return TrimLeft(TrimRighet(Sentence));
}

int main()
{
    string Sentence = "        Mohamed ragheb omer ragheb        ";

    cout << Sentence << endl;
    cout << "\nTrim left  : " << TrimLeft(Sentence) << endl;
    cout << "Trim righet: " << TrimRighet(Sentence) << endl;
    cout << "Trim       : " << Trim(Sentence) << endl;

    return 0;
}