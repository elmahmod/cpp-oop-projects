#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class clsUtil
{
private:
public:
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter,
        SpecialLetter,
        Digit,
        Mix
    };

    static void initializeRandom()
    {
        srand((unsigned)time(NULL));
    }

    // random number
    static int randomNumber(int from, int to)
    {
        return rand() % (to - from + 1) + from;
    }

    // get random character & word & key
    static char randomCharacter(enCharType charType)
    {
        if (charType == enCharType::Mix)
        {
            charType = static_cast<enCharType>(randomNumber(1, 4));
        }

        switch (charType)
        {
        case enCharType::SmallLetter:
            return static_cast<char>(randomNumber('a', 'z'));
        case enCharType::CapitalLetter:
            return static_cast<char>(randomNumber('A', 'Z'));
        case enCharType::SpecialLetter:
            return static_cast<char>(randomNumber(33, 47));
        case enCharType::Digit:
            return static_cast<char>(randomNumber('0', '9'));
        default:
            return '\0';
        }
    }

    static string randomWord(enCharType charType, int wordLength)
    {
        string word = "";
        for (int i = 0; i < wordLength; i++)
        {
            word += randomCharacter(charType);
        }
        return word;
    }

    static string generateKey(enCharType charType)
    {
        string key = "";
        for (int i = 0; i < 4; i++)
        {
            key += randomWord(charType, 4) + '-';
        }
        return key.substr(0, key.length() - 1);
    }

    static void printKeys(enCharType charType, int keysNumber)
    {
        for (int i = 0; i < keysNumber; i++)
        {
            cout << "key [" << i + 1 << "]   : " << generateKey(charType) << endl;
        }
    }

    // swap using (template)
    template <typename T>
    static void swap(T &num1, T &num2)
    {
        T temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // shuffle array
    static void shuffleArray(int arr[], int arrLength)
    {
        for (int i = arrLength - 1; i > 0; i--)
        {
            int j = randomNumber(0, i);
            swap(arr[i], arr[j]);
        }
    }

    // fill array with random numbers & words & keys
    static void fillArrayWithRandomNumbers(int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = randomNumber(0, 10);
    }

    static void fillArrayWithRandomWords(string arr[], int arrLength, enCharType charType, int wordLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = randomWord(charType, wordLength);
    }

    static void fillArrayWithRandomKeys(string arr[], int arrLength, enCharType charType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generateKey(charType);
    }

    // encryption, decryption
    static void encryptText(string &text, int key)
    {
        for (int i = 0; i < text.length(); i++)
            text[i] = text[i] + key;
    }

    static void decryptText(string &text, int key)
    {
        for (int i = 0; i < text.length(); i++)
            text[i] = text[i] - key;
    }
};