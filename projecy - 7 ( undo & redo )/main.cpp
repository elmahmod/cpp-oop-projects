#include <iostream>
#include "clsString.h"
using namespace std;

int main()
{
    clsString s1;

    cout << "\ns1 = " << s1.getValue() << endl;

    s1.setValue("muhammed");
    cout << "\ns1 = " << s1.getValue() << endl;

    s1.setValue("muhammed2");
    cout << "\ns1 = " << s1.getValue() << endl;

    s1.setValue("muhammed3");
    cout << "\ns1 = " << s1.getValue() << endl;

    cout << "\n==== Undo ====\n";
    s1.undo();
    cout << "s1 = " << s1.getValue() << endl;

    s1.undo();
    cout << "s1 = " << s1.getValue() << endl;

    s1.undo();
    cout << "s1 = " << s1.getValue() << endl;

    cout << "\n==== Redo ====\n";
    s1.redo();
    cout << "s1 = " << s1.getValue() << endl;

    s1.redo();
    cout << "s1 = " << s1.getValue() << endl;

    s1.redo();
    cout << "s1 = " << s1.getValue() << endl;

    cout << "\n==== Undo ====\n";
    s1.undo();
    cout << "s1 = " << s1.getValue() << endl;

    cout << "\n==== Redo ====\n";
    s1.redo();
    cout << "s1 = " << s1.getValue() << endl;

    return 0;
}
