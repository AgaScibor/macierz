#ifndef MACIERZ_HPP
#define MACIERZ_HPP

#include <iostream>

class macierz {
public:
    // Konstruktory i destruktor
    macierz(); // Konstruktor domyślny - tworzy macierz 2x2 wypełnioną zerami
    macierz(double a, double b, double c, double d); // Konstruktor z wartościami początkowymi
    macierz(const macierz& copy); // Konstruktor kopiujący
    ~macierz(); // Destruktor


    // Operatory przeciążone
    macierz operator*(const macierz& copy) const; // Mnożenie macierzy
    macierz operator+(const macierz& copy) const; // Dodawanie macierzy
    macierz operator*(const double x) const; // Mnożenie macierzy przez stałą
    macierz& operator=(const macierz& copy); // Przypisanie macierzy
    bool operator==(const macierz& copy) const; // Porównanie macierzy
    macierz& operator+=(const macierz& copy); // Dodawanie macierzy do siebie
    macierz& operator*=(const macierz& copy); // Mnożenie macierzy przez siebie
    macierz& operator*=(const double x); // Mnożenie macierzy przez stałą
    friend std::ostream& operator<<(std::ostream& s, const macierz& m); // Wypisanie macierzy na ekran 

    // Metody dostępowe
    void set(int i, int j, double x); // Ustawienie wartości w konkretnym miejscu macierzy
    double get(int i, int j) const; // Pobranie wartości z konkretnego miejsca macierzy
    void transpozycja(); // Transpozycja macierzy - zamiana miejscami wierszy i kolumn


private:
    // Dwuwymiarowa tablica przechowująca elementy macierzy
    double** tablica; 
};
#endif // MACIERZ_HPP
