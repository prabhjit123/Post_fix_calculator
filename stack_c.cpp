#include <iostream>
#include <stdexcept>
#include "stack_c.h"
#include "list.h"
using namespace std;

Stack_C::Stack_C()
    {
        try{
            stk = new List();
        }
        catch(const std::bad_alloc& e)
            {
                std::cerr << "Out of Memory" << e.what() << std::endl;
            };
    };
Stack_C::~Stack_C()
    {
        delete stk;
    };
void Stack_C::push(int data)
    {
        stk->insert(data);
    };
int Stack_C::pop()
    {
        if (stk->get_size()==0)
        {
            throw std::runtime_error("Empty Stack");
        }
        else
        {
            return stk->delete_tail();
        };
    };
int Stack_C::get_element_from_top(int idx)
    {   
        if(idx >= stk->get_size() || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else
        {
            int size = stk->get_size();
            Node * ptr = stk->get_head();
            for (int i = 0; i<=(size-idx-1); i++)
            {
                ptr = ptr->next;
            };
            return ptr->get_value();
        };
    return 1;
    }
int Stack_C::get_element_from_bottom(int idx)
    {
        if(idx >= stk->get_size() || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else
        {
            int size = stk->get_size();
            Node * ptr = stk->get_head();
            for (int i = 0; i<=idx; i++)
            {
                ptr = ptr->next;
            }
            return ptr->get_value();
        };
    return 1;
    };
void Stack_C::print_stack(bool top_or_bottom)
    {
        if (top_or_bottom==1)
        {
            Node * ptr = stk->get_head()->next;
            for(int i = 0; i<stk->get_size(); i++)
            {
                ptr = ptr->next;
            };
            for(int i = stk->get_size(); i>0; i--)
            {
                cout << ptr->prev->get_value() << endl;
                ptr = ptr->prev;
            };
        }
        else
        {
            Node * ptr = stk->get_head();
            for(int i = 0; i<stk->get_size(); i++)
            {
                ptr = ptr->next;
                cout << ptr->get_value() << endl;
            }
        }
    };
int Stack_C::add()
    {   Node * ptr = stk->get_head()->next;
            for(int i = 0; i<stk->get_size(); i++)
            {
                ptr = ptr->next;
            };
        if (stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
            int adds = ptr->prev->get_value() + ptr->prev->prev->get_value();
            pop();
            pop();
            push(adds);
            return adds;
        };
    };
int Stack_C::subtract()
    {   Node * ptr = stk->get_head()->next;
            for(int i = 0; i<stk->get_size(); i++)
            {
                ptr = ptr->next;
            };
        if (stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
            int subs = ptr->prev->prev->get_value() - ptr->prev->get_value();
            pop();
            pop();
            push(subs);
            return subs;
        };
    };
int Stack_C::multiply()
    {
        Node * ptr = stk->get_head()->next;
            for(int i = 0; i<stk->get_size(); i++)
            {
                ptr = ptr->next;
            };
        if (stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
            int multiplication = ptr->prev->get_value() * ptr->prev->prev->get_value();
            pop();
            pop();
            push(multiplication);
            return multiplication;
        };
    };
int Stack_C::divide()
    {   Node * ptr = stk->get_head()->next;
            for(int i = 0; i<stk->get_size(); i++)
            {
                ptr = ptr->next;
            };
        if (stk->get_size()<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else if (ptr->prev->get_value()==0)
        {
            pop();
            pop();
            throw std::runtime_error("Division by Zero Error");
        }
        else
        {
            float div = float(ptr->prev->prev->get_value()) / float(ptr->prev->get_value());
            if (div<0 && ptr->prev->prev->get_value() % ptr->prev->get_value()!=0)
        {
            pop();
            pop();
            push(div-1);
            return div-1;
        }
        else
        {   pop();
            pop();
            push(div);
            return div;
        };
        };
    };
List* Stack_C::get_stack()
    {
        return stk;
    }; // Get a pointer to the linked list representing the stack
int Stack_C::get_size()
    {
        return stk->get_size();
    }; // Get the size of the stack
