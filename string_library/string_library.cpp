#include <iostream>
#include <vector>
#include "clsString.h"

using namespace std;

int main()
{
    clsString str("hello WORLD, this is a test.");

    // Set / Get
    str.setValue("hello WORLD, this is a test.");
    cout << "Value: " << str.getValue() << endl;

    // Count Words
    cout << "Words: " << str.countWords() << endl;

    // Count Small Letters
    cout << "Small Letters: " << str.countSmallLetters() << endl;

    // Count Capital Letters
    cout << "Capital Letters: " << str.countCapitalLetters() << endl;

    // Count Target Letter
    cout << "Target Letter 'l': " << str.countTargetLetters('l') << endl;

    // Count Vowels
    cout << "Vowels: " << str.countVowels() << endl;

    // Length
    cout << "Length: " << str.length() << endl;


    // Upper First Letter Of Each Word
    str.upperFirstLetterOfEachWord();
    cout << "Upper First Letter: " << str.getValue() << endl;


    // Lower First Letter Of Each Word
    str.lowerFirstLetterOfEachWord();
    cout << "Lower First Letter: " << str.getValue() << endl;


    // Upper All String
    str.upperAllString();
    cout << "Upper All: " << str.getValue() << endl;


    // Lower All String
    str.lowerAllString();
    cout << "Lower All: " << str.getValue() << endl;


    // Invert All Letters Case
    str.invertAllLettersCase();
    cout << "Invert Case: " << str.getValue() << endl;


    // Split
    vector<string> vTokens = str.split(" ");

    cout << "Split:" << endl;

    for (string token : vTokens)
    {
        cout << token << endl;
    }


    // Trim Left
    str.setValue("     Hello World     ");

    str.trimLeft();
    cout << "Trim Left: [" << str.getValue() << "]" << endl;


    // Trim Right
    str.setValue("     Hello World     ");

    str.trimRight();
    cout << "Trim Right: [" << str.getValue() << "]" << endl;


    // Trim
    str.setValue("     Hello World     ");

    str.trim();
    cout << "Trim: [" << str.getValue() << "]" << endl;


    // Reverse String
    str.setValue("Hello World From C++");

    str.reverseString();
    cout << "Reverse Words: " << str.getValue() << endl;


    // Replace Word
    str.setValue("Hello World From C++");

    str.replaceWord("World", "Programming");

    cout << "Replace Word: " << str.getValue() << endl;


    // Remove Punctuations
    str.setValue("Hello, World! How are you?");

    str.removePunctuations();

    cout << "Remove Punctuations: " << str.getValue() << endl;


    return 0;
}
