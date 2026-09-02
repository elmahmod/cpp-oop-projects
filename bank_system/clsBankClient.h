#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;

const string clientsFile = "clients.txt";

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode
    };
    enMode _mode;
    string _accountNumber;
    string _pinCode;
    double _balance;

    static clsBankClient _convertLineToClientObject(string line, string separator = "#//#")
    {
        vector<string> vClientData = clsString::split(line, separator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _getEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:
    clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, double balance)
        : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _accountNumber = accountNumber;
        _pinCode = pinCode;
        _balance = balance;
    }

    // set
    void setPinCode(string pinCode) { _pinCode = pinCode; }
    void setBalance(double balance) { _balance = balance; }

    // get
    string getAccountNumber() { return _accountNumber; } // read only
    string getPinCode() { return _pinCode; }
    double getBalance() { return _balance; }

    // is empty?
    bool isEmpty()
    {
        return _mode == EmptyMode;
    }

    // print data
    void print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << getFirstName();
        cout << "\nLastName    : " << getLastName();
        cout << "\nFull Name   : " << fullName();
        cout << "\nEmail       : " << getEmail();
        cout << "\nPhone       : " << getPhone();
        cout << "\nAcc. Number : " << _accountNumber;
        cout << "\nPassword    : " << _pinCode;
        cout << "\nBalance     : " << _balance;
        cout << "\n___________________\n";
    }

    // find
    static clsBankClient find(string accountNumber)
    {
        ifstream file(clientsFile);

        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                clsBankClient client = _convertLineToClientObject(line);
                if (client.getAccountNumber() == accountNumber)
                {
                    file.close();
                    return client;
                }
            }
        }
        else
        {
            cout << "\nFile does not found\n";
        }

        return _getEmptyClientObject();
    }

    static clsBankClient find(string accountNumber, string pinCode)
    {
        ifstream file(clientsFile);

        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                clsBankClient client = _convertLineToClientObject(line);
                if (client.getAccountNumber() == accountNumber && client.getPinCode() == pinCode)
                {
                    file.close();
                    return client;
                }
            }
        }
        else
        {
            cout << "\nFile does not found\n";
        }

        return _getEmptyClientObject();
    }

    static bool isClientExist(string accountNumber)
    {
        clsBankClient client = find(accountNumber);
        return !client.isEmpty();
    }

}; // finish line
