
#include <iostream>
#include "clsString.h"
using namespace std;

int main()
{
    clsString s1;

    cout << "\n========================================\n";
    cout << "         STRING UNDO / REDO TEST         \n";
    cout << "========================================\n";

    cout << "\n[ INITIAL VALUE ]\n";
    cout << "s1 = [" << s1.getValue() << "]\n";

    cout << "\n---------- SET VALUES ----------\n";

    s1.setValue("muhammed");
    cout << "Set 1  | s1 = " << s1.getValue() << endl;

    s1.setValue("muhammed2");
    cout << "Set 2  | s1 = " << s1.getValue() << endl;

    s1.setValue("muhammed3");
    cout << "Set 3  | s1 = " << s1.getValue() << endl;

    cout << "\n---------- UNDO OPERATIONS ----------\n";

    s1.undo();
    cout << "Undo 1 | s1 = [" << s1.getValue() << "]\n";

    s1.undo();
    cout << "Undo 2 | s1 = [" << s1.getValue() << "]\n";

    s1.undo();
    cout << "Undo 3 | s1 = [" << s1.getValue() << "]\n";

    cout << "\n---------- REDO OPERATIONS ----------\n";

    s1.redo();
    cout << "Redo 1 | s1 = [" << s1.getValue() << "]\n";

    s1.redo();
    cout << "Redo 2 | s1 = [" << s1.getValue() << "]\n";

    s1.redo();
    cout << "Redo 3 | s1 = [" << s1.getValue() << "]\n";

    cout << "\n---------- FINAL UNDO / REDO ----------\n";

    s1.undo();
    cout << "Undo   | s1 = [" << s1.getValue() << "]\n";

    s1.redo();
    cout << "Redo   | s1 = [" << s1.getValue() << "]\n";

    cout << "\n========================================\n";
    cout << "         SECOND OBJECT TEST             \n";
    cout << "========================================\n";

    clsString s2;

    cout << "\n========================================\n";
    cout << "        STRING UNDO / REDO TEST (S2)     \n";
    cout << "========================================\n";

    cout << "\n[1] INITIAL STATE\n";
    cout << "Current Value : [" << s2.getValue() << "]\n";

    cout << "\n[2] SET VALUE\n";
    s2.setValue("muhammed");
    cout << "Current Value : [" << s2.getValue() << "]\n";

    cout << "\n[3] UNDO OPERATION\n";
    s2.undo();
    cout << "Current Value : [" << s2.getValue() << "]\n";

    cout << "\n[4] REDO OPERATION\n";
    s2.redo();
    cout << "Current Value : [" << s2.getValue() << "]\n";

    cout << "\n[5] UNDO OPERATION\n";
    s2.undo();
    cout << "Current Value : [" << s2.getValue() << "]\n";

    cout << "\n========================================\n";
    cout << "             TEST COMPLETED             \n";
    cout << "========================================\n";

    return 0;
}
