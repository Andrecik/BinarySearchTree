#include "include/node.h"

template <typename T>
Node::Node(T x){
    element = x;
    r_next = nullptr;
    l_next = nullptr; 
} 

template <typename T>
Node::Node(T x, Node* right){
    element = x;
    r_next = right;
    l_next = nullptr; 
}

template <typename T>
Node::Node(T x, Node* right, Node* left){
    element = x;
    r_next = right;
    l_next = left; 
}
