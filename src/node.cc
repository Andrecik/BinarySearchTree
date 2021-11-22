#include "include/node.h"


template <typename T>
template <typename O>
Node<T>::Node(O x):  element{x}, r_next{nullptr}, l_next{nullptr} {} 

template <typename T>
template <typename O>
Node<T>::Node(O x, Node* right){
    element = x;
    r_next = right;
    l_next = nullptr; 
}

template <typename T>
template <typename O>
Node<T>::Node(O x, Node* right, Node* left){
    element = x;
    r_next = right;
    l_next = left; 
}
