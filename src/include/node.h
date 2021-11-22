#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <memory>



template <typename kT, typename vT>
class Node{
private:    
    std::pair<kT key, vT value>;
    std::unique_ptr<Node> r_next; //uniquepointer
    std::unique_ptr<Node> l_next; //uniquepointer

public:
// Constructors
    Node()=default;

// Destructors
    ~Node()=default;

};


#endif