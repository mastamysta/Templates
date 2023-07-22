#include <iostream>
#include <memory>

class rectangle
{
    private:
        int v1;
        int v2;
        int v3;
        int v4;
        
    public:
    
    rectangle()
    {
        std::cout << "Running rectangle constructor\n";
        
        v1 = 0;
        v2 = 0;
        v3 = 0;
        v4 = 0;
    }
    
    ~rectangle()
    {
        std::cout << "Running rectangle destructor\n";
    }
};

int main()
{
    
    // UNIQUE - can't be copied, basically moves some runtime errors to be compiler errors and makes code more readable
    
    std::cout << "\n\nSTARTING UNIQUE DEMO\nCreating unique pointer for rectangle\n";
    
    {
        std::unique_ptr<rectangle> rect = std::make_unique<rectangle>();
    }
    
    // this wont compile as unique_ptr (by design) doesn't have copy constructors
    //std::unique_ptr<rectangle> r2 = rect;
    
    // SHARED - each time you invoke the copy constructor, a reference counter is incremented. inverse each time destructor is called. delete is called on the heap-allocated object when the reference counter hits 0.
    
    // always use make_shared (rather than std::shared_ptr<rectangle> shared_rect(new rectangle())) for shared pointers because this compresses allocation of rectangle and allocation of shared_ptr control block into a single allocated, saving a bit of clock time.
    std::cout << "\n\nSTARTING SHARED DEMO\nCreating shared pointer for rectangle\n";
    
    {
        std::shared_ptr<rectangle> shared_rect = std::make_shared<rectangle>();
    
        std::cout << "Initialising second shared pointer using copy constructor\n";
    
        {
            std::shared_ptr<rectangle> shared_rect0 = shared_rect;
            std::cout << "Exiting scope of second shared pointer for rectangle\n";
        }
    
        std::cout << "Exiting scope of first shared pointer for rectangle\n";
    }
    
    std::cout << "Exited scope of first shared pointer for rectangle\n";
    
    // WEAK - when copy constructor for a weak pointer is invoked with a shared pointer as the argument, the reference counter on the shared pointer is not incremented. You can check whether a weak pointer points to a valid object which can be extremely handy... so basically I think they are for checking whether your shared pointer still exists. Has no make_weak method.
    
    std::cout << "\n\nSTARTING WEAK DEMO\nCreating weak pointer\n";
    
    std::weak_ptr<rectangle> weak_rect;
    
    {
        std::cout << "Initialising shared pointer\n";
        
        std::shared_ptr<rectangle> shared_rect = std::make_shared<rectangle>();
        
        std::cout << "Assigning shared pointer to weak pointer\n";
        
        weak_rect = shared_rect;
    
        std::cout << "Exiting scope of shared pointer\n";
    }
    
    std::cout << "Exited scope of first shared pointer for rectangle\n";
    
    if(weak_rect.expired())
        std::cout << "Weak pointer tells us rectangle has expired\n";
    else
        std::cout << "NOT REACHED SHOULD NOT HET HERE!!!!!\n";
}