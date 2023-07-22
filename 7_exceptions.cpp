#include <iostream>
#include <exception>

int main()
{
    
    try
    {
        throw 505;
    }
    catch (int& e)
    {
        std::cout << "Error " << e << "!\n" << std::endl;
    }
    catch (...)
    {
        std::cout << "Here!\n";
    }
    
    
}