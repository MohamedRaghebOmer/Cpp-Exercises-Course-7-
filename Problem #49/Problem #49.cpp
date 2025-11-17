#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector <string> SplitString(string Sentence, string Delim = " ")
{
    vector <string> vWord;

    short Pos = 0; // The position of Delim
    string Word = ""; // Empty string

    while ((Pos = Sentence.find(Delim)) != string::npos)
    {
        Word = Sentence.substr(0, Pos); // Stor word

        if (Word != "")
            vWord.push_back(Word);

        Sentence.erase(0, Pos + Delim.length()); // Delet printed word from string
    }

    if (Sentence != "")
        vWord.push_back(Sentence);

    return vWord;
}

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector <string> vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PINCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClient;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line = "";

        while (getline(MyFile, Line))
        {
            stClient Client = ConvertLineToRecord(Line);
            vClient.push_back(Client);
        }

        MyFile.close();
    }

    return vClient;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please enter account number: ";
    cin >> AccountNumber;

    return AccountNumber;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following is the extracted client record:" << endl;
    cout << "\nAccount Number : " << Client.AccountNumber << endl;
    cout << "PIN Code       : " << Client.PINCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
    vector <stClient> vClient = LoadClientsDataFromFile(ClientsFileName);

    for (stClient c : vClient)
    {
        if (c.AccountNumber == AccountNumber)
        {
            Client = c;
            return true;
        }
    }
    return false;
}

int main()
{
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with account number \'" << AccountNumber << "\' is not found." << endl;
    }

    return 0;
}