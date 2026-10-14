
#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
#include "../clsDate.h"

using namespace std;

class clsQueueLine
{
private:
    string _prefix;
    int _totalTickets = 0;
    int _avgServeTime = 0;

    class clsTicket
    {
    private:
        string _prefix;
        string _date;
        int _ticketNumber;
        int _expectedServeTime;
        int _waitingClients;

    public:
        clsTicket(const string &prefix, int ticketNumber,
                  int expectedServeTime, int waitingClients)
            : _prefix(prefix),
              _date(clsDate::getSystemDateTimeString()),
              _ticketNumber(ticketNumber),
              _expectedServeTime(expectedServeTime),
              _waitingClients(waitingClients)
        {
        }

        string fullNumber() const
        {
            return _prefix + to_string(_ticketNumber);
        }

        void print() const
        {
            string indent(8, ' ');

            cout << "\n";
            cout << indent << "+----------------------------------------------+\n";
            cout << indent << "|                 TICKET INFO                  |\n";
            cout << indent << "+----------------------------------------------+\n";

            cout << indent << "|  " << left << setw(18) << "Ticket Number"
                 << ": " << setw(23) << fullNumber() << " |\n";

            cout << indent << "|  " << left << setw(18) << "Date"
                 << ": " << setw(23) << _date << " |\n";

            cout << indent << "|  " << left << setw(18) << "Waiting Clients"
                 << ": " << setw(23) << _waitingClients << " |\n";

            cout << indent << "|  " << left << setw(18) << "Expected Serve In"
                 << ": " << setw(23)
                 << (to_string(_expectedServeTime) + " min") << " |\n";

            cout << indent << "+----------------------------------------------+\n";
        }
    };

    queue<clsTicket> _queueLine;

public:
    clsQueueLine(const string &prefix, int avgServeTime)
        : _prefix(prefix), _avgServeTime(avgServeTime)
    {
    }

    int waitingClients() const
    {
        return static_cast<int>(_queueLine.size());
    }

    int servedClients() const
    {
        return _totalTickets - waitingClients();
    }

    void issueTicket()
    {
        _totalTickets++;

        int waiting = waitingClients();

        clsTicket ticket(
            _prefix,
            _totalTickets,
            _avgServeTime * waiting,
            waiting);

        _queueLine.push(ticket);
    }

    bool serveNextClient()
    {
        if (_queueLine.empty())
            return false;

        _queueLine.pop();
        return true;
    }

    string whoIsNext()
    {
        if (_queueLine.empty())
            return "No Clients Left.";

        return _queueLine.front().fullNumber();
    }

    void printInfo() const
    {
        string indent(8, ' ');

        cout << "\n";
        cout << indent << "+----------------------------------------------+\n";
        cout << indent << "|                  QUEUE INFO                  |\n";
        cout << indent << "+----------------------------------------------+\n";

        cout << indent << "|  " << left << setw(18) << "Prefix"
             << ": " << setw(23) << _prefix << " |\n";

        cout << indent << "|  " << left << setw(18) << "Total Tickets"
             << ": " << setw(23) << _totalTickets << " |\n";

        cout << indent << "|  " << left << setw(18) << "Served Clients"
             << ": " << setw(23) << servedClients() << " |\n";

        cout << indent << "|  " << left << setw(18) << "Waiting Clients"
             << ": " << setw(23) << waitingClients() << " |\n";

        cout << indent << "|  " << left << setw(18) << "Avg Serve Time"
             << ": " << setw(23)
             << (to_string(_avgServeTime) + " min") << " |\n";

        cout << indent << "+----------------------------------------------+\n";
    }

    void printTicketsLineRTL() const
    {
        queue<clsTicket> temp = _queueLine;

        cout << "\n";
        cout << "        [ TICKETS LINE - RTL ]\n";
        cout << "        ----------------------\n";
        cout << "        ";

        if (temp.empty())
        {
            cout << "No Tickets\n";
            return;
        }

        while (!temp.empty())
        {
            cout << "[" << temp.front().fullNumber() << "]";
            temp.pop();

            if (!temp.empty())
                cout << " --> ";
        }

        cout << "\n";
    }

    void printTicketsLineLTR() const
    {
        queue<clsTicket> temp = _queueLine;
        stack<clsTicket> reversed;

        while (!temp.empty())
        {
            reversed.push(temp.front());
            temp.pop();
        }

        cout << "\n";
        cout << "        [ TICKETS LINE - LTR ]\n";
        cout << "        ----------------------\n";
        cout << "        ";

        if (reversed.empty())
        {
            cout << "No Tickets\n";
            return;
        }

        while (!reversed.empty())
        {
            cout << "[" << reversed.top().fullNumber() << "]";
            reversed.pop();

            if (!reversed.empty())
                cout << " <-- ";
        }

        cout << "\n";
    }

    void printTickets() const
    {
        cout << "\n";
        cout << "        ============ WAITING TICKETS ============\n";

        if (_queueLine.empty())
        {
            cout << "\n        No Tickets\n";
            return;
        }

        queue<clsTicket> temp = _queueLine;

        while (!temp.empty())
        {
            temp.front().print();
            temp.pop();
        }

        cout << "\n";
    }
};
