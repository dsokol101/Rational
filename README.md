#Rational class
Operator Overloading
This is the code from class

In Java, if you have a binary operator, e.g. add

public Rational add(Rational other) {
    
    // get common denominator
    int den=this.den*other.den;
    int num=this.num*other.den + other.num*this.den;

    return new Rational(num, den);
}
to call this suppose you have 2 Rational r1 and r2:
Rational r3 = r1.add(r2);
in C++:
Rational r3 = r1 + r2;