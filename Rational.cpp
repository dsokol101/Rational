#include <stdexcept>
#include "Rational.h"

using namespace std;

Rational::Rational() : numerator(0), denominator(1) {}


Rational::Rational(int num, int den) : numerator(num), denominator(den) {
    if (den == 0)
        throw invalid_argument("Denominator cannot be zero");
    reduce();
}
void Rational::reduce() {
    int gcd = 1;
    int a = numerator;
    int b = denominator;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    numerator /= gcd;
    denominator /= gcd;
}
void Rational::print() const {
    cout << numerator << "/" << denominator << endl;
}
// operator overloading for a binary operator
Rational Rational::operator+(const Rational& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    Rational result(num, den);
    result.reduce();
    return result;
}
Rational Rational::operator-(const Rational& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    Rational result(num, den);
    result.reduce();
    return result;
}
Rational Rational::operator*(const Rational& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    Rational result(num, den);
    result.reduce();
    return result;
}
Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0)
        throw invalid_argument("Division by zero");
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    Rational result(num, den);
    result.reduce();
    return result;
}   
bool Rational::operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator>(const Rational& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<=(const Rational& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Rational::operator>=(const Rational& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}

bool Rational::operator==(const Rational& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Rational::operator!=(const Rational& other) const {
    return numerator * other.denominator != other.numerator * denominator;
}   