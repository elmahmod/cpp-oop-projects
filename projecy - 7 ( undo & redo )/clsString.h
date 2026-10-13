#pragma once
#include <iostream>
#include <stack>
using namespace std;

class clsString
{
private:
    stack<string> _redo;
    stack<string> _undo;
    string _value = "o";

public:
    void setValue(string value)
    {
        _undo.push(_value);
        _value = value;

        // clear redo history
        while (!_redo.empty())
            _redo.pop();
    }

    string getValue() { return _value; }

    void undo()
    {
        if (!_undo.empty())
        {
            _redo.push(_value);
            _value = _undo.top();
            _undo.pop();
        }
    }

    void redo()
    {
        if (!_redo.empty())
        {
            _undo.push(_value);
            _value = _redo.top();
            _redo.pop();
        }
    }
};