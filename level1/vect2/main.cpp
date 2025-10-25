
#include "vect2.hpp"
#include <iostream>
int main() 
{
    vect2 v1; // {0, 0}
    vect2 v2(1, 2); // {1, 2}
    const vect2 v3(v2); // {1, 2}
    vect2 v4 = v2; // {1, 2}

    std::cout << "v1: " << v1 << std::endl;        // v1: {0, 0}
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl; // v1: {0, 0}
    std::cout << "v2: " << v2 << std::endl;        // v2: {1, 2}
    std::cout << "v3: " << v3 << std::endl;        // v3: {1, 2}
    std::cout << "v4: " << v4 << std::endl;        // v4: {1, 2}

    std::cout << v4++ << std::endl; // prints old value {1, 2}, then v4 = {2, 3}
    std::cout << ++v4 << std::endl; // increments first → v4 = {3, 4}, prints {3, 4}
    std::cout << v4-- << std::endl; // prints old value {3, 4}, then v4 = {2, 3}
    std::cout << --v4 << std::endl; // decrements first → v4 = {1, 2}, prints {1, 2}

    v2 += v3; // v2 = (1,2) + (1,2) = {2, 4}
    v1 -= v2; // v1 = (0,0) - (2,4) = {-2, -4}
    v2 = v3 + v3 * 2; // v3*2 = (2,4); v3+(2,4) = {3, 6}
    v2 = 3 * v2; // 3*{3,6} = {9,18}
    v2 += v2 += v3; 
    // inner: v2 += v3 → {10,20}
    // outer: v2 += {10,20} → {20,40}
    v1 *= 42; // (-2,-4)*42 = {-84, -168}
    v1 = v1 - v1 + v1; 
    // v1 - v1 = {0,0}; {0,0} + v1 = {-84, -168} → v1 = {-84, -168}

    std::cout << "v1: " << v1 << std::endl;        // v1: {-84, -168}
    std::cout << "v2: " << v2 << std::endl;        // v2: {20, 40}
    std::cout << "-v2: " << -v2 << std::endl;      // -v2: {-20, -40}
    std::cout << "v1[1]: " << v1[1] << std::endl;  // v1[1]: -168
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;  // v1[1]: 12
    std::cout << "v3[1]: " << v3[1] << std::endl;  // v3[1]: 2
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl; // 0 (false)
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl; // 1 (true)
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl; // 1 (true)
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl; // 0 (false)
}
