#include "Rational.h"
#include <iostream>
using namespace std;

int main()
{
    Rational r0, r1;
    Rational r2 = r0+r1;
    /** 
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3 = r1 + r2;
    r3.print();
    if (r2 < r1)
        cout << "r2 is less than r1 "  << endl;
    else
        cout << "r2 is not less than r1" << endl;
    ++r2; // add 1 to r2
    r3 = (++r2)*r1; 

    cout << r1; // << is a binary operator, left operand is cout 
    // of type ostream, right operand is r1 of type Rational
    // therefore, I cannot overload the operator<< as a member function of Rational, 
    // because the left operand is not of type Rational
    cout << "r3 = (++r2)*r1: " << r3 << endl;
    cout << "r2 after adding 1 twice: " << r2 << endl;
    r2.print();
    r1+=r2;
    // someFunc(r1+=r2); since r1+=r2 returns a Rational, I can use it in a larger expression, like passing it as an argument to a function
    cout << "r1 after adding r2: " << r1; // <<endl;
    r1.print();
    Rational r8;
    cout << "Enter a rational number as 2 ints, numerator followed by denominator: ";
    cin >> r8;
    cout << "You entered: " << r8 << endl;

    Rational *r4 = new Rational{3, 5};
    Rational *r5 = new Rational{6, 10};
    Rational r6 = *r4 + *r5; // add objects pointed to by r4 and r5
    cout << "operands: " << endl;
    r4->print();
    r5->print();
    cout << "sum: " << endl;
    r6.print();
    if (*r5 == *r4)
        cout << "r5 is equal to r4" << endl;
    else
        cout << "r5 is not equal r4" << endl;
    delete r4;
    delete r5;
***/
    return 0;
}