#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void readClientInfo(clsBankClient &client)
{
    client.setFirstName(clsInputValidate::readString("Enter First Name: "));
    client.setLastName(clsInputValidate::readString("Enter Last Name: "));
    client.setEmail(clsInputValidate::readString("Enter Email: "));
    client.setPhone(clsInputValidate::readString("Enter Phone: "));
    client.setPinCode(clsInputValidate::readString("Enter Pin Code: "));
    client.setBalance(clsInputValidate::readDblNumber("Enter Balance: "));
}

void updateClient()
{

    string accountNumber = clsInputValidate::readString("Please enter client account number: ");

    while (!clsBankClient::isClientExist(accountNumber))
    {
        accountNumber = clsInputValidate::readString("account number is not found, choose another one: ");
    }

    clsBankClient client = clsBankClient::find(accountNumber);
    client.print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n_____________________\n";

    readClientInfo(client);

    switch (client.save())
    {
    case clsBankClient::enSaveResult::svSucceeded:
    {
        cout << "\naccount updated successfully\n";
        client.print();
        break;
    }
    case clsBankClient::enSaveResult::svFailedEmptyObject:
    {
        cout << "\nError account was not saved bacause it's empty\n";
        break;
    }
    default:
        break;
    }
}

void addNewClient()
{
    string accountNumber = clsInputValidate::readString("Enter account number: ");

    while (clsBankClient::isClientExist(accountNumber))
    {
        accountNumber = clsInputValidate::readString("client is already used, choose another one: ");
    }

    clsBankClient newClient = clsBankClient::getAddNewClient(accountNumber);
    readClientInfo(newClient);

    switch (newClient.save())
    {
    case clsBankClient::enSaveResult::svSucceeded:
    {
        cout << "\naccount added successfully\n";
        newClient.print();
        break;
    }
    case clsBankClient::enSaveResult::svFailedEmptyObject:
    {
        cout << "\nError account was not saved bacause it's empty\n";
        break;
    }
    case clsBankClient::enSaveResult::svFailedClientExists:
    {
        cout << "\nclient is already used\n";
        break;
    }
    default:
        break;
    }
}

void deleteClient()
{
    string accountNumber = clsInputValidate::readString("Please enter client account number: ");

    while (!clsBankClient::isClientExist(accountNumber))
    {
        accountNumber = clsInputValidate::readString("account number is not found, choose another one: ");
    }

    clsBankClient client = clsBankClient::find(accountNumber);
    client.print();

    if (clsInputValidate::confirmAction("are you sure you want to delete this client (y/n): "))
    {
        if (client.Delete())
        {
            cout << "\nDeleted successfully\n";
            client.print();
        }
        else
        {
            cout << "\nerror client was not deleted\n";
        }
    }
}

void printClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(20) << left << Client.fullName();
    cout << "| " << setw(12) << left << Client.getPhone();
    cout << "| " << setw(20) << left << Client.getEmail();
    cout << "| " << setw(10) << left << Client.getPinCode();
    cout << "| " << setw(12) << left << Client.getBalance();
}

void showClientsList()
{
    vector<clsBankClient> vClients = clsBankClient::getClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (clsBankClient Client : vClients)
        {
            printClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(40) << left << Client.fullName();
    cout << "| " << setw(12) << left << Client.getBalance();
}

void showTotalBalances()
{

    vector<clsBankClient> vClients = clsBankClient::getClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;

    double TotalBalances = clsBankClient::getTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
}

int main()
{
    showTotalBalances();
    return 0;
}
