#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

#include <iterator>

template <typename kT,typename vT,typename OP>
template <class kOT, class vOT>
class Bst<kT,vT,OP>::__Iterator{

    private:
    using node = typename Bst<kT,vT,OP>::Node;
    node* current;

    public:

    // Constructor to implement

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

    // ==

    // !=

};

#endif
