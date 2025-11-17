/*
This program ask the user to type a sentnece then replace the spaces
between each two words and by the Seprator do you prefer in line 62
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vWords, string Delim)
{
    string Line = "";

    for (string &Word : vWords)
    {
        Line += Word + Delim;
    }

    if (Line != "")
        Line = Line.substr(0, Line.length() - Delim.length());

    return Line;
}

string JoinString(string Arr[], short ArrayLength, string Delim)
{
    string Line = "";

    for (short i = 0; i < ArrayLength; i++)
    {
        Line += Arr[i] + Delim;
    }
    
    if (Line != "")
        Line = Line.substr(0, Line.length() - Delim.length());

    return Line;
}

int main()
{
    vector <string> vStorVector = { "Mohamed", "Ragheb", "Omer", "Elmorsy" };
    string Arr[] = {"Mohamed", "Ragheb", "Omer", "Elmorsy"};

    cout << "\nVector after join : " << JoinString(vStorVector, " ") << endl;
    cout << "\nArray after join  : " << JoinString(Arr, 4, " ") << endl;

    system("pause>0");
}