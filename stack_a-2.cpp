#include "stack_a.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_A::Stack_A()
{
    size = 0;
}
void Stack_A::push(int data)
    {
        if(size==1024)
        {
            throw std::runtime_error("Stack Full");
        }
        else
        {
            stk[size] = data;
            size++;
        };
    };
int Stack_A::pop()
    {
        if(size==0)
        {
            throw std::runtime_error("Empty Stack");
        }
        else
        {
            int temp = stk[size-1];
            stk[size-1]=0;
            size--;
            return temp;
        }
    return 0; //Returning 0
    };
int Stack_A::get_element_from_top(int idx)
    {   if(size-idx-1>=size || size-idx-1<0)
        {
            throw std::runtime_error("Index out of range");
        }
        else
        {
        return stk[size-idx-1];
        };
    };
int Stack_A::get_element_from_bottom(int idx)
    {
        if(idx>=size || idx < 0)
        {
            throw std::runtime_error("Index out of range");
        }
        else
        {
        return stk[idx];
        };
    };
void Stack_A::print_stack(bool top_or_bottom)
    {
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
int Stack_A::add()
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
int Stack_A::subtract()
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
int Stack_A::multiply()
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
int Stack_A::divide()
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
            throw std::runtime_error("Division by zero error");
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
int* Stack_A::get_stack()
    {
        int * ptr = stk;
        return ptr;
    };
int Stack_A::get_size()
    {
        return size;
    };
