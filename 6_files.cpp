#include <iostream>
#include <fstream>

int main()
{
    
    std::ofstream my_out_stream("somefile.txt");
    
    my_out_stream << "Hello world!\n";
    
    my_out_stream.close();
    
    std::ifstream my_in_stream("somefile.txt");
    
    std::string my_string ;
    
    my_in_stream >> my_string;
    
    std::cout << my_string << std::endl;
    
}