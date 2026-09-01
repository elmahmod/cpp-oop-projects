#include <iostream>
#include "clsUtil.h"

using namespace std;

int main()
{
    // Initialize random seed
    clsUtil::initializeRandom();

    // ========================================
    // 1. Random Number
    // ========================================

    cout << "Random Number: "
         << clsUtil::randomNumber(1, 100)
         << endl;

    // ========================================
    // 2. Random Character
    // ========================================

    cout << "\nRandom Characters:\n";

    cout << "Small Letter   : "
         << clsUtil::randomCharacter(clsUtil::SmallLetter)
         << endl;

    cout << "Capital Letter : "
         << clsUtil::randomCharacter(clsUtil::CapitalLetter)
         << endl;

    cout << "Special Letter : "
         << clsUtil::randomCharacter(clsUtil::SpecialLetter)
         << endl;

    cout << "Digit          : "
         << clsUtil::randomCharacter(clsUtil::Digit)
         << endl;

    cout << "Mix            : "
         << clsUtil::randomCharacter(clsUtil::Mix)
         << endl;

    // ========================================
    // 3. Random Word
    // ========================================

    cout << "\nRandom Words:\n";

    cout << "Small Word : "
         << clsUtil::randomWord(clsUtil::SmallLetter, 8)
         << endl;

    cout << "Capital Word : "
         << clsUtil::randomWord(clsUtil::CapitalLetter, 8)
         << endl;

    cout << "Mix Word : "
         << clsUtil::randomWord(clsUtil::Mix, 8)
         << endl;

    // ========================================
    // 4. Generate Key
    // ========================================

    cout << "\nGenerated Keys:\n";

    cout << clsUtil::generateKey(clsUtil::CapitalLetter)
         << endl;

    cout << clsUtil::generateKey(clsUtil::Mix)
         << endl;

    // ========================================
    // 5. Print Keys
    // ========================================

    cout << "\nPrint Keys:\n";

    clsUtil::printKeys(clsUtil::Mix, 5);

    // ========================================
    // 6. Swap
    // ========================================

    cout << "\nSwap:\n";

    int num1 = 10;
    int num2 = 20;

    cout << "Before: "
         << num1 << " , " << num2 << endl;

    clsUtil::swap(num1, num2);

    cout << "After : "
         << num1 << " , " << num2 << endl;

    // ========================================
    // 7. Shuffle Array
    // ========================================

    cout << "\nShuffle Array:\n";

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Before: ";

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout << endl;

    clsUtil::shuffleArray(arr, 10);

    cout << "After : ";

    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout << endl;

    // ========================================
    // 8. Fill Array With Random Numbers
    // ========================================

    cout << "\nRandom Number Array:\n";

    int numbers[10];

    clsUtil::fillArrayWithRandomNumbers(numbers, 10);

    for (int i = 0; i < 10; i++)
        cout << numbers[i] << " ";

    cout << endl;

    // ========================================
    // 9. Fill Array With Random Words
    // ========================================

    cout << "\nRandom Word Array:\n";

    string words[5];

    clsUtil::fillArrayWithRandomWords(
        words,
        5,
        clsUtil::Mix,
        6);

    for (int i = 0; i < 5; i++)
        cout << words[i] << endl;

    // ========================================
    // 10. Fill Array With Random Keys
    // ========================================

    cout << "\nRandom Key Array:\n";

    string keys[5];

    clsUtil::fillArrayWithRandomKeys(
        keys,
        5,
        clsUtil::Mix);

    for (int i = 0; i < 5; i++)
        cout << keys[i] << endl;

    // ========================================
    // 11. Encrypt Text
    // ========================================

    cout << "\nEncryption:\n";

    string text = "Hello World";

    cout << "Original  : " << text << endl;

    clsUtil::encryptText(text, 5);

    cout << "Encrypted : " << text << endl;

    // ========================================
    // 12. Decrypt Text
    // ========================================

    clsUtil::decryptText(text, 5);

    cout << "Decrypted : " << text << endl;

    return 0;
}