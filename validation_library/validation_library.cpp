#include <iostream>
#include "clsInputValidate.h"
using namespace std;

int main()
{
    // 1. isNumberBetween
    cout << clsInputValidate::isNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::isNumberBetween(15, 1, 10) << endl;

    // 2. readIntNumber
    int number = clsInputValidate::readIntNumber("Enter an integer number: ");
    cout << "You entered: " << number << endl;

    // 3. readDblNumber
    double dblNumber = clsInputValidate::readDblNumber("Enter a double number: ");
    cout << "You entered: " << dblNumber << endl;

    // 4. readIntNumberBetween
    int age = clsInputValidate::readIntNumberBetween(18, 60, "Enter your age between 18 and 60: ");
    cout << "Your age is: " << age << endl;

    // 5. readDblNumberBetween
    double salary = clsInputValidate::readDblNumberBetween(1000.0, 5000.0, "Enter salary between 1000 and 5000: ");
    cout << "Your salary is: " << salary << endl;

    return 0;
}
