// Calculator.h
#include "Fraction.h"

class Calculator {
public:
    static Fraction Add(const Fraction& a, const Fraction& b);
    static Fraction Subtract(const Fraction& a, const Fraction& b);
    static Fraction Multiply(const Fraction& a, const Fraction& b);
};


