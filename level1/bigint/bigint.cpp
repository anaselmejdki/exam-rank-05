#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint::bigint(unsigned long n)
{
    if (n == 0)
    {
        digits = "0";
        return;
    }
    while (n > 0)
    {
        digits = digits + ((n % 10) + '0');
        n /= 10;
    }
}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
        digits = other.digits;
    return *this;
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

bigint bigint::operator-(const bigint& other) const
{
    if (this != &other)
        return bigint(0);
    return bigint(0);
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

bigint bigint::operator<<(unsigned long n) const
{
    
}