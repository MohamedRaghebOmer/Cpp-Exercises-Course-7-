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

bool IsVowel(char Letter)
{
    string vowels = "aeiouAEIOU";
    return vowels.find(Letter) != string::npos;
}

short CountVowel(string Sentence)
{
    short Counter = 0;

    for (short i = 0; i < Sentence.length(); i++)
    {
        if(IsVowel(Sentence[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string Sentence = ReadString();

    cout << "\nNumber of vowels = " << CountVowel(Sentence) << endl;
    return 0;
}