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
    bool MarkForDelete = false;
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

string ConvertRecordToLine(stClient& Client, string Seperator = "#//#")
{
    string ClientRecord = "";

    ClientRecord = Client.AccountNumber + Seperator;
    ClientRecord += Client.PINCode + Seperator;
    ClientRecord += Client.Name + Seperator;
    ClientRecord += Client.Phone + Seperator;
    ClientRecord += to_string(Client.AccountBalance);

    return ClientRecord;
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

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> &vClient, stClient& Client)
{
    for (stClient &c : vClient)
    {
        if (c.AccountNumber == AccountNumber)
        {
            Client = c;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
    for (stClient &c : vClient)
    {
        if (AccountNumber == c.AccountNumber)
        {
            c.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

bool SaveClientDataToFile(string FileName, vector <stClient> &vClient)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (stClient &Client : vClient)
        {
            if (Client.MarkForDelete == false)
            {
                string Line = ConvertRecordToLine(Client);
                MyFile << Line << endl;
            }
        }

        MyFile.close();
        return true;
    }

    return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClient)
{
    stClient Client;
    char Sure = 'n';

     if (FindClientByAccountNumber(AccountNumber, vClient, Client))
     {
         PrintClientCard(Client);

         cout << "\nAre you sure you want to delete this client? [Y|N]" << endl;
         cin >> Sure;

         if (toupper(Sure) == 'Y')
         {
             MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
             SaveClientDataToFile(ClientsFileName, vClient);

             cout << "\nClient deleted Successfully." << endl;

             return true;
         }
         else
         {
             return false;
         }
     }
     else
     {
         cout << "Client with account number \'" << AccountNumber << "\' is not found." << endl;
         return false;
     }
}

int main()
{
    string AccountNumber = ReadClientAccountNumber();
    vector <stClient> vClient = LoadClientsDataFromFile(ClientsFileName);

    DeleteClientByAccountNumber(AccountNumber, vClient);

    return 0;
}