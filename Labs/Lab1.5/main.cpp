   /* DONE BY:
    * Student: Vitaliy Syniak
    * Group: 121-1
    * Lab1.5
    */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    {
        // First values
        int nA = 76, nB = 24;
        float fltC = 8.2, fltD = 8.2;

        bool res = !((nA != nB) && (fltC == fltD));
        cout << "First result is: " << boolalpha << res << endl;

        // Second values
        float fltA = 44.9, fltB = 44.9;
        int nC = 31, nD = 47;

        bool res2 = !((fltA != fltB) && (nC == nD));
        cout << "Second result is: " << boolalpha << res2 << endl;

    }
    {
        const int CONSTA = 74; // Константа цілого типу
        int nB = 50, nE = 17194; // Опис і ініціалізація змінних цілого типу
        float nC; // Опис змінної дійсного типу
        float *pnC; // Опис вказівної змінної
        pnC = &nC; // Ініціалізація вказівної змінної через адресу nC
        *pnC = 128.3; // Розіменування

        bool res = ((CONSTA |- nB) - *pnC) != (49 /  (nE >> sizeof(long)));

        cout << "CONST result is: " << boolalpha << res << endl;
    }

    return 0;
}

