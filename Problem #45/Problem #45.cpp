#include <iostream>
#include <string>
using namespace std;

struct stAccountData
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

stAccountData ReadNewClient()
{
    stAccountData AccountData;

    cout << "\nEnter account number: ";
    getline(cin, AccountData.AccountNumber);

    cout << "Enter PIN Code: ";
    getline(cin, AccountData.PinCode);

    cout << "Enter name: ";
    getline(cin,AccountData.Name);

    cout << "Enter phone: ";
    getline(cin,AccountData.Phone);

    cout << "Enter account balnce: ";
    cin >> AccountData.AccountBalance;

    return AccountData;
}

string ConvertRecordToLine(stAccountData& AccountData, string Seperator = "#//#")
{
    string ClietRecord = "";

    ClietRecord += AccountData.AccountNumber + Seperator;
    ClietRecord += AccountData.PinCode + Seperator;
    ClietRecord += AccountData.Name + Seperator;
    ClietRecord += AccountData.Phone + Seperator;
    ClietRecord += to_string(AccountData.AccountBalance);

    return ClietRecord;
}

int main()
{
    stAccountData AccountData;

    cout << "Please enter Client Data:" << endl;
    AccountData = ReadNewClient();

    cout << "\nCleint record for saving it is: ";
    cout << ConvertRecordToLine(AccountData, "#//#") << endl;

    return 0;
}
