// main.cpp
#include "Calculator.h"
#include <iostream>
#include <string>
#include <sstream>

int main() {
    Fraction fraction1, fraction2;

    fraction1.Read();
    fraction1.Display();
    fraction2.Read();
    fraction2.Display();

    Fraction resultAdd = Calculator::Add(fraction1, fraction2);
    Fraction resultSubtract = Calculator::Subtract(fraction1, fraction2);
    Fraction resultMultiply = Calculator::Multiply(fraction1, fraction2);

    std::cout << "\nResults:\n";
    std::cout << "Result of addition:\n";
    resultAdd.Display();

    std::cout << "\nResult of subtraction:\n";
    resultSubtract.Display();

    std::cout << "\nResult of multiplication:\n";
    resultMultiply.Display();

    std::cout << "\nResult of multiplication:\n";
    resultMultiply.Display();


    std::cout << "Equality check:\n";
    if (fraction1 == fraction2) {
        std::cout << "Fractions are equal\n";
    }
    else {
        std::cout << "Fractions are not equal\n";
    }

    fraction1++;
    fraction2--;
    std::cout << "Increment and decrement:\n";
    std::cout << "Fraction 1 after increment: " << fraction1;
    std::cout << "Fraction 2 after decrement: " << fraction2;


    return 0;
}
