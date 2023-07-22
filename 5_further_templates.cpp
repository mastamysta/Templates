#include <iostream>
#include <cstdlib>


// Here, I'll try to create a single class interface which can create a mixed-type linked list (where the data in each node can be of any data-type/class) and can print out the data by iterating over the list

class linked_node
{
        
    public:
    
        linked_node *next;
        
    
        linked_node()
        {
            std::cout << "Executing linked_node constructor\n";
            
            next = NULL;
        }  
        
        virtual void print_data()
        {
            throw std::exception("Should not be printing linked_node type!");
        } 
};

template <typename T>
class mixed_node: public linked_node
{
    private:
        
        T data;
    
    public:
    
        mixed_node(T node_data)
        {
            std::cout << "Executing mixed_node constructor\n";
            
            next = NULL;
            data = node_data;
        }  
        
        void print_data()
        {
            std::cout << data << "\n";
        }
        
};


class mixed_list
{
  
    private:

        linked_node *head;
        linked_node *tail;
  
    public:
    
        mixed_list()
        {
            std::cout << "Executing mixed_list constructor\n";
            
            head = NULL;
            tail = NULL;
        }

        void add_node(linked_node *node)
        {
        
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                (*tail).next = node;
                tail = node;
            }
        }
        
        void print_all()
        {
            linked_node *curr = head;
            
            while (curr != NULL)
            {
               (*curr).print_data();
               curr = (*curr).next;
            }    
        }
    
};

class oddly_shaped
{
    private:
    
        int value;
        std::string extra;
        
    public:
    
        oddly_shaped()
        {
            std::cout << "Executing oddly_shaped constructor\n";
            
            value = 18;
            extra = "bruh";
        }
        
    friend std::ostream& operator<<(std::ostream& os, oddly_shaped& data);
};

std::ostream& operator<<(std::ostream& os, oddly_shaped& data)
{
    os << data.extra;
    return os;
}


int main()
{

    mixed_list my_list;
        
    mixed_node<int> my_node(5);
    my_list.add_node(&my_node);
    
    mixed_node<std::string> my_node1("stuff");
    my_list.add_node(&my_node1);
    
    oddly_shaped my_odd_object;
    mixed_node<oddly_shaped> my_node2(my_odd_object);
    my_list.add_node(&my_node2);
    
    mixed_node<int> my_node3(41);
    my_list.add_node(&my_node3);
        
    
    my_list.print_all();
}