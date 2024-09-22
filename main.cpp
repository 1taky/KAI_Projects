/*
 * Done by:
 * Student name: Vitaliy Syniak
 * Group: 121-1
 * Lab 1.4
 */

#include <iostream>

int main() {

    // Опис змінних напередвизначених типів, які наведені y варіанті
    unsigned short usN1;
    int iN2;
    float fN3;
    double dbN4;

    // Опис вказівних змінних відповідних типів
    unsigned short *pusN1;
    int *piN2;
    float *pfN3;
    double *pdbN4;

    // Опис нетипізованої вказівної змінної
    void *pV;

    // Ініціювання вказівних змінних адресами змінних
    pusN1 = &usN1;
    piN2 = &iN2;
    pfN3 = &fN3;
    pdbN4 = &dbN4;

    // Ініціювання змінних, використовуючи операцію розіменування вказівних змінних
    *pusN1 = 43;
    *piN2 = 5124;
    *pfN3 = -8976.04;
    *pdbN4 = 3.5e-4;

    // Визначення розміру всіх змінних
    int sizeusN1 = sizeof(usN1);
    int sizeiN2 = sizeof(iN2);
    int sizefN3 = sizeof(fN3);
    int sizedbN4 = sizeof(dbN4);

    int sizepusN1 = sizeof(usN1);
    int sizepiN2 = sizeof(iN2);
    int sizepfN3 = sizeof(fN3);
    int sizepdbN4 = sizeof(dbN4);

    // Ініціювання нетипізованої вказівної змінної адресами типізованих вказівних змінних
    pV = &fN3;

    return 0;

}
