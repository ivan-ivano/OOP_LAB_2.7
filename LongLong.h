// LongLong.
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class LongLong {
private:
    long highPart;
    unsigned long lowPart;

public:
    LongLong();
    LongLong(long high, unsigned long low);
    LongLong(const LongLong& other);

    LongLong operator+(const LongLong& other) const;
    LongLong operator-(const LongLong& other) const;
    LongLong operator*(const LongLong& other) const;

    bool operator==(const LongLong& other) const;

    bool operator!=(const LongLong& other) const;

    bool operator<(const LongLong& other) const;

    bool operator>(const LongLong& other) const;

    bool operator<=(const LongLong& other) const;

    bool operator>=(const LongLong& other) const;

    LongLong operator=(const LongLong& other);

    friend ostream& operator<<(ostream& out, const LongLong& a);
    friend istream& operator>>(istream& in, LongLong& a);

    LongLong& operator++();
    LongLong operator++(int);
    LongLong& operator--();
    LongLong operator--(int);

    operator string() const;

    LongLong operator*(const int& other) const;

    LongLong operator/(const int& other) const;

    long GetHighPart() const;
    unsigned long GetLowPart() const;
    void SetHighPart(long a);
    void SetLowPart(unsigned long a);

    void Display() const;
    void Read();

    void Init(long high, unsigned long low);

    std::string ToString(LongLong& a);
};
