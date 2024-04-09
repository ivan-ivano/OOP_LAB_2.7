// Fraction.cpp
#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <string>


Fraction::Fraction() : fractionalPart(0) {}

Fraction::Fraction(const LongLong& intPart, unsigned short fracPart) : integerPart(intPart), fractionalPart(fracPart) {}

Fraction::Fraction(const Fraction& other) : integerPart(other.integerPart), fractionalPart(other.fractionalPart) {}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart + other.integerPart;
    result.fractionalPart = fractionalPart + other.fractionalPart;
    while (result.fractionalPart >= 10) {
        result.integerPart = result.integerPart + LongLong(0, 1);
        result.fractionalPart -= 10;
    }
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart - other.integerPart;
    result.fractionalPart = fractionalPart - other.fractionalPart;
    while (result.fractionalPart < 0) {
        result.integerPart = result.integerPart - LongLong(0, 1);
        result.fractionalPart += 10;
    }
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result;
    result.integerPart = integerPart * other.integerPart;
    LongLong num = other.integerPart * fractionalPart + integerPart * other.fractionalPart + LongLong(0, fractionalPart * other.fractionalPart / 10);
    result.integerPart = result.integerPart + num / 10;
    result.fractionalPart = num.GetLowPart() % 10;
    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return (integerPart == other.integerPart) && (fractionalPart == other.fractionalPart);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    if (integerPart == other.integerPart) {
        return fractionalPart < other.fractionalPart;
    }
    return integerPart < other.integerPart;
}

bool Fraction::operator<=(const Fraction& other) const {
    if (*this == other) {
        return 1;
    };

    return !(*this > other);
}

bool Fraction::operator>(const Fraction& other) const {
    if (!(*this == other)) {
        return other < *this;
    };

    return 0;
}

bool Fraction::operator>=(const Fraction& other) const {
    if (*this == other) {
        return 1;
    };
    return !(*this < other);
}

Fraction Fraction::operator=(const Fraction& other)
{
    integerPart = other.integerPart;
	fractionalPart = other.fractionalPart;
	return *this;
}


void Fraction::Display() const {
    std::cout << "Fraction: ";
    integerPart.Display();
    std::cout << "Fractional part: " << fractionalPart << std::endl;
}

void Fraction::Read() {
    integerPart.Read();
    std::cout << "Enter Fraction (fractionalPart): " << std::endl;
    std::cin >> fractionalPart;
}

void Fraction::Init(LongLong intPart, unsigned short fracPart)
{
    integerPart = intPart;
    fractionalPart = fracPart;
}

std::string Fraction::ToString(Fraction& a)
{
    std::stringstream ss;
    ss << a.GetIntegerPart().GetHighPart() << " " << a.GetIntegerPart().GetLowPart() << " " << a.GetFractionalPart();

    return ss.str();

}

unsigned short Fraction::GetFractionalPart() const
{
    return fractionalPart;
}

LongLong Fraction::GetIntegerPart() const
{
    return integerPart;
}

void Fraction::SetFractionalPart(unsigned short a)
{
    fractionalPart = a;
}

void Fraction::SetIntegerPart(const LongLong& a)
{
    integerPart = a;
}

std::ostream& operator<<(std::ostream& out, const Fraction& a)
{
	out << "Fraction: " << a.integerPart << " " << a.fractionalPart << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& a)
{
	in >> a.integerPart >> a.fractionalPart;
	return in;
}

Fraction& Fraction::operator++()
{
	integerPart = integerPart + LongLong(0, 1);
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction t(*this);
	integerPart = integerPart + LongLong(0, 1);
	return t;
}

Fraction& Fraction::operator--()
{
	integerPart = integerPart - LongLong(0, 1);
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction t(*this);
	integerPart = integerPart - LongLong(0, 1);
	return t;
}

Fraction::operator std::string() const
{
	std::stringstream ss;
	ss << "Integer part: " << integerPart << " Fractional part: " << fractionalPart;
	return ss.str();
}