#include <iostream> // Підключаємо бібліотеку для введення і виведення
#include <stack>    // Підключаємо бібліотеку для роботи зі стеком
#include <string>   // Підключаємо бібліотеку для роботи з рядками

using namespace std; // Використовуємо простір імен std, щоб не писати std:: перед cout, cin

// Функція для визначення пріоритету оператора
int getOperation(char c) { // Функція приймає символ оператора
    if (c == '+' || c == '-') { // Якщо це '+' або '-', то це операція з нижчим пріоритетом
        return 1; // Повертаємо 1, бо додавання і віднімання мають найнижчий пріоритет
    } else if (c == '*' || c == '/') { // Якщо це '*' або '/', то це операція з вищим пріоритетом
        return 2; // Повертаємо 2, бо множення і ділення мають вищий пріоритет
    } else {
        return 0; // Якщо це не оператор, повертаємо 0 (можливо, помилка)
    }
}

// Функція для перевірки, чи є символ оператором
bool isOperatorChar(char c) { // Перевіряємо, чи символ є оператором
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Повертаємо true, якщо символ один із цих: +, -, *, /
}

// Функція для перевірки, чи є символ цифрою
bool checkDigit(char c) { // Перевіряємо, чи є символ цифрою
    return (c >= '0' && c <= '9'); // Якщо символ між '0' і '9', це цифра, і ми повертаємо true
}

// Функція для перетворення інфіксного виразу в постфіксний
string convertInfixToPostfix(string expression) { // Приймаємо інфіксний вираз як рядок
    stack<char> operatorStack; // Створюємо стек для операторів
    string postfixExpression = ""; // Змінна для зберігання постфіксного виразу

    for (int i = 0; i < expression.length(); i++) { // Проходимо по кожному символу в рядку
        char currentChar = expression[i]; // Отримуємо поточний символ

        if (checkDigit(currentChar)) { // Якщо символ є цифрою
            postfixExpression += currentChar; // Додаємо цю цифру в постфіксний вираз
        } else if (currentChar == '(') { // Якщо це відкрита дужка
            operatorStack.push(currentChar); // Кладемо дужку в стек
        } else if (currentChar == ')') { // Якщо це закрита дужка
            // Видаляємо всі оператори зі стека до відкритої дужки
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top(); // Додаємо оператор у постфікс
                operatorStack.pop(); // Видаляємо оператор зі стека
            }
            operatorStack.pop(); // Видаляємо відкриту дужку
        } else if (isOperatorChar(currentChar)) { // Якщо це оператор
            // Поки у стека є оператори з вищим або рівним пріоритетом
            while (!operatorStack.empty() && getOperation(operatorStack.top()) >= getOperation(currentChar)) {
                postfixExpression += operatorStack.top(); // Додаємо оператор зі стека до постфіксу
                operatorStack.pop(); // Видаляємо оператор зі стека
            }
            operatorStack.push(currentChar); // Кладемо поточний оператор у стек
        }
    }

    // Після завершення всіх операцій додаємо всі залишки зі стека
    while (!operatorStack.empty()) { // Поки стек не порожній
        postfixExpression += operatorStack.top(); // Додаємо оператор у постфікс
        operatorStack.pop(); // Видаляємо оператор зі стека
    }

    return postfixExpression; // Повертаємо постфіксний вираз
}

// Функція для виконання арифметичних операцій
int doOperation(char operation, int op1, int op2) { // Приймаємо оператор і два числа (операнди)
    if (operation == '+') { // Якщо оператор додавання
        return op1 + op2; // Повертаємо суму двох чисел
    } else if (operation == '-') { // Якщо оператор віднімання
        return op1 - op2; // Повертаємо різницю
    } else if (operation == '*') { // Якщо оператор множення
        return op1 * op2; // Повертаємо добуток
    } else if (operation == '/') { // Якщо оператор ділення
        if (op2 != 0) { // Перевіряємо, чи дільник не дорівнює нулю
            return op1 / op2; // Якщо не нуль, повертаємо результат ділення
        } else {
            cout << "Помилка: ділення на нуль." << endl; // Виводимо помилку, якщо дільник 0
            return 0; // Повертаємо 0 у випадку помилки
        }
    }
    return 0; // Якщо оператор не розпізнаний, повертаємо 0
}

// Функція для обчислення постфіксного виразу
int calculatePostfix(string postfixExpression) { // Приймаємо постфіксний вираз
    stack<int> numbers; // Стек для зберігання операндів (чисел)

    for (int i = 0; i < postfixExpression.length(); i++) { // Проходимо через кожен символ у постфіксному виразі
        char currentChar = postfixExpression[i]; // Поточний символ

        if (checkDigit(currentChar)) { // Якщо символ є цифрою
            int number = currentChar - '0'; // Перетворюємо символ на ціле число
            numbers.push(number); // Кладемо число у стек
        } else if (isOperatorChar(currentChar)) { // Якщо це оператор
            int operand2 = numbers.top(); numbers.pop(); // Витягуємо друге число зі стека
            int operand1 = numbers.top(); numbers.pop(); // Витягуємо перше число зі стека
            int result = doOperation(currentChar, operand1, operand2); // Виконуємо операцію над цими числами
            numbers.push(result); // Кладемо результат назад у стек
        }
    }

    return numbers.top(); // Повертаємо результат обчислення (останнє значення у стеці)
}

int main() {
    string expression; // Змінна для зберігання виразу від користувача
    cout << "Введіть вираз: "; // Просимо користувача ввести вираз
    getline(cin, expression); // Читаємо введений рядок

    string postfixExpression = convertInfixToPostfix(expression); // Перетворюємо інфіксний вираз на постфіксний
    cout << "Постфіксний вираз: " << postfixExpression << endl; // Виводимо постфікс

    int result = calculatePostfix(postfixExpression); // Обчислюємо результат постфіксного виразу
    cout << "Результат: " << result << endl; // Виводимо результат обчислень

    return 0; // Завершуємо програму
}
