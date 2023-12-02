#include <iostream>
#include "list.h"
#include "node.h"
List::List()
    {
        size = 0;
        sentinel_head =  new Node(true);
        sentinel_tail =  new Node(true);
        sentinel_tail->prev = sentinel_head;
        sentinel_head->next = sentinel_tail;
    };
List::~List()
    {
        delete sentinel_head;
        delete sentinel_tail;
    };

    // Insert an element at the tail of the linked list 
void List::insert(int v)
    {
        Node * new_node = new Node(v,nullptr,nullptr);
        if (size==0)
        {
        new_node->next = sentinel_tail;
        new_node->prev = sentinel_head;
        sentinel_tail->prev = new_node;
        sentinel_head->next = new_node;
        size++;
        }
        else
        {
            new_node->next = sentinel_tail;
            new_node->prev = sentinel_tail->prev;
            sentinel_tail->prev->next = new_node;
            sentinel_tail->prev = new_node;
            size++;
        };
    };
    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
int List::delete_tail()
    {   
        int temp = sentinel_tail->prev->get_value();
        sentinel_tail->prev->prev->next = sentinel_tail;
        sentinel_tail->prev = sentinel_tail->prev->prev;
        size--;
        return temp;
    };

    // Return the size of the linked list 
    // Do not count the sentinel elements
int List::get_size()
    {
        return size;
    };

    // Return a pointer to the sentinel head of the linked list 
Node* List::get_head()
    {
        return sentinel_head;
    };
