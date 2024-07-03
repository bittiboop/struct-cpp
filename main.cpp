#include <iostream>
using namespace std;

struct Fraction {
    int numer;
    int denomin;

    Fraction(int num, int denom) : numer(num), denomin(denom) {
        if (denomin < 0) {
            numer = -numer;
            denomin = -denomin;
        }
        reduce();
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int divisor = gcd(abs(numer), abs(denomin));
        numer /= divisor;
        denomin /= divisor;
    }

    void toProper() const {
        int wholePart = numer / denomin;
        int fractionalPart = abs(numer % denomin);
        if (wholePart != 0) {
            cout << wholePart << " ";
        }
        if (fractionalPart != 0) {
            cout << fractionalPart << "/" << denomin;
        }
        if (wholePart == 0 && fractionalPart == 0) {
            cout << 0;
        }
        cout << endl;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numer * other.denomin + other.numer * denomin;
        int denom = denomin * other.denomin;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numer * other.denomin - other.numer * denomin;
        int denom = denomin * other.denomin;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numer * other.numer;
        int denom = denomin * other.denomin;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numer * other.denomin;
        int denom = denomin * other.numer;
        return Fraction(num, denom);
    }

    void print() const {
        cout << numer << "/" << denomin << endl;
    }
};

int main() {
    Fraction frac1(3, 4);
    Fraction frac2(2, 3);

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;

    cout << "Sum: ";
    sum.print();
    cout << "Diff: ";
    difference.print();
    cout << "pRod: ";
    product.print();
    cout << "Qout: ";
    quotient.print();

    cout << "Shortened and translated fraction: ";
    Fraction improper(9, 4);
    improper.toProper();

    return 0;
}

