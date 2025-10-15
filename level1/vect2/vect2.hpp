#pragma once

#include <iostream>
#include <string>

class vect2 {
    private:
        int x;
        int y;
    public:
        //Constructor
        vect2();
        vect2(int x, int y);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        //arith
        vect2 operator+(const vect2& other) const;
        vect2& operator+=(const vect2& other);
        vect2 operator-(const vect2& other) const;
        vect2& operator-=(const vect2& other);
        vect2 operator*(int scalar) const;
        vect2& operator*=(int scalar);
        //comparison
        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;
        //postfix prefix
        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);
        //minus
        vect2 operator-() const;
        //[]
        int& operator[](int scalar);
        const int& operator[](int scalar) const;
        //friend
        friend vect2 operator*(int scalar, const vect2& other);
        friend std::ostream& operator<<(std::ostream& os, const vect2& other);

};