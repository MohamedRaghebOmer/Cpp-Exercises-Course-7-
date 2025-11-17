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

string TrimLeft(string Sentence)
{
    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] != ' ')
        {
            return Sentence.substr(i, Sentence.length() - i);
        }
    }

    return "";
}

string TrimRight(string Sentence)
{
    for (short i = Sentence.length() - 1; i >= 0; i--)
    {
        if (Sentence[i] != ' ')
            return Sentence.substr(0, i + 1);
    }

    return "";
}

string Trim(string Sentence)
{
    return TrimRight(TrimLeft(Sentence));
}

int main()
{
    string Sentence = ReadString();
    cout << "\nString     = " << Sentence << endl;
    cout << "\nTrim Left  = " << TrimLeft(Sentence) << endl;
    cout << "Trim Right = " << TrimRight(Sentence) << endl;
    cout << "Trim       = " << Trim(Sentence) << endl;

    system("pause>0");
}