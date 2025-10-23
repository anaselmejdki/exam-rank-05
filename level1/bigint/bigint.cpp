#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int n)
{
    if (n == 0)
    {
        digits = "0";
        return;
    }
    while (n > 0)
    {
        digits = digits + static_cast<char>('0' + (n % 10));
        n /= 10;
    }
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        this->digits = other.digits;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const bigint& other)
{
    for (int i = other.digits.length() - 1; i >=0; --i)
        os << other.digits[i];
    return os;
}

bigint bigint::operator+(const bigint& other) const
{
    bigint result;
    result.digits.clear();
    int carry = 0;
    size_t i = 0;

    while (i < digits.size() || i < other.digits.size() || carry)
    {
        int d1 = (i < digits.size()) ? digits[i] - '0': 0;
        int d2 = (i < other.digits.size()) ? other.digits[i] - '0': 0;
        int sum = d1 + d2 + carry;
        result.digits += (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }
    return result;
}

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint res = *this;
    ++(*this);
    return res;
}

bigint bigint::operator<<(unsigned int n) const
{
    bigint res = *this;
    res.digits.insert(0, n, '0');
    return res;
}

bigint& bigint::operator<<=(unsigned int n)
{
    digits.insert(0, n, '0');
    return *this;
}

bigint bigint::operator>>(unsigned int n) const
{
    bigint res = *this;
    if (n >= res.digits.size())
        res.digits = "0";
    else
        res.digits.erase(0, n);
    return res;
}

bigint& bigint::operator>>=(unsigned int n)
{
    if (n >= digits.size())
        digits = "0";
    else
        digits.erase(0, n);
    return *this;
}


bool bigint::operator==(const bigint& other) const
{
    return (this->digits == other.digits);
}

bool bigint::operator!=(const bigint& other) const
{
    return !(this->digits == other.digits);
}

bool bigint::operator<(const bigint& other) const
{
    if (this->digits.size() != other.digits.size())
        return this->digits.size() < other.digits.size();
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return false;
}

bool bigint::operator<=(const bigint& other) const
{
    return !(*this > other);
}

bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

bigint bigint::operator<<(const bigint& other) const
{
    bigint res = *this;
    unsigned int n = 0;

    for (int i = other.digits.size() - 1; i >= 0; --i)
        n = n * 10 + (other.digits[i] - '0');
    
    res.digits.insert(0, n, '0');
    return res;
}

bigint& bigint::operator<<=(const bigint& other)
{
    unsigned int n = 0;

    for (int i = other.digits.size() - 1; i >= 0; --i)
        n = n * 10 + (other.digits[i] - '0');
    
    digits.insert(0, n, '0');
    return *this;
}

bigint bigint::operator>>(const bigint& other) const
{
    bigint res = *this;
    unsigned int n = 0;

    for (int i = other.digits.size() - 1; i >= 0 ; --i)
        n = n * 10 + (other.digits[i] - '0');
    
    if (n >= res.digits.size())
        res.digits = "0";
    else
        res.digits.erase(0, n);
    return res;
}

bigint& bigint::operator>>=(const bigint& other)
{
    unsigned int n = 0;

    for (int i = other.digits.size() - 1; i >= 0; --i)
        n = n * 10 + (other.digits[i] - '0');
    
    if (n >= digits.size())
        digits = "0";
    else
        digits.erase(0, n);
    return *this;
}

bigint bigint::operator-(const bigint& other) const
{
    if (*this == other)
        return bigint(0);
    return bigint(0);
}