#include <iostream>

template <typename T>
struct is_float
{
    static constexpr bool value = false;
};

template <>
struct is_float<float>
{
    static constexpr bool value = true;
};

template <typename T>
struct strip_ptr{};

template <typename T>
struct strip_ptr<T*>
{
    using type = T;
};

int main()
{
    

    
    // we want metafunction check whether a type is a float
    
    std::cout << is_float<float>::value << "\n";
    std::cout << is_float<strip_ptr<float*>::type>::value << "\n";
    std::cout << is_float<void>::value << "\n";
    
}