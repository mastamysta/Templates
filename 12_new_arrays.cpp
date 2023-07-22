#include <iostream>

static int cid = 0;

class my_class
{
    
    private:

        int obj_id;
    
    public:
    
    
        my_class()
        {
            obj_id = cid;
            std::cout << "Executing constructor for obj " << obj_id <<  "\n";
            cid++;
        }
        
        ~my_class()
        {
            std::cout << "Executing destructor for obj " << obj_id << "\n";
        }
};


int main()
{
    
    my_class* arr = new my_class[10];
    
    my_class* arr1 = new my_class[12];
    
    memcpy(arr, arr1, 8 * sizeof(my_class));
    
    delete[] arr;
    
}