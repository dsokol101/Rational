#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;
    void reduce();

public:
    Rational();
    Rational(int);
    Rational(int, int);
    void print() const;

    //Rational operator=(const Rational &); // assignment not necessary here
    //Rational operator+=(const Rational &); // note NO const bec we are modifying
    // the left operand
    // also, note the return type. That's bec we want the expression to evaluate
    // to the left operand after the operation is done
    //Rational operator-=(const Rational &);
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;
    bool operator<(const Rational &) const;
    bool operator>(const Rational &) const;
    bool operator<=(const Rational &) const;
    bool operator>=(const Rational &) const;
    // instead of .equals() method of Java
    bool operator==(const Rational &) const;
    bool operator!=(const Rational &) const;
    // overload casting operator
    explicit operator double() const;
    friend Rational operator+(const Rational& lhs, const Rational& rhs);
    //void operator++(); // prefix increment
    //Rational operator++(int); // postfix increment
    // instead of .toString() method of Java
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    // instead of writing a .read() method
    friend std::istream& operator>>(std::istream&, Rational&);
};
// global fuction

#endif
