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

void PrintClientRecord(stClient Client)
{
    cout << "|" << setw(15) << left << Client.AccountNumber;
    cout << "|" << setw(10) << left << Client.PINCode;
    cout << "|" << setw(30) << left << Client.Name;
    cout << "|" << setw(17) << left << Client.Phone;
    cout << "|" << setw(10) << left << Client.AccountBalance;
}

void PrintAllClientData(vector <stClient> vClient)
{
    cout << "\n\t\t\t\tClient List (" << vClient.size() << ") Client(s)." << endl;
    cout << "_____________________________________________________________________________________" << endl;
    cout << "\n|" << setw(15) << left << "Account Number";
    cout << "|" << setw(10) << left << "PIN Code";
    cout << "|" << setw(30) << left << "Client Name";
    cout << "|" << setw(17) << left << "Phone";
    cout << "|" << setw(10) << left << "Balance ";
    cout << "\n_____________________________________________________________________________________\n" << endl;

    for (stClient Client : vClient)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    
    cout << "_____________________________________________________________________________________" << endl;
}

int main()
{
    vector <stClient> vClient = LoadClientsDataFromFile(ClientsFileName);
    PrintAllClientData(vClient);

    return 0;
}