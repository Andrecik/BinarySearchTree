#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <memory>



template <typename T>
class Node{
    std::pair<int k, T element>;
    Node* r_next; //uniquepointer
    Node* l_next; //uniquepointer
public:
// Constructors
    Node()=default;
template <typename O>  
    Node(O x);

template <typename O>  
    Node(O x, Node*);

template <typename O>  
    Node(O, Node*, Node*);
// Destructors
    ~Node()=default;

};


#endif