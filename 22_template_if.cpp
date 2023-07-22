#include <iostream>

struct a
{
    static const int value = 0;
};

struct b
{
    static const int value = 1;
};

// tempalte if statements

template <bool predicate, typename THEN, typename ELSE>
struct if_{};

template <typename THEN, typename ELSE>
struct if_<true, THEN, ELSE>
{
    using type = THEN;
};

template <typename THEN, typename ELSE>
struct if_<false, THEN, ELSE>
{
    using type = ELSE;
};



int main()
{
    std::cout << if_<true, a, b>::type::value << "\n";
    std::cout << if_<false, a, b>::type::value << "\n";
    
    
    std::cout << if_<true, a, if_<false, a, b>::type>::type::value << "\n";
}