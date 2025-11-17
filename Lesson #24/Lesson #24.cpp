#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string GetUserString()
{
    string UserInput;

    cout << "Please write your string:" << endl;
    getline(cin, UserInput);

    return UserInput;
}

string CapitalizeWords(string Sentence)
{
    if (Sentence != "")
        Sentence[0] = toupper(Sentence[0]); // Capitalize first letter if small

    for (int i = 1; i < Sentence.length(); i++)
    {
        if (i + 1 < Sentence.length() && Sentence[i] == ' ' && Sentence[i + 1] != ' ')
        {
            Sentence[i + 1] = toupper(Sentence[i + 1]);
        }

    }
    
    return Sentence;
}

int main()
{
    string Words = CapitalizeWords(GetUserString());
    
    cout << "\nSentence after Capitalization: " << endl;
    cout << Words << endl;

    return 0;
}