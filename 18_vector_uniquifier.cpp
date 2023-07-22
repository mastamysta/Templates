#include <iostream>

// declare vector just for lols
template <int... Is>
struct Vector
{}; // not implemented


// base template for smoosh, not implemented
template<typename T, typename U>
struct smoosh
{}; // not implemented

// template to smoosh two vector types
template <int... Is, int... Js>
struct smoosh<Vector<Is...>, Vector<Js...>>
{
    using type = Vector<Is..., Js...>;
};

// base template
template <typename T>
struct get_unique_vect
{
    using type = T;
};

template <int I, int J, int... Is>
struct get_unique_vect<Vector<I, J, Is...>>
{
    using type = typename smoosh<Vector<I>, typename get_unique_vect<Vector<J, Is...>>::type>::type;
};

template <int I, int... Is>
struct get_unique_vect<Vector<I, I, Is...>>
{
    using type = typename get_unique_vect<typename smoosh<Vector<I>, Vector<Is...>>::type>::type;
};



// convenience template to get into our struct
template <typename T>
using get_unique = typename get_unique_vect<T>::type;

int main()
{
    
    std::cout << std::is_same<get_unique<Vector<2>>, Vector<2>>::value << "\n";
    std::cout << std::is_same<get_unique<Vector<2,2,2>>, Vector<2>>::value << "\n";
    std::cout << std::is_same<get_unique<Vector<2,2,2,2,2>>, Vector<2>>::value << "\n";
    std::cout << std::is_same<get_unique<Vector<2,3,4,4,5>>, Vector<2,3,4,5>>::value << "\n";
    std::cout << std::is_same<get_unique<Vector<2,2,3,4,4,5>>, Vector<2,3,4,5>>::value << "\n";
    
}