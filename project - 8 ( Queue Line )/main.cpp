#include <iostream>
#include "DS/clsQueueLine.h"

using namespace std;

int main()
{
    clsQueueLine payBills("A0", 10);

    // Issue tickets
    for (int i = 0; i < 5; i++)
    {
        payBills.issueTicket();
    }

    // Initial queue
    payBills.printInfo();
    payBills.printTicketsLineRTL();
    payBills.printTicketsLineLTR();
    payBills.printTickets();

    // Serve two clients
    payBills.serveNextClient();
    payBills.serveNextClient();

    // Updated queue
    payBills.printInfo();
    payBills.printTicketsLineRTL();
    payBills.printTicketsLineLTR();
    payBills.printTickets();

    return 0;
}