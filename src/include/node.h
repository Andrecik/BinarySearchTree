#ifndef NODE_H
#define NODE_H 


#include <iostream>
#include <memory>
#include <utility>


template <typename kT, typename vT, typename OP>
template <typename kO, typename vO>
struct Bst<kT,vT,OP>::Node{
    
    std::pair<const kO, vO> element;//riflettere su se dobbiamo mantere costante il valore della key: aggiungere "const kO"
    std::unique_ptr<Node> parent ;
    std::unique_ptr<Node> r_next ; 
    std::unique_ptr<Node> l_next ; 

// Constructors
    Node() = default; // vT{}
    explicit Node(std::pair<const kO, vO>& x):element{x}  {};
    Node(std::pair<const kO, vO>& x, Node* previous):element{x} {
        parent.reset(previous); ///vedi se va bene
    };
    
// Destructors
    ~Node()=default;


};


#endif