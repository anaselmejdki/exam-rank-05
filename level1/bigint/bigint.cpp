#include "bigint.hpp"

bigint bigint::operator<<(unsigned int shift) const
{
  if (digits == "0") return bigint(0);
  bigint res = *this;
  res.digits.insert(0, shift, '0');
  return res;
}

bigint &bigint::operator++()
{
  return *this += bigint(1);
}

bigint bigint::operator++(int){
  // affectation then assignement it means i will create a temp to store this then increment this
  bigint tmp = *this;
  ++(*this);
  return tmp;
}

bigint &bigint::operator=(const bigint &other)
{
  if (this != &other)
    digits = other.digits;
  return *this;
}

bigint bigint::operator+(const bigint &other) const
{
  // 1337 => 7331 
  //   38 => 83  
  bigint res;
  res.digits.clear();

  size_t i = 0;
  int carry = 0;
  while (i < digits.size() || i < other.digits.size() || carry)
  {
    int d1 = 0;
    if (i < digits.size())
      d1 = digits[i] - '0';
    
    int d2 = 0;
    if (i < other.digits.size())
      d2 = other.digits[i] - '0';

    int sum = d1 + d2 + carry;
    res.digits += (sum % 10) + '0';
    carry = sum / 10;
    i++;
  }
  return res;
}

bigint& bigint::operator+=(const bigint& other) {
	*this = *this + other;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const bigint& b);

const std::string& bigint::getDigits() const {
  return this->digits;
}

std::ostream &operator<<(std::ostream &os, const bigint &b)
{
  std::string digits = b.getDigits();
  std::reverse(digits.begin(), digits.end());
  size_t first_non_zero = digits.find_first_not_of('0');
  if (first_non_zero == std::string::npos)
    os << '0';
  else {
    os << digits.substr(first_non_zero);
  }
  return os;
}


bigint::bigint() : digits("0")
{
}

bigint::bigint(const bigint &other) : digits(other.digits)
{
}

bigint::bigint(unsigned long n)
{
    if (n == 0)
        digits = "0";
    while (n)
    {
        digits += n % 10 + 48;
        n /= 10;
    }
}

bigint& bigint::operator<<=(unsigned long n)
{
    digits.insert(0, n, '0');
    return *this;
}

bigint& bigint::operator>>=(unsigned long n)
{
    if ( n >= digits.size())
        digits = "0";
    else
        digits.erase(0, n);
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    unsigned long  n = 0;

    for (int i = other.digits.size() - 1; i >= 0; --i)
        n = n * 10 + (other.digits[i] - '0');
    
    if (n >= digits.size())
        digits = "0";
    else
        digits.erase(0, n);
    return *this;
}

bool bigint::operator==(const bigint& other) const { return (this->digits == other.digits); }

bool bigint::operator!=(const bigint& other) const { return (this->digits != other.digits); }

bool bigint::operator<(const bigint& other) const
{
    if (this->digits.size() != other.digits.size())
        return this->digits.size() < other.digits.size();
    
    for (int i = digits.size(); i >= 0; --i)
    {
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return false;
}

bool bigint::operator<=(const bigint& other) const { return !(*this > other); }

bool bigint::operator>(const bigint& other) const { return (other < *this); }

bool bigint::operator>=(const bigint& other) const { return !(*this < other); }




