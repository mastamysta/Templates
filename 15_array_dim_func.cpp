#include <iostream>

template <typename T>
class rank
{
    public:
    
        static const size_t value = 0;
};

template <typename T, size_t S>
class rank<T[S]>
{
    public:
    
        static const size_t value = 1 + rank<T>::value;
};

int main()
{
    std::cout << rank<size_t>::value << "\n"; // 0
    std::cout << rank<int[1]>::value << "\n"; // 1
    std::cout << rank<float[3][4][2][4][4]>::value << "\n"; // 5
    
}