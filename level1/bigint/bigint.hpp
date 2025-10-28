#include <algorithm> // Required for std::reverse
#include <iostream>
#include <string>

class bigint
{
  private:
    std::string digits;

  public:
    bigint();                               // default constructor.
    bigint(unsigned long n);                // constructor with params.
    bigint(const bigint &other);            // copy constructor
    bigint &operator=(const bigint &other); // copy  assignement operat


    bigint operator+(const bigint &other) const;
    bigint &operator+=(const bigint &other);
    bigint operator++(int);
    bigint &operator++();
    bigint operator<<(unsigned int shift) const;
    const std::string &getDigits() const;
    friend std::ostream& operator<<(std::ostream& os, const bigint& b);

    bigint& operator<<=(unsigned long n);
    bigint& operator>>=(unsigned long n);
    bigint& operator>>=(const bigint& other);

    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator>=(const bigint& other) const;
};