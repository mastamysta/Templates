#include <iostream>

/* 

References are a bit controvertial in where people feel they should be used vs. pointers.

Here's the only bit of non-vindictive advice i could find on SO:

'A rather common convention I've encountered is to use references when the parameter must refer an existing object and pointers when a NULL value is ok.'


*/

void my_func(int &integer_reference)
{
    std::cout << integer_reference;
}

int main()
{
    std::string my_string = "Hello world\n";
    
    // a reference is less powerful than a pointer but is still
    // fundamentally just holding the memory address of the referenced object
    std::string &my_reference = my_string;
    
    std::cout << my_reference;
    
    my_string = "Bruh\n";
    
    // The reference behaves as another name for the same variable.
    std::cout << my_reference;
    
    
    
    
   
    // ------------------------------
    
    
    int my_int = 5;
    
    // reference type can also be used to prevent copy-by-value overheads
    // see definition for my_func.
    my_func(my_int);
}