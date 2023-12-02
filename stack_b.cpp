#include "stack_b.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Stack_B::Stack_B()
{
    size = 0;
    capacity = 1024;
    try {
        stk = new int[capacity];
    }
    catch(const std::bad_alloc& e)
            {
                std::cerr << "Out of Memory" << e.what() << std::endl;
            };
}
Stack_B::~Stack_B()
    {
        delete[] stk;
    };

void Stack_B::push(int data)
    {
        if (size==0){
            size=1;
            stk[0]=data;
        }
        else if(size == capacity)
        {
            try{
                int * copied_array = new int[capacity*2];
                for (int i = 0; i < size; i++)
            {
                copied_array[i] = stk[i];
            }
            delete[] stk;
            stk = copied_array;
            stk[size] = data;
            capacity = capacity*2;
            size++;
            }
            catch(const std::bad_alloc& e)
            {
                std::cerr << "Out of Memory" << e.what() << std::endl;
            };
            
            }
        else
        {
            stk[size] = data;
            size++;
        };
    };
    int Stack_B::pop()
    {
        if(size==0)
        {
            throw std::runtime_error("Empty Stack");
        }
        else if(size==1)
        {
            size=0;
            return stk[0];
        }
        else if(size <= capacity/4)
        {
            try{
                int * copied_array = new int[capacity/4];
            for (int i = 0; i < size; i++)
            {
                copied_array[i] = stk[i];
            }
            delete[] stk;
            stk = copied_array;
            int temp = stk[size-1];
            size--;
            capacity = capacity/4;
            return temp;}
            catch(const std::bad_alloc& e)
            {
                std::cerr << "Out of Memory" << e.what() << std::endl;
            };
        }
        else
        {
            int temp = stk[size-1];
            size--;
            return temp;
        };
        return 1;
    };
    int Stack_B::get_element_from_top(int idx)
    {
        if (idx >size-1 || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else 
        {
            return stk[size-idx-1];
        };
        return 1;
    };
    int Stack_B::get_element_from_bottom(int idx)
    {
        if (idx >size-1 || idx<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else 
        {
            return stk[idx];
        };
        return 1;
    };
    void Stack_B::print_stack(bool top_or_bottom)
    {
        if (size==0)
        {
            return;
        }
        if (top_or_bottom == 1)
        {
            for (int i=size-1; i>=0; i--)
            {
                cout << stk[i] << endl;
            };
        }
        else
        {
            for (int i=0; i<size; i++)
            {
                cout << stk[i] << endl;
            };
        };
    };
    int Stack_B::add()
    {
        if (size<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
        int addition = stk[size-1] + stk[size-2];
        pop();
        pop();
        push(addition);
        return addition;
        };
    return 1;
    };
    int Stack_B::subtract()
    {
        if (size<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
        int subtraction = stk[size-2] - stk[size-1];
        pop();
        pop();
        push(subtraction);
        return subtraction;
        };
    return 1;
    };
    int Stack_B::multiply()
    {   
        if (size<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
        int multiplication = stk[size-1] * stk[size-2];
        pop();
        pop();
        push(multiplication);
        return multiplication;
        };
    return 1;
    };
    int Stack_B::divide()
    {
        if (size<2)
        {
            throw std::runtime_error("Not Enough Arguments");
        }
        else
        {
        if (stk[size-1]==0)
        {
            pop();
            pop();
            throw std::runtime_error("Divide by Zero Error");
        }
        else
        {
        float division = float(stk[size-2]) / float(stk[size-1]);
        if (division<0 && stk[size-2]%stk[size-1]!=0)
        {
            pop();
            pop();
            push(division-1);
            return division-1;
        }
        else
        {
            pop();
            pop();
            push(division);
            return division;
        };
        };
        };
    return 1;
    };
    int* Stack_B::get_stack()
    {
        int * ptr = stk;
        return ptr;
    };
    int Stack_B::get_size()
    {
        return size;
    };
