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
        UpdateMode,
        AddNewMode
    };
    enMode _mode;
    string _accountNumber;
    string _pinCode;
    double _balance;
    bool _markedForDelete = false;

    static clsBankClient _convertLineToClientObject(string line, string separator = "#//#")
    {
        vector<string> vClientData = clsString::split(line, separator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _getEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static string _convertClientObjectToLine(clsBankClient client, string separator = "#//#")
    {
        string line = "";
        line = client.getFirstName() + separator;
        line += client.getLastName() + separator;
        line += client.getEmail() + separator;
        line += client.getPhone() + separator;
        line += client.getAccountNumber() + separator;
        line += client.getPinCode() + separator;
        line += to_string(client.getBalance());
        return line;
    }

    static void _saveClientObjectToFile(vector<clsBankClient> vClients)
    {
        ofstream file(clientsFile);

        if (file.is_open())
        {
            for (clsBankClient &client : vClients)
            {
                if (!client._markedForDelete)
                    file << _convertClientObjectToLine(client) << endl;
            }
            file.close();
        }
        else
        {
            cout << "\nfile not found\n";
        }
    }

    static vector<clsBankClient> _loadClientsFile()
    {
        vector<clsBankClient> vClients;
        ifstream file(clientsFile);

        if (file.is_open())
        {
            string line = "";
            while (getline(file, line))
            {
                vClients.push_back(_convertLineToClientObject(line));
            }
            file.close();
        }
        else
        {
            cout << "\nfile not found\n";
        }
        return vClients;
    }

    void _update()
    {
        vector<clsBankClient> vClients = _loadClientsFile();

        for (clsBankClient &client : vClients)
        {
            if (client.getAccountNumber() == this->_accountNumber)
            {
                client = *this;
                _saveClientObjectToFile(vClients);
                return;
            }
        }
    }

    void _addNew()
    {
        _addDataLineToFile(_convertClientObjectToLine(*this));
    }

    void _addDataLineToFile(string dataLine)
    {
        ofstream file(clientsFile, ios::app);

        if (file.is_open())
        {
            file << dataLine << endl;
            file.close();
        }
        else
        {
            cout << "\nfile not found\n";
        }
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
        cout << "\nPin Code    : " << _pinCode;
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

    // save result
    enum enSaveResult
    {
        svFailedEmptyObject = 0,
        svSucceeded,
        svFailedClientExists
    };

    enSaveResult save()
    {
        switch (_mode)
        {
        case EmptyMode:
            return svFailedEmptyObject;

        case UpdateMode:
        {
            _update();
            return svSucceeded;
        }

        case AddNewMode:
        {
            if (isClientExist(_accountNumber))
            {
                return svFailedClientExists;
            }
            else
            {
                _addNew();
                _mode = UpdateMode;
                return svSucceeded;
            }
        }
        }

        return svFailedEmptyObject;
    }

    static clsBankClient getAddNewClient(string accountNumber)
    {
        return clsBankClient(AddNewMode, "", "", "", "", accountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> vClients = _loadClientsFile();

        for (clsBankClient &client : vClients)
        {
            if (client._accountNumber == this->_accountNumber)
            {
                client._markedForDelete = true;
                _saveClientObjectToFile(vClients);
                client = _getEmptyClientObject();
                return true;
            }
        }
        return false;
    }
}; // finish line
