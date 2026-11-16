#include <stdexcept>
#include "Rational.h"

using namespace std;

Rational::Rational() : numerator(0), denominator(1) {}
Rational::Rational(int num) : Rational(num, 1) {}
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
/* 
void Rational::print() const {
    cout << numerator << "/" << denominator << endl;
}*/
// operator overloading for a binary operator
Rational Rational::operator-(const Rational& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    Rational result(num, den);
    return result;
}
Rational Rational::operator*(const Rational& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Rational(num, den);
}
Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0)
        throw invalid_argument("Division by zero");
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Rational(num, den);
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
// cast operator from double data type
Rational::operator double() const {
    return static_cast<double>(numerator) / denominator;
}
// special member function for assignment operator
Rational Rational::operator=(const Rational& other) {
    if (this != &other) { // check for self-assignment
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}
Rational Rational::operator+=(const Rational& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    reduce(); // call reduce on this object
    return *this;
}
Rational Rational::operator-=(const Rational& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    reduce(); 
    return *this;
}
Rational& Rational::operator++() { // prefix increment
    numerator += denominator; // add 1 to the rational number
    reduce(); // reduce the result
    return *this; // return the modified object
}
Rational Rational::operator++(int) { // postfix increment
    Rational temp{*this}; // create a copy of the current object
    numerator += denominator; // add 1 to the rational number
    reduce(); // reduce the result
    return temp; // return the original value before increment
}
// global operators (these are friend functions of the Rational class)
Rational operator+(const Rational& lhs, const Rational& rhs) {
    int num = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
    int den = lhs.denominator * rhs.denominator;
    return Rational(num, den);
}
// the return value of an operator becomes the 
// value of the expression that uses the operator
ostream& operator<<(ostream& os, const Rational& r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}
istream& operator>>(istream& is, Rational& r) {
    is >> r.numerator >> r.denominator;
    return is;
}
