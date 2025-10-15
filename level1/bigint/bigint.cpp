#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(unsigned int n)
{
    if (n == 0)
    {
        digits = "0";
        return ;
    }
    while(n > 0)
    {
        digits += static_cast<char>('0' + (n % 10));
        n /= 10;
    }
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint& other)
{
    if (*this != other)
        this->digits = other.digits;
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
        int dig1 = (i < digits.size()) ? digits[i] - '0' : 0;
        int dig2 = (i < other.digits.size()) ? other.digits[i] - '0' : 0;
        int sum = dig1 + dig2 + carry;
        result.digits += (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }
    return result;
}

bigint bigint::operator-(const bigint& other) const
{
    if (*this == other)
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
    bigint result = *this;
    ++(*this);
    return result;
}

bigint bigint::operator<<(unsigned int n) const
{
    bigint result = *this;
    result.digits.insert(result.digits.begin(), n, '0');
    return result;
}

bigint& bigint::operator<<=(unsigned int n)
{
    digits.insert(digits.begin(), n, '0');
    return *this;
}

bigint bigint::operator>>(unsigned int n) const
{
    bigint result = *this;
    if (n >= result.digits.size())
        result.digits = "0";
    else
        result.digits.erase(result.digits.begin(), result.digits.begin() + n);
    return result;
}

bigint& bigint::operator>>=(unsigned int n)
{
    if (n >= digits.size())
        digits = "0";
    else
        digits.erase(digits.begin(), digits.begin() + n);
    return *this;
}

bool bigint::operator==(const bigint& other) const { return digits == other.digits; }

bool bigint::operator!=(const bigint& other) const { return !(*this == other); }

bool bigint::operator<(const bigint& other) const
{
    if (digits.size() != other.digits.size())
        return (digits.size() < other.digits.size());
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        if (digits[i] != other.digits[i])
            return (digits[i] < other.digits[i]);
    }
    return false;
}

bool bigint::operator<=(const bigint& other) const { return !(*this > other); }

bool bigint::operator>(const bigint& other) const { return (other < *this); }

bool bigint::operator>=(const bigint& other) const { return !(*this < other); }

bigint bigint::operator<<(const bigint& other) const { return (*this << to_uint(other)); }

bigint& bigint::operator<<=(const bigint& other) { return (*this <<= to_uint(other)); }

bigint bigint::operator>>(const bigint& other) const { return (*this >> to_uint(other)); }

bigint& bigint::operator>>=(const bigint& other) { return (*this >>= to_uint(other)); }

std::ostream& operator<<(std::ostream& os, const bigint& other)
{
    for (int i = other.digits.size() - 1; i >= 0; --i)
        os << other.digits[i];
    return os;
}

unsigned int to_uint(const bigint& other)
{
    unsigned int result = 0;
    for (int i = other.digits.size() - 1; i >= 0; --i)
        result = result * 10 + (other.digits[i] - '0');
    return result;
}
