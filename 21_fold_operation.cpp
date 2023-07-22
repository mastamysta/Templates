#include <iostream>

template <int... I>
struct Vector {};


template <typename V>
struct fd {};

template <int... I>
struct fd<Vector<I...>>
{
    static constexpr int value = ( 0 + ... );
};

// not allowed without c++17

int main()
{
    
    std::cout << fd<Vector<2>>::value << "\n";
    std::cout << fd<Vector<2,2,2,2,2>>::value << "\n";
    std::cout << fd<Vector<2,3,4,4,5>>::value << "\n";
    std::cout << fd<Vector<2,2,3,4,4,5>>::value << "\n";
    
}