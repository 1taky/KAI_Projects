//Done by student: Vitaliy Syniak
//Group: 121-1
//RGR 28 variant

#include <iostream>
#include <string>

using namespace std;

bool checkChain(string chain);

int main() {
    string chain;
    cout << "Enter chain: ";
    getline(cin, chain);

    if (checkChain(chain)) {
        cout << "Chain is true" << endl;
    } else {
        cout << "Chain is false" << endl;
    }

    return 0;
}

bool checkChain(string chain) {
    int length = chain.length();

    if (length < 3) return false;

    if (chain[0] != '+' && chain[0] != '-') {               // Перевіряю, щоб 1 символ був '-' або '+'
        return false;
    }

    bool checkDigit = false;                                // Перевіряю, щоб були цифри
    bool checkABC = false;                                  // Перевіряю, чи є букви A-C
    bool checkDEFG = false;                                 // Перевіряю, чи є D-G

    for (int i = 1; i < length; i++) {
        if (chain[i] >= '5' && chain[i] <= '9') {           // Циклом перебираю усі символи строки і спочатку перевіряю, чи є цифри на початку
            checkDigit = true;                              // Якщо знайдено цифру в діапазоні 5-9, то повертаю true
        } else if (chain[i] >= 'A' && chain[i] <= 'C') {    // Потім перевіряю наявність букв від А до С, після цифр
            checkABC = true;                                // Знайдена буква A-C
        } else if (chain[i] >= 'D' && chain[i] <= 'G') {    // І на останок перевіряю чи є букви від D до G після попередніх або якщо не було А-С то після цифр
            checkDEFG = true;                               // Знайдена буква D-G
        }

        if (checkABC && checkDEFG) {                        // Якщо одночасно є і А-с і D-G, то повертаю false, бо за умовою такого не може бути
            return false;
        }
    }

    if (!checkDigit) {                                      // Якщо немає цифр, то теж false, бо за умовою вони мають бути обов'язково
        return false;
    }

    if (length > 0 && chain[length - 1] == '-') {           // І тут перевіряю, щоб останній елемент був '-'
        return true;
    }

    return false;                                           // Якщо не виконано жодна з умов, то буде false
}
