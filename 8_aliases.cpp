#include <iostream>

template <typename T>
class array
{
    
    private:
    
        int l = 0;
        
        T data;

    public:
        
        array(int length)
        {
            l = length;
        }
        
        int len()
        {
            return l;
        }
};

// the using keyword allows us to declare an alias for our class. This is the same as a typedef but it sopports templates.

template <typename T>
using arr = array<T>;

int main()
{
    arr<int> my_arr(5);
    
    std::cout << my_arr.len() << std::endl;
}