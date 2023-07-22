#include <iostream>

class obj
{

    public:
    
        obj()
        {
            std::cout << "Constructor\n";
        }
        
        ~obj()
        {
            std::cout << "Destructor\n";
        }
  
};

void func(obj& my_obj)
{
    std::cout << "Exiting func\n";
}

int main()
{

    obj my_obj;
    
    func(my_obj);
    
    std::cout << "Exiting program\n";
  
}