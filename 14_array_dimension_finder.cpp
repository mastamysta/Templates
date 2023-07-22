#include <iostream>
// write a template metafunction to find dimension of array of any type at compile time. 1D? 2D? 3D?


template <typename T>
struct get_dim
{
    static constexpr size_t value = 0;
};


template <typename T, size_t N>
struct get_dim<T[N]> // what is this bit of syntax here?? we use the angled brackets to indicate something
{
    static constexpr size_t value = 1 + get_dim<T>::value;
};


int main()
{
    
    std::cout << get_dim<size_t>::value << "\n"; // 0
    std::cout << get_dim<int[1]>::value << "\n"; // 1
    std::cout << get_dim<float[3][4][2][4][4]>::value << "\n"; // 5
    
}