#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string JoinString(vector <string> vSentence, string Delim = " ")
{
    string WordAfterDelim = "";

    for (string Word : vSentence)
    {
        WordAfterDelim += Word + Delim;
    }

    return WordAfterDelim.substr( 0, WordAfterDelim.length() - Delim.length() );
}

string JoinString(string arr[], short arrLength, string Delim = " ")
{
    string WordAfterDelim = "";

    for (int i = 0; i < arrLength; i++)
    {
        WordAfterDelim += arr[i] + Delim;
    }

    return WordAfterDelim.substr(0, WordAfterDelim.length() - Delim.length());
}

int main()
{
    vector <string> vSentence = { "Mohamed","Ragheb","Omer","Elmorcy" };
    cout << "Vector after join:\n" << JoinString(vSentence) << endl;
    
    const short arrLenght = 4;
    string arr[arrLenght] = { "Mohamed","Ragheb","Omer","Elmorcy" };
    cout << "\nArray after join:\n" << JoinString(arr, arrLenght) << endl;

    return 0;
}