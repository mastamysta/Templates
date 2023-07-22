#include <iostream>
#include <thread>

#define DATA_ITEM_INVALID   -1

#define MAX_DATA_ITEMS      20

// the idea here is to have multiple data stores, each data store may have a reference to each data item. I want to use smart pointers to free data items automatically when all the data stores are done with them.

class data_item
{
    
    private:
        
        int data;
    
    public:
    
        data_item()
        {
            std::cout << "Executing default data item constructor\n";
            data = DATA_ITEM_INVALID;
        }
        
        data_item(data_item& item)
        {
            std::cout << "Executing copy constructor\n";
            data = item.data;
        }
    
        data_item(int val)
        {
            data = val;
            std::cout << "Executing data item constructor " << data << "\n";
        }
        
        ~data_item()
        {
            std::cout << "Executing data item destructor " << data << "\n";
        }
        
    friend class data_store;
};

class data_store
{
    private:
    
        static const int starting_data_array_size = 1;
    
        int id;
        
        std::shared_ptr<data_item>* data_array;
        int data_array_size;
    
    public:
        
        data_store(int ident)
        {
            id = ident;
            std::cout << "Executing data store constructor " << id << "\n";
            
            data_array_size = starting_data_array_size;
            data_array = new std::shared_ptr<data_item>[data_array_size];
        }
        
        ~data_store()
        {
            std::cout << "Executing data store destructor " << id << "\n";
        }
    
        void add_data(std::shared_ptr<data_item> item)
        {
            for (int i = 0; i < data_array_size; i ++)
            {
                if (!data_array[i])
                {
                    std::cout << "Found free index " << i << " inserting into data store\n";
                    data_array[i] = item;
                    return;
                }
            }
            
            std::cout << "Data store " << id << " is full, expanding data array\n";
            int old_array_size = data_array_size;
            data_array_size *= 2;
            std::shared_ptr<data_item>* expanded_array = new std::shared_ptr<data_item>[data_array_size];
            
            // need to do it this way (not using memcpy) because we must invoke the copy constructor of each shared_ptr so that ref counts are incremented. Otherwise some objects disappear.
            for (int i = 0; i < old_array_size; i++)
                expanded_array[i] = data_array[i];
            
            delete[] data_array;
            data_array = expanded_array;
            
            std::cout << "Inserting into index " << old_array_size << " after expansion\n";
            data_array[old_array_size] = item;
        }
        
        void clear_array()
        {
            std::cout << "Clearing data from data store\n";
            
            for (int i = 0; i < data_array_size; i ++)
            {
                data_array[i] = NULL;
            }
        }
};


void thread_func(data_store& ds, std::shared_ptr<data_item> data_array[], int start_index, int step)
{
    std::cout << "Started thread: " << std::this_thread::get_id() << "\n";
    
    for (int i = start_index; i < MAX_DATA_ITEMS; i+=step)
    {
        std::cout << "Thread " << std::this_thread::get_id() << " is inputting data item " << i << "\n"; 
        ds.add_data(data_array[i]);
    }
    
    std::cout << "Terminating thread: " << std::this_thread::get_id() << "\n";
    
}

int main()
{
    
    data_store ds0(0);
    data_store ds1(1);
    
    
    {
        std::shared_ptr<data_item> data_array[MAX_DATA_ITEMS];
        
        for (int i = 0; i < MAX_DATA_ITEMS; i++)
        {
            data_array[i] = std::make_shared<data_item>(i);
        }
        
        // must explitly use std::ref otherwise compiler passes by value and you get multiple calls to destructor!
        std::thread t0(thread_func, std::ref(ds0), data_array, 0, 3);
        //std::thread t1(thread_func, std::ref(ds1), data_array, 1, 4);
        
        t0.join();
        //t1.join();
        
        ds1.clear_array();
        
        
        //std::thread t2(thread_func, std::ref(ds1), data_array, 2, 7);
        
        //t2.join();
    }
    
    
    
    
    std::cout << "Exiting\n";
}