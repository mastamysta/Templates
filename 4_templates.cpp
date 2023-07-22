# include <iostream>

template<typename T, int S>
class array
{
private:
    T arr[S];
    
public:
    
    int length()
    {
        return S;
    }
    
};

int main()
{
 
    array<int, 5> arr;
    
    std::cout << arr.length();
    
    
}