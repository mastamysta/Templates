#include <iostream>

template <typename T>
struct rank
{
    static const size_t value = 0;
};

template <typename T, size_t N>
struct rank<T[N]>
{
    static const size_t value = 1 + rank<T>::value;
};

template <typename T>
struct rank<T[]>
{
    static const size_t value = 1 + rank<T>::value;
};

int main()
{
    
    std::cout << rank<int>::value << "\n";
    std::cout << rank<int[][4][5][2][3]>::value << "\n";
    
}