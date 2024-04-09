// LongLong.cpp
#include "LongLong.h"
#include <iostream>
#include <sstream>
#include <string>


LongLong::LongLong() : highPart(0), lowPart(0) {}

LongLong::LongLong(long high, unsigned long low) : highPart(high), lowPart(low) {}

LongLong::LongLong(const LongLong& other) : highPart(other.highPart), lowPart(other.lowPart) {}

LongLong LongLong::operator+(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart + other.lowPart;
    result.highPart = highPart + other.highPart + (result.lowPart < lowPart);
    return result;
}

LongLong LongLong::operator-(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart - other.lowPart;
    result.highPart = highPart - other.highPart - (result.lowPart > lowPart);
    return result;
}

LongLong LongLong::operator*(const LongLong& other) const {
    LongLong result;
    result.lowPart = lowPart * other.lowPart;
    result.highPart = highPart * other.highPart;
    return result;
}

bool LongLong::operator==(const LongLong& other) const {
    return (highPart == other.highPart) && (lowPart == other.lowPart);
};

bool LongLong::operator!=(const LongLong& other) const {
    return !(*this == other);
};

bool LongLong::operator<(const LongLong& other) const {
    if (highPart == other.highPart) {
        return lowPart < other.lowPart;
    }
    return highPart < other.highPart;
}

bool LongLong::operator>(const LongLong& other) const {
    if (!(*this == other)) {
        return other < *this;
    };

    return 0;
}

bool LongLong::operator<=(const LongLong& other) const {
    if (*this == other) {
        return 1;
    };

    return !(*this > other);
}

bool LongLong::operator>=(const LongLong& other) const {
    if (*this == other) {
        return 1;
    };
    return !(*this < other);
}

LongLong LongLong::operator=(const LongLong& other)
{
    highPart = other.highPart;
	lowPart = other.lowPart;
	return *this;
}

LongLong& LongLong::operator++()
{
    *this = *this + LongLong(0, 1);
	return *this;
}

LongLong LongLong::operator++(int)
{
	LongLong result = *this;
	++(*this);
	return result;
}

LongLong& LongLong::operator--()
{
	*this = *this - LongLong(0, 1);
	return *this;
}

LongLong LongLong::operator--(int)
{
    LongLong result = *this;
	--(*this);
	return result;
}

LongLong::operator string() const
{
	stringstream ss;
	ss << "High part: " << highPart << " Low part: " << lowPart;
	return ss.str();
}

LongLong LongLong::operator*(const int& other) const {
    LongLong result;
    result.lowPart = lowPart * other;
    result.highPart = highPart * other;
    return result;
}

LongLong LongLong::operator/(const int& other) const {
    LongLong result;
    result.lowPart = lowPart / other;
    result.highPart = highPart / other;
    result.lowPart += (ULONG_MAX + 1ull) / other * (result.highPart % other);
    return result;
}

long LongLong::GetHighPart() const
{
    return highPart;
}

unsigned long LongLong::GetLowPart() const
{
    return lowPart;
}

void LongLong::SetHighPart(long a)
{
    highPart = a;
}

void LongLong::SetLowPart(unsigned long a)
{
    lowPart = a;
}

void LongLong::Display() const {
    std::cout << "LongLong: " << highPart << " " << lowPart << std::endl;
}

void LongLong::Read() {
    std::cout << "Enter LongLong (highPart lowPart): ";
    std::cin >> highPart >> lowPart;
}

void LongLong::Init(long high, unsigned long low)
{
    highPart = high;
    lowPart = low;
}

std::string LongLong::ToString(LongLong& a)
{
    std::stringstream ss;
    ss << a.GetHighPart() << " " << a.GetLowPart();

    return ss.str();
}

istream& operator>>(istream& in, LongLong& a)
{
    in >> a.highPart >> a.lowPart;
	return in;
}

ostream& operator<<(ostream& out, const LongLong& a)
{
	out << "High part: " << a.highPart << " Low part: " << a.lowPart;
	return out;
}
