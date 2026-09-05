#include <iostream>
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
int main()
{
    deleteClient();
    return 0;
}
