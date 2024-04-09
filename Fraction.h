// Fraction.h
#include "LongLong.h"

class Fraction {
private:
    LongLong integerPart;
    unsigned short int fractionalPart;

public:
    Fraction();
    Fraction(const LongLong& intPart, unsigned short fracPart);
    Fraction(const Fraction& other);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    bool operator==(const Fraction& other) const;

    bool operator!=(const Fraction& other) const;

    bool operator<(const Fraction& other) const;

    bool operator<=(const Fraction& other) const;

    bool operator>(const Fraction& other) const;

    bool operator>=(const Fraction& other) const;

    Fraction operator=(const Fraction& other);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& a);
    friend std::istream& operator>>(std::istream& in, Fraction& a);

    operator std::string() const;

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    void Display() const;
    void Read();
    void Init(LongLong intPart, unsigned short fracPart);
    std::string ToString(Fraction& a);

    LongLong GetIntegerPart() const;
    unsigned short GetFractionalPart() const;
    void SetIntegerPart(const LongLong& a);
    void SetFractionalPart(unsigned short a);
};
