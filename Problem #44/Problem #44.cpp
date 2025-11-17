#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string Sentence;

    cout << "What is String do you want to write?" << endl;
    getline(cin, Sentence);

    return Sentence;
}

string DeletePunct(string Sentence)
{
    string CleanSentence = "";

    for (short i = 0; i < Sentence.length(); i++)
    {
        if (!ispunct(Sentence[i]))
        {
            CleanSentence += Sentence[i];
        }
    }

    return CleanSentence;
}

int main()
{
    string Sentence = ReadString();
    
    cout << "\nSentence after deleting all punctuation marks: " << DeletePunct(Sentence) << endl;
    return 0;
}