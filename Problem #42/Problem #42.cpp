#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string ReplaceWordInStringUsingBuildInFunction(string Sentence, string WordToReplace,
string ReplaceTo)
{
    short Pos = Sentence.find(WordToReplace);

    while (Pos != string::npos)
    {
        Sentence = Sentence.replace(Pos, WordToReplace.length(), ReplaceTo);
        Pos = Sentence.find(WordToReplace);
    }
    return Sentence;
}

int main()
{
    string Sentence = "My name is Mohamed Ragheb, My dad's name is Ragheb";
    string WordToRepalce = "Ragheb";
    string ReplaceTo = "Omer";

    cout << "Original Sentence: " << Sentence << endl;
    cout << "Sentence after replace: " << ReplaceWordInStringUsingBuildInFunction(Sentence,
        WordToRepalce, ReplaceTo) << endl;

    return 0;
}
