#include <iostream>

template <size_t A>
struct gcd<A, 0>
{
    static const size_t value = A;
};

template <size_t A, size_t B>
struct gcd<A, B>
{
    static const size_t value = gcd<B, A%B>::value;
};


// gcd is recursive gcd(b, a%b) until b = 0 (return a)

int programmatic_gcd(size_t a, size_t b)
{
    if (b == 0) return a;
    return programmatic_gcd(b, a%b);
}

int main()
{
    
    //std::cout << programmatic_gcd(862, 418) << "\n";
    std::cout << gcd<862, 418>::value << "\n";
}