#include <iostream>

template <typename T>
class dynamic_array
{
    
    private:
    
        T* data;
        
        static const size_t STARTING_ARR_SIZE = 8;
        size_t array_size;
        
        
        // desired_size should always be the desired index+1
        void check_resize(size_t desired_size)
        {
            
            // bail out if array is already big enough
            if (desired_size <= array_size)
                return;
            
            int expanded_size = desired_size * 2;
            
            std::cout << "Resize required: " << array_size << " -> " << desired_size << "\n";
            std::cout << "Resized to: " << expanded_size << "\n";
            
            T* expanded_data = new T[expanded_size];
            std::copy(data, data + array_size, expanded_data);
            delete data;
            data = expanded_data;
            array_size = expanded_size;
        }
    
    public:
    
        dynamic_array()
        {
            data = new T[STARTING_ARR_SIZE];
            array_size = STARTING_ARR_SIZE;
        }
        
        ~dynamic_array()
        {
            delete[] data;
        }
    
        // In vanilla C, the [i] operator behaves as syntactic sugar for *(ptr + i), dereferencing the the data at the actual address allows the user to modify the object like this: arr[4] = 5;.
        // To emulate this behaviour we return a reference, which means the caller of the operator[] will be able to modify the underlying data within the dynamic array rather than being returned a copy.
        T& operator[](size_t i)
        {
            check_resize(i + 1);
            
            return data[i];
        }
        
};



// need to overload [] operator and maybe []=

int main()
{
    
    dynamic_array<int> int_array;
    
    int_array[2] = 4;
    int_array[8] = 5;
    
    std::cout << int_array[2] << "\n";
    std::cout << int_array[85] << "\n";
}
