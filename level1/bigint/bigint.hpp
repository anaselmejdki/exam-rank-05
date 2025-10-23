#pragma once

#include <iostream>
#include <string>

class bigint {
    private:
        std::string digits;
    public:
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);

        friend std::ostream& operator<<(std::ostream& os, const bigint& other);

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        bigint& operator++();
        bigint operator++(int);

        bigint operator<<(unsigned int n) const;
        bigint& operator<<=(unsigned int n);
        bigint operator>>(unsigned int n) const;
        bigint& operator>>=(unsigned int n);

        // bigint& operator>>=(const bigint& other);

        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;

        bigint operator<<(const bigint& other) const;
        bigint& operator<<=(const bigint& other);
        bigint operator>>(const bigint& other) const;
        bigint& operator>>=(const bigint& other);

        bigint operator-(const bigint& other) const;
};