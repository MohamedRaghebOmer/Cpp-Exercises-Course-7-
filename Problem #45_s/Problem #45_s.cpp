#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

    cout << "\nEnter Account Number: ";
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

int main()
{
    cout << "Please enter client data:" << endl;

    stClient Client1 = ReadNewClient();

    cout << "\nClient record to save:" << endl;
    cout << ConvertRecordToLine(Client1) << endl;

    return 0;
}