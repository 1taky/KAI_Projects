#include <iostream>

int main() {
    // Перша частина
    {
        char chSym1;
        chSym1 = 'U';
        const char CONSTSym1 = '*';
        char chSym2 = '6';

        std::cout << "Char1: " << chSym1    << std::endl;
        std::cout << "Const: " << CONSTSym1 << std::endl;
        std::cout << "Char2: " << chSym2    << std::endl;

        char chSym3;
        chSym3 = 0x7b; // "{"
        const char CONSTSym2 = 0x4c; // 'L'
        char chSym4 = 0x18; // '↑'

        std::cout << "Char3: "  << chSym3    << std::endl;
        std::cout << "Const2: " << CONSTSym2 << std::endl;
        std::cout << "Char4: "  << chSym4    << std::endl;
    }
    // Друга частина
    {
        int iNum1;
        float fltNum2;
        unsigned short usNum3;

        iNum1 = 5876;
        fltNum2 = 21.09;
        usNum3 = 333;

        double dbNum4;
        int iNum5;
        char chSym1;

        // Явно приведення
        dbNum4 = (double)iNum1;
        iNum5 = (int)fltNum2;
        chSym1 = (char)usNum3;

        std::cout << "Double: "  << dbNum4 << std::endl;
        std::cout << "Integer: " << iNum5  << std::endl;
        std::cout << "Char: "    << chSym1 << std::endl;


        // Неявне приведення
        dbNum4 = iNum1;
        iNum5 = fltNum2;
        chSym1 = usNum3;

        std::cout << "Double: "  << dbNum4 << std::endl;
        std::cout << "Integer: " << iNum5  << std::endl;
        std::cout << "Char: "    << chSym1 << std::endl;

        // Обхід суворої типізації

        double * pdblD;
        void *pV;
        pV = &iNum1;
        pdblD = (double*)pV;
        dbNum4 = *pdblD;

        std::cout << dbNum4 << std::endl;

        int * piNum5;
        pV = &fltNum2;
        piNum5 = (int*)pV;
        iNum5 = *piNum5;

        std::cout << iNum1 << std::endl;

        char * pchSym;
        pV = &usNum3;
        pchSym = (char*)pV;
        chSym1 = *pchSym;

        std:: cout << chSym1 << std::endl;
    }
    return 0;
}
