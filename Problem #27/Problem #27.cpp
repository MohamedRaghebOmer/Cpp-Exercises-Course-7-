#include <iostream>
#include <cctype>
using namespace std;

char ReadChar()
{
    char c;

    cout << "Please enter your character: ";
    cin >> c;

    return c;
}

char InvertCharCase(char C)
{
    return isupper(C) ? tolower(C) : toupper(C);
}

int main()
{
    cout << "\nYour Char after converting is : " << InvertCharCase(ReadChar()) << endl;

    return 0;
}
