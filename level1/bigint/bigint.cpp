#include "bigint.hpp"

bigint::bigint() : digits("0"), negative(false) {}

bigint::bigint(unsigned int n) : negative(false)
{
    digits.clear();
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

bigint::bigint(int n)
{
    if (n < 0)
    {
        negative = true;
        n = -n;
    }
    else
        negative = false;
    while (n > 0)
    {
        digits += static_cast<char>('0' + (n % 10));
        n /= 10;
    }
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
    {
        this->digits = other.digits;
        negative = other.negative;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const bigint& other)
{
    if (other.negative && !(other.digits.size() == 0 && other.digits[0] == '0'))
        os << '-';
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
    if (negative != other.negative)
        return negative;
    
    bool result;
    if (this->digits.size() != other.digits.size())
        result = this->digits.size() < other.digits.size();
    else
    {
        result = false;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] != other.digits[i])
            {
                result = digits[i] < other.digits[i];
                break;
            }
        }
    }
    return negative ? !result && *this != other : result;
}

bool bigint::operator<=(const bigint& other) const
{
    return (*this < other || *this == other);
}

bool bigint::operator>(const bigint& other) const
{
    return !(*this <= other);
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