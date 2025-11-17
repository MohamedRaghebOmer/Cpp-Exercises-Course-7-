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

enum enWhatToCount { CapitalLetters, SmallLetters, All};

short CountLetters(string S, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == All)
    {
        return S.length();
    }

    short Counter = 0;

    for (short i = 0; i < S.length(); i++)
    {
        if ( WhatToCount == enWhatToCount::CapitalLetters && isupper(S[i]) )
        {
            Counter++;
        }
        else if (WhatToCount == enWhatToCount::SmallLetters && islower(S[i]))
        {
            Counter++;
        }
    }
    return Counter;
}

short CountCapitalLetters(string S)
{
    short Counter = 0;

    for (short i = 0; i < S.length(); i++)
    {
        if (isupper(S[i]))
            Counter++;
    }
    return Counter;
}

short CountSmallLetters(string S) 
{
    short Counter = 0;

    for (short i = 0; i < S.length(); i++)
    {
        if (islower(S[i]))
            Counter++;
    }
    return Counter;
}

int main()
{
    string S = ReadString();

    cout << "\nString Length: " << S.length() << endl;
    cout << "\nCapital letters counter: " << CountCapitalLetters(S) << endl;
    cout << "\nSmall letters counter: " << CountSmallLetters(S) << endl;

    cout << "\n\nMethod 2:\n";
    cout << "\nString Length: " << CountLetters(S) << endl;
    cout << "\nCapital letters counter: " << CountLetters(S, enWhatToCount::CapitalLetters) << endl;
    cout << "\nSmall letters counter: " << CountLetters(S, enWhatToCount::SmallLetters) << endl;


    return 0;
}