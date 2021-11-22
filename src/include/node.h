#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <memory>
#include <utility>


template <typename kT, typename vT>
class Node{
private:    
    std::pair<kT, vT> element;//riflettere su se dobbiamo mantere costante il valore della key: aggiungere "const kT"
    std::unique_ptr<Node> r_next; //uniquepointer
    std::unique_ptr<Node> l_next; //uniquepointer

public:
// Constructors
    Node()=default;

// Destructors
    ~Node()=default;

};


#endif