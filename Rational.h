#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
    int numerator;
    int denominator;
    void reduce();

public:
    Rational();
    Rational(int, int);
    Rational operator+(const Rational &) const;
    void print() const;

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
    Rational operator++(); // prefix increment
    Rational operator++(int); // postfix increment
    // instead of .toString() method of Java
    //   friend std::ostream& operator<<(std::ostream&, const Rational&);
    // instead of writing a .read() method
    //   friend std::istream& operator>>(std::istream&, Rational&);
};
#endif
