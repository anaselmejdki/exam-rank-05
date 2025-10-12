#pragma once

#include <iostream>
#include <string>

class bigint {
    private:
        std::string digits;
    public:
        //Constructors
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& other);
        //arithmetic
        bigint operator+(const bigint& other) const;
        bigint operator-(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        //Increment
        bigint& operator++();
        bigint operator++(int);
        //digit shift
        bigint operator<<(unsigned int n) const;
        bigint& operator<<=(unsigned int n);
        bigint operator>>(unsigned int n) const;
        bigint& operator>>=(unsigned int n);
        //Comparison
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;
        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        
        //overloading
        bigint operator<<(const bigint& other) const;
        bigint& operator<<=(const bigint& other);
        bigint operator>>(const bigint& other) const;
        bigint& operator>>=(const bigint& other);
        
        friend std::ostream& operator<<(std::ostream& os, const bigint& other);
        friend unsigned int to_uint(const bigint& other);
};