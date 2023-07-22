#include <iostream>

using namespace std;

int main()
{
    cout << "hello, what's your name?\n";
    
    std::string my_name;
    
    cin >> my_name;
    
    cout << "Hi " << my_name << ", i'm Hal!\n";
}