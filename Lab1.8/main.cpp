// Done by student: Vitaliy Syniak
// Group: 121-1
// Lab1.8

#include <iostream>

using namespace std;

int main() {
    // ЗАВДАННЯ НОМЕР 1 ТА 2
    {
        // Умовний оператор if, else if, else
        int num;

        cout << "Enter number: ";
        cin >> num;

        if ((num & 1) == 0) {
            cout << "Number is even" << endl;
        }
        else cout << "Number is odd" << endl;

    }

    {
        // Оператор switch-case
        int num1, num2;

        cout << "Enter number 1: ";
        cin >> num1;

        cout << "Enter number 2: ";
        cin >> num2;

        char op;
        cout << "Enter operation(+, -, *, /): ";
        cin >> op;

        switch(op) {
            case '+':
                cout << num1 + num2 << endl;
            break;
            case '-':
                cout << num1 - num2 << endl;
            break;
            case '*':
                cout << num1 * num2 << endl;
            break;
            case '/':
                cout << num1 / num2 << endl;
            break;
            default:
                cout << "Incorrect operation" << endl;
        }
    }

    {
        // Цикл for
        int num;

        cout << "Enter number for 'for' cycle: ";
        cin >> num;

        for (int i = 1; i <= num; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    {
        // Цикл while
        int num;

        cout << "Enter number(number > 0) for 'while' cycle: ";
        cin >> num;

        while (num > 0) {
            cout << num << " ";
            num--;
        }
        cout << endl;
    }

    {
        // Цикл do-while
        int yourPassword;
        int password = 123321;

        cout << "Try to guess the password: ";

        do {
            cin >> yourPassword;
            if (yourPassword != password) {
                cout << "Incorrect password, try again: " << endl;
            }
        } while (yourPassword != password);

        cout << "You entered correct password. You are the real hacker)" << endl;
    }

    // ЗАВДАННЯ НОМЕР 3
    // #1
    {
        int num;

        cout << "Enter number: ";
        cin >> num;

        if(num & 1 == 0) {
            cout << "Number is even" << endl;
        }
        else{
            cout << "Number is odd" << endl;
        }
    }
    // #2
    {
        int num;

        cout << "Enter number: ";
        cin >> num;

        int count = 0;
        while (num > 0) {
            num = num & (num - 1);
            count++;
        }
        cout << "Count bits: " << count << endl;
    }
    // #3
    {
        int num, pos;

        cout << "Enter number: ";
        cin >> num;

        cout << "Bit position to check: ";
        cin >> pos;

        if ((num & (1 << pos)) == 1) {
            cout << "Bit on position " << pos << " == 1";
        }
        else {
            cout << "Bit on position " << pos << " == 0";
        }
    }
    return 0;
}
