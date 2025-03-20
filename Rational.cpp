#include "Rational.h"
#include <iostream>
#include <numeric>
using namespace std;

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
Rational::Rational(int n, int d)
{
    numerator = n;
    denominator = d;
    reduce();
}
void Rational::reduce()
{
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}
Rational Rational::operator+(const Rational& other) const {
    int den=denominator*other.denominator;
    int num=numerator*other.denominator + other.numerator*denominator;
    Rational sum(num,den);
    sum.reduce();
    return sum;
}
Rational Rational::operator-(const Rational& other) const {
    int den=denominator*other.denominator;
    int num=numerator*other.denominator - other.numerator*denominator;
    Rational diff(num,den);
    diff.reduce();
    return diff;
}   
Rational Rational::operator*(const Rational& other) const {
    int den=denominator*other.denominator;
    int num=numerator*other.numerator;
    Rational prod(num,den);
    prod.reduce();
    return prod;
}
Rational Rational::operator/(const Rational& other) const {
    int den=denominator*other.numerator;
    int num=numerator*other.denominator;
    Rational quot(num,den);
    quot.reduce();
    return quot;
}
bool Rational::operator<(const Rational& other) const {
    return numerator*other.denominator < other.numerator*denominator;
}
bool Rational::operator>(const Rational& other) const {
    return numerator*other.denominator > other.numerator*denominator;
}
bool Rational::operator<=(const Rational& other) const {
    return numerator*other.denominator <= other.numerator*denominator;
}   
bool Rational::operator>=(const Rational& other) const {
    return numerator*other.denominator >= other.numerator*denominator;
}
bool Rational::operator!=(const Rational& other) const {
    return numerator*other.denominator != other.numerator*denominator;
}
bool Rational::operator==(const Rational& other) const {
    //return numerator*other.denominator == other.numerator*denominator;
    return numerator == other.numerator && denominator == other.denominator;
}
// prefix increment
Rational Rational::operator++() {
    numerator += denominator;
    reduce();
    return *this;
}   
// postfix increment
Rational Rational::operator++(int) {
    Rational temp = *this;
    numerator += denominator;
    reduce();
    return temp;
}
void Rational::print() const
{
    cout << numerator << "/" << denominator << endl;
}   