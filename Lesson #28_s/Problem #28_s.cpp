#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string S;

    cout << "Enter a string: ";
    getline(cin, S);

    return S;
}

char InvertCharCase(char C)
{
    return isupper(C) ? tolower(C) : toupper(C);
}

string InvertStringCase(string S)
{
    for (int i = 0; i < S.length(); i++)
    {
        S[i] = InvertCharCase(S[i]);
    }
    return S;
}

int main()
{
    cout << "\nYour String after converting is : " << InvertStringCase(ReadString()) << endl;

    return 0;
}
