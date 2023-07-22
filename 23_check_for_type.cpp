/**
 * Write a compile-time solution that checks is a list of parameters
 * contains a given type. (See the test cases bellow)
 *
 * By convention, first type is the target of the lookup, the remaining types are used as pack
 *
 * 1. Add a definition of `val` that specialize the case where the list _has_ a type
 * 2. Implement the list-lookup solution
 * 3. Fix the alias definition with your solution
 * 4. Test
 *
 */

#include <iostream>
#include <type_traits>

namespace detail {
/////////////////////////////////////////////
// TODO: Look in the type list for a matching type.
/////////////////////////////////////////////

// base template
template <typename T, typename U>
struct lookup_type_in_tuple
{
    using type = std::false_type;
};

// specialise true
template <typename T, typename... Pack>
struct lookup_type_in_tuple<T, std::tuple<T, Pack...>>
{
    using type = std::true_type;
};

// specialise recurse
template <typename T, typename U, typename... Pack>
struct lookup_type_in_tuple<T, std::tuple<U, Pack...>>
{
    using type = typename lookup_type_in_tuple<T, std::tuple<Pack...>>::type;
};

// Convenience call alias
template <typename T, typename... Pack>
using tuple_contains_type = typename lookup_type_in_tuple<T, std::tuple<Pack...>>::type;

// Conditional values for test
template<bool>
struct val {
    static constexpr char* value = "Does not have type";
};

template<> // complete specialisation for true case
struct val<true> {
    static constexpr char* value = "Does have type!";
};

} // namespace detail

template<typename LookupType, typename... Pack>
struct test : public detail::val<detail::tuple_contains_type<LookupType, Pack...>::value> {};

struct A{};
struct B{};
struct C{};
struct D{};

using pass = test<A, B, A, D, A, D>;
using fail = test<A, C, D, B, C>;
using meh = test<A, C, D, B, A>;
using aa = test<A, B>;

int main() {
    std::cout << "Test A in B, A, D, A, D: " << pass::value << std::endl;	
    std::cout << "Test A in C, D, B, C: " << fail::value << std::endl;	
    std::cout << "Test A in C, D, B, A: " << meh::value << std::endl;	
    std::cout << "Test A in B " << aa::value << std::endl;
    return 0;
}