#pragma once

#include <iostream>
#include <string>


class bigint {
    private:
        std::string digits;
    public:
        //constructors
        bigint();
        bigint(unsigned int n);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);
        //Arithmetci
        bigint operator+(const bigint& other) const;
        bigint operator-(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        //Increment
        bigint& operator++();
        bigint operator++(int);
        //shifting
        bigint operator<<(unsigned int n) const;
        bigint& operator<<=(unsigned int n);
        bigint operator>>(unsigned int n) const;
        bigint& operator>>=(unsigned int n);
        //comparison
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
        //functions
        friend std::ostream& operator<<(std::ostream& os, const bigint& other);
        friend unsigned int to_uint(const bigint& other);
};
