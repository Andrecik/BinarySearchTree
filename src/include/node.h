#ifndef NODE_H
#define NODE_H 


#include <iostream>
#include <memory>
#include <utility>



template <typename pT>
struct Node{
    
    pT element;
    Node* parent ;
    std::unique_ptr<Node> r_next ;
    std::unique_ptr<Node> l_next ; 

// Constructors
    Node() = default;
    explicit Node(const pT& x):element{x}  {};
    Node(const pT& x,Node* previous ): element{x}, parent{previous} {};
    Node(pT&& x, Node* previous ): element{std::move(x)}, parent{previous} {};
    
// Destructors
    ~Node()=default;


};


#endif