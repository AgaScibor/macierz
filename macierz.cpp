#include "macierz.h"


macierz::macierz() {
    // Konstruktor domyślny - alokacja pamięci dla tablicy i wypełnienie zerami
    tablica = new double* [2];
    for (int i = 0; i < 2; ++i) {
        tablica[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
            tablica[i][j] = 0.0;
        }
    }
}

macierz::macierz(double a, double b, double c, double d) {
    // Konstruktor z wartościami początkowymi
    tablica = new double* [2];
    for (int i = 0; i < 2; ++i) {
        tablica[i] = new double[2];
    }
    tablica[0][0] = a;
    tablica[0][1] = b;
    tablica[1][0] = c;
    tablica[1][1] = d;
}

macierz::macierz(const macierz& copy) {
    // Konstruktor kopiujący - alokacja pamięci i kopiowanie wartości z innej macierzy
    tablica = new double* [2];
    for (int i = 0; i < 2; ++i) {
        tablica[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
            tablica[i][j] = copy.tablica[i][j];
        }
    }
}

macierz::~macierz() {
    // Destruktor - zwolnienie zaalokowanej pamięci
    for (int i = 0; i < 2; ++i) {
        delete[] tablica[i];
    }
    delete[] tablica;
}

macierz macierz::operator*(const macierz& copy) const {
    macierz wynik;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            wynik.tablica[i][j] = tablica[i][0] * copy.tablica[0][j] + tablica[i][1] * copy.tablica[1][j];
        }
    }
    return wynik;
}

macierz macierz::operator+(const macierz& copy) const {
    macierz wynik;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            wynik.tablica[i][j] = tablica[i][j] + copy.tablica[i][j];
        }
    }
    return wynik;
}

macierz macierz::operator*(const double x) const {
    macierz wynik;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            wynik.tablica[i][j] = tablica[i][j] * x;
        }
    }
    return wynik;
}

macierz& macierz::operator=(const macierz& copy) {
    if (this != &copy) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                tablica[i][j] = copy.tablica[i][j];
            }
        }
    }
    return *this;
}

bool macierz::operator==(const macierz& copy) const {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (tablica[i][j] != copy.tablica[i][j]) {
                return false;
            }
        }
    }
    return true;
}

macierz& macierz::operator+=(const macierz& copy) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tablica[i][j] += copy.tablica[i][j];
        }
    }
    return *this;
}

macierz& macierz::operator*=(const macierz& copy) {
    *this = *this * copy;
    return *this;
}

macierz& macierz::operator*=(const double x) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tablica[i][j] *= x;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& s, const macierz& m) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            s << m.tablica[i][j] << " ";
        }
        s << "\n";
    }
    return s;
}

void macierz::set(int i, int j, double x) {
    if (i >= 0 && i < 2 && j >= 0 && j < 2) {
        tablica[i][j] = x;
    }
}

double macierz::get(int i, int j) const {
    if (i >= 0 && i < 2 && j >= 0 && j < 2) {
        return tablica[i][j];
    }
    return 0.0;
}

void macierz::transpozycja() {
    macierz temp;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            temp.tablica[j][i] = tablica[i][j];
        }
    }
    *this = temp;
}
