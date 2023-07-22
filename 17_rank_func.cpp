#include <iostream>

// can't use a function as we *need* partial specialization to determine type T from T[]
template <typename T>
struct get_dim
{
    // need static so we don't need to instantiate the struct
    // need const qualifier to be allowed to initialise a static
    static const size_t value = 0;
};

// now we partially specialise the base template
template <typename T, size_t N>
struct get_dim<T[N]>
{
    static const size_t value = 1 + get_dim<T>::value;
};

int main()
{
    
    std::cout << get_dim<size_t>::value << "\n"; // 0
    std::cout << get_dim<int[1]>::value << "\n"; // 1
    std::cout << get_dim<float[3][4][2][4][4]>::value << "\n"; // 5
    
}