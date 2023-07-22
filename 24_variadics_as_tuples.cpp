#include <iostream>

// template declaration
template <int B, int... Is>
struct sum_v
{
    static const int value = B + sum_v<Is...>::value;
};

template <int B>
struct sum_v<B>
{
    static const int value = B;
};

// convenience template
template <int B, int... Is>
int sum = sum_v<B, Is...>::value;

int main()
{
    // template that goes through variadic list of ints and sums them
    
    std::cout << sum<1, 2, 3, 4, 5, 6> << "\n";
}