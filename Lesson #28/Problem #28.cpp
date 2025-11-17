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

string InvertStringCase(string S)
{
    for (int i = 0; i < S.length(); i++)
    {
        S[i] = isupper(S[i]) ? tolower(S[i]) : toupper(S[i]);
    }
    return S;
}

int main()
{
    cout << "\nYour String after converting is : " << InvertStringCase(ReadString()) << endl;

    return 0;
}
