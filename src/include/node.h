#ifndef NODE_H
#define NODE_H 


#include <iostream>
#include <memory>
#include <utility>


template <typename kT, typename vT, typename OP>
template <typename kO, typename vO>
struct Bst<kT,vT,OP>::Node{
    
    std::pair<const kO, vO> element;//riflettere su se dobbiamo mantere costante il valore della key: aggiungere "const kO"
    std::unique_ptr<Node<kO,vO>> parent ;
    std::unique_ptr<Node<kO,vO>> r_next ; 
    std::unique_ptr<Node<kO,vO>> l_next ; 

// Constructors
    Node() = default; // vT{}
    explicit Node(const std::pair<const kO, vO>& x):element{x}  {};
    Node(const std::pair<const kO, vO>& x, const Node* previous ): element{x}, parent{previous} {};
    Node(std::pair<const kO, vO>&& x, const Node* previous ): element{std::move(x)}, parent{previous} {};
    
// Destructors
    ~Node()=default;


};


#endif