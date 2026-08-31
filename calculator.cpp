#include <iostream>
using namespace std;

class clsCalculator
{
private:
    enum enOperationType
    {
        Add = 1,
        Sub,
        Div,
        Multip,
        Clear
    };

    int _result = 0;
    int _lastNumber = 0;
    enOperationType _opType;

    string getOperationName(enOperationType opType)
    {
        string types[] = {"adding", "subtracting", "dividing", "multiplying", "clear"};
        return types[opType - 1];
    }

public:
    void clear()
    {
        _opType = Clear;
        _lastNumber = 0;
        _result = 0;
    }

    void add(int number)
    {
        _opType = Add;
        _lastNumber = number;
        _result += number;
    }

    void subtract(int number)
    {
        _opType = Sub;
        _lastNumber = number;
        _result -= number;
    }

    void divide(int number)
    {
        _opType = Div;
        _lastNumber = number;

        if (number == 0)
            number = 1;
        _result /= number;
    }

    void multiply(int number)
    {
        _opType = Multip;
        _lastNumber = number;
        _result *= number;
    }

    void printResult()
    {
        cout << "Result after " << getOperationName(_opType) << " " << _lastNumber << " is: " << _result << endl;
    }
};

int main()
{
    clsCalculator cal;

    cal.clear();

    cal.add(10);
    cal.printResult();

    cal.add(100);
    cal.printResult();

    cal.subtract(20);
    cal.printResult();

    cal.multiply(2);
    cal.printResult();

    cal.divide(2);
    cal.printResult();

    cal.clear();
    cal.printResult();
    return 0;
}