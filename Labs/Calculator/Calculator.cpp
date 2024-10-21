//Done by student: Vitaliy Syniak
//Group: 121-1
//Lab2.2, 14 variant

#include <iostream> 
#include <stack>    
#include <string>   

using namespace std; 

int getOperation(char c);
bool isOperatorChar(char c);
bool checkDigit(char c);
string convertInfixToPostfix(string expression);
int doOperation(char operation, int op1, int op2);
int calculatePostfix(string postfixExpression);

int main() {
    string expression; 
    cout << "Введіть вираз: "; 
    getline(cin, expression); 

    string postfixExpression = convertInfixToPostfix(expression); 
    cout << "Постфіксний вираз: " << postfixExpression << endl; 

    int result = calculatePostfix(postfixExpression); 
    cout << "Результат: " << result << endl; 

    return 0; 
}

int getOperation(char c) { 
    if (c == '+' || c == '-') { 
        return 1; 
    } else if (c == '*' || c == '/') { 
        return 2; 
    } else {
        return 0; 
    }
}

bool isOperatorChar(char c) { 
    return (c == '+' || c == '-' || c == '*' || c == '/'); 
}

bool checkDigit(char c) { 
    return (c >= '0' && c <= '9'); 
}

string convertInfixToPostfix(string expression) { 
    stack<char> operatorStack; 
    string postfixExpression = ""; 

    for (int i = 0; i < expression.length(); i++) { 
        char currentChar = expression[i]; 

        if (checkDigit(currentChar)) { 
            postfixExpression += currentChar; 
        } else if (currentChar == '(') { 
            operatorStack.push(currentChar); 
        } else if (currentChar == ')') { 
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top(); 
                operatorStack.pop(); 
            }
            operatorStack.pop(); 
        } else if (isOperatorChar(currentChar)) { 
            while (!operatorStack.empty() && getOperation(operatorStack.top()) >= getOperation(currentChar)) {
                postfixExpression += operatorStack.top(); 
                operatorStack.pop(); 
            }
            operatorStack.push(currentChar); 
        }
    }

    while (!operatorStack.empty()) { 
        postfixExpression += operatorStack.top(); 
        operatorStack.pop(); 
    }

    return postfixExpression; 
}

int doOperation(char operation, int op1, int op2) { 
    if (operation == '+') { 
        return op1 + op2; 
    } else if (operation == '-') { 
        return op1 - op2; 
    } else if (operation == '*') { 
        return op1 * op2; 
    } else if (operation == '/') { 
        if (op2 != 0) { 
            return op1 / op2; 
        } else {
            cout << "На нуль ділити не можна" << endl; 
            return 0; 
        }
    }
    return 0; 
}

int calculatePostfix(string postfixExpression) { 
    stack<int> numbers; 

    for (int i = 0; i < postfixExpression.length(); i++) { 
        char currentChar = postfixExpression[i]; 

        if (checkDigit(currentChar)) { 
            int number = currentChar - '0'; 
            numbers.push(number); 
        } else if (isOperatorChar(currentChar)) { 
            int operand2 = numbers.top(); numbers.pop(); 
            int operand1 = numbers.top(); numbers.pop(); 
            int result = doOperation(currentChar, operand1, operand2); 
            numbers.push(result); 
        }
    }

    return numbers.top(); 
}