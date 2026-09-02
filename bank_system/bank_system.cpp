#include <iostream>
#include "clsBankClient.h"
using namespace std;

int main()
{
    clsBankClient client = clsBankClient::find("A101");
    client.print();

    clsBankClient client2 = clsBankClient::find("A101", "123454");
    client2.print();

    cout << clsBankClient::isClientExist("A101") << endl;
    return 0;
}
