//Done by student: Vitaliy Syniak
//Group: 121-1
//Practice1.4

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int num;

    {
        // Task #1
        cout << "Enter number of element: ";
        cin >> num;

        if (num == 1 || num == 2) {
            cout << num << " = 1" << endl;
        } else {
            int fib1 = 1, fib2 = 1, result;
            for (int i = 3; i <= num; i++) {
                result = fib1 + fib2;
                fib1 = fib2;
                fib2 = result;
            }
            cout << "Fibonacci " << num << " = " << result << endl;
        }
    }

    // Task #2
    {
        cout << "Enter number: ";
        cin >> num;

        int sum = 0, count = 0;
        for (int i = 1; i <= num; i += 2) {
            sum += i;
            count++;
        }

        if (count > 0) {
            cout << "Average sum = " << (double)sum / count << endl;
        } else {
            cout << "No odd elements" << endl;
        }
    }

    // Task #3
    {
        double b1, q;
        int n;
        cout << "Enter b1: ";
        cin >> b1;
        cout << "Enter q: ";
        cin >> q;
        cout << "Enter number of elements: ";
        cin >> n;

        double geomSum = 0;
        for (int i = 0; i < n; i++) {
            geomSum += b1 * pow(q, i);
        }

        cout << "Average summary  = " << geomSum / n << endl;
    }
    return 0;
}