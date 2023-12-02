#include "node.h"
#include <iostream>
Node::Node(bool sentinel)
{
    is_sentinel = sentinel;
};
Node::Node(int v, Node*nxt, Node* prv)
    {
        value = v;
        next = nxt;
        prev = prv;
    };
bool Node::is_sentinel_node()
    {
        return is_sentinel;
    };

    // Return the value of a node
int Node::get_value()
    {
        return value;
    }
