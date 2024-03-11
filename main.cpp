#include <iostream>
#include "macierz.h"

int main() {
    // Przykłady użycia klasy macierz
    macierz m1;
    macierz m2(1.0, 3.0, 6.0, 4.0);
    macierz m3(m2);

    std::cout << "Macierz m1:\n" << m1;
    std::cout << "Macierz m2:\n" << m2;
    std::cout << "Macierz m3 (skopiowana z m2):\n" << m3;

    macierz m4 = m2 + m3;
    std::cout << "Macierz m4 (m2 + m3):\n" << m4;

    macierz m5 = m2 * m3;
    std::cout << "Macierz m5 (m2 * m3):\n" << m5;

    m1 = m2;
    std::cout << "Macierz m1 po przypisaniu m1 = m2:\n" << m1;

    if (m2 == m3) {
        std::cout << "Macierze m2 i m3 są rowne.\n";
    }
    else {
        std::cout << "Macierze m2 i m3 są rozne.\n";
    }

    m1 += m2;
    std::cout << "Macierz m1 po dodaniu m2 do m1:\n" << m1;

    m1 *= m2;
    std::cout << "Macierz m1 po pomnozeniu m1 przez m2:\n" << m1;

    m1 *= 2.0;
    std::cout << "Macierz m1 po pomnozeniu m1 przez 2.0:\n" << m1;

    m1.transpozycja();
    std::cout << "Macierz m1 po transpozycji:\n" << m1;

    return 0;
}
