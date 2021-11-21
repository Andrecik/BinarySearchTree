#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <vector>

template <typename T>
class Node{
    T element;
    Node* r_next;
    Node* l_next;
public:
// Constructors
    Node(){};
    
    Node(T);

    Node(T, Node*);

    Node(T, Node*, Node*);
// Destructors
    ~Node(){};

};


#endif