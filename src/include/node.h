#ifndef NODE_H
#define NODE_H 


#include <iostream>
#include <memory>
#include <utility>



template <typename O>
struct Node{
    
    O element;//riflettere su se dobbiamo mantere costante il valore della key: aggiungere "const kO"
    Node* parent ;
    std::unique_ptr<Node> r_next ;
    std::unique_ptr<Node> l_next ; 

// Constructors
    Node() = default; // vT{}
    explicit Node(const O& x):element{x}  {};
    Node(const O& x,const Node* previous ): element{x}, parent{previous} {};
    Node(O&& x, const Node* previous ): element{std::move(x)}, parent{previous} {};
    
// Destructors
    ~Node()=default;


};


#endif