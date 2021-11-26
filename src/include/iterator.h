#ifndef __ITERATOR_H
#define __ITERATOR_H

#include "node.h"
#include <utility>
#include <iterator>

template <typename kT,typename vT,typename OP>
template <class kOT, class vOT>
class Bst<kT,vT,OP>::__Iterator{

    private:
    using node = typename Bst<kT,vT,OP>::Node<kOT, vOT>;
    node* current;

    public:

    // Constructor to implement
    __Iterator()=default;
    
    ~__Iterator()=default;
    
    using value_type = std::pair<kOT,vOT>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag; 
    using reference = value_type&;
    using pointer = value_type*;

    // *
    reference operator*() const noexcept {return current->element;}
    // ->
    pointer operator->() const noexcept {return &(*(*this));}

    // ++
    __Iterator operator++() {
        current = current-> next;
        return *this;
        }//definire next
    
    __Iterator& operator++(int ){
        auto temp = *this;
        current = current -> next;
        return temp;
        } //definire next

    // ==
    friend
    bool operator ==(const __Iterator& a, const __Iterator& b){return a.current == b.current;}
    
    // !=
    friend
    bool operator !=(const __Iterator& a, const __Iterator& b){return !(a == b);}

};

#endif

__Iterator x = &stocazzo;