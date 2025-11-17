#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadChar()
{
    char Letter;

    cout << "Please enter a character: ";
    cin >> Letter;

    return Letter;
}

bool IsVowel(char Letter)
{
    string vowels = "aeiouAEIOU";
    return vowels.find(Letter) != string::npos;
}


int main()
{
    char Letter = ReadChar();

    if (IsVowel(Letter))
        cout << "Yes, Letter \'" << Letter << "\' is a vowel letrer! :-)" << endl;
    else
        cout << "No, Letter \'" << Letter << "\' is NOT a vowel letrer. :-(" << endl;

    return 0;
}