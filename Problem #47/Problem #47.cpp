#include <iostream>
#include<fstream>
#include <string>
#include <vector>
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

stClient ReadNewClient()
{
    stClient Client;

    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);

    cout << "Enter PIN Code: ";
    getline(cin, Client.PINCode);

    cout << "Enter Name: ";
    getline(cin, Client.Name);

    cout << "Enter Phone: ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string ClientRecord = "";

    ClientRecord = Client.AccountNumber + Seperator;
    ClientRecord += Client.PINCode + Seperator;
    ClientRecord += Client.Name + Seperator;
    ClientRecord += Client.Phone + Seperator;
    ClientRecord += to_string(Client.AccountBalance);

    return ClientRecord;
}

void SaveLineToFile(string ClientsFileName, string LineToAdd)
{
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << LineToAdd << endl;
       
        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client = ReadNewClient();
    SaveLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';

    do
    {
        system("cls");

        cout << "Add New Client:\n" << endl;
        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? [Y/N] ";
        cin >> AddMore;

    }while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();

    return 0;
}