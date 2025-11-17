#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "Enter a string: ";
    getline(cin, Sentence);

    return Sentence;
}

int CountWords(string Sentence)
{
    short Counter = 0;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (Sentence[i] == ' ')
            Counter++;
    }

    if (Sentence.back() != ' ')
        Counter++;

    if (Sentence.front() == ' ')
        Counter--;

    return Counter;
}

int main()
{
    string Sentence = ReadString();

    cout << CountWords(Sentence) << endl;

    return 0;
}