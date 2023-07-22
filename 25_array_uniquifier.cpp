#include <iostream>


#include <type_traits>
#include <typeinfo>

// base template
template <typename T>
struct uniquify_t
{
    using type = T;
};

// specialise for similar indexes
template <typename T, int I>
struct uniquify_t<T[I][I]>
{
    using type = typename uniquify_t<T[I]>::type;
};

// specialise for different indexes
template <typename T, int I, int J>
struct uniquify_t<T[I][J]>
{
    using type = typename uniquify_t<T[J]>::type[I];
};

// convenience alias
template <typename T>
using uniquify = typename uniquify_t<T>::type;

int test0 = std::is_same<uniquify<int[2]>, int[2]>::value;
int test1 = std::is_same<uniquify<float[2][2]>, float[2]>::value;
int test2 = std::is_same<uniquify<int[2][2][2]>, int[2]>::value;
int test3 = std::is_same<uniquify<bool[2][3][4][4]>, bool[2][3][4]>::value;
int test4 = std::is_same<uniquify<bool>, bool>::value;
int test5 = std::is_same<uniquify<bool[2][2][2][3][4][4][5][5][6][1][1]>, bool[2][3][4][5][6][1]>::value;

int main()
{
    std::cout << test0 << "\n";
    std::cout << test1 << "\n";
    std::cout << test2 << "\n";
    std::cout << typeid(uniquify<bool[2][3][4][4]>).name() << "\n";
    std::cout << test4 << "\n";
    std::cout << test5 << "\n";
}