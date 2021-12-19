#ifndef __ITERATOR_H
#define __ITERATOR_H



#include <utility>
#include <iterator>

template <typename kT,typename vT,typename OP>
template <typename kOT, typename vOT>
class Bst<kT,vT,OP>::__Iterator{

    private:

    node* current;

    public:

    // Constructors
    __Iterator() noexcept = default;
    
    explicit __Iterator(node* p) noexcept: current{p}{}

    ~__Iterator() = default;
    
    using value_type = std::pair<kOT, vOT>;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag; 
    using reference = value_type&;
    using pointer = value_type*;

    // Operators

    // *
    reference operator*() const noexcept {return current->element;}
    // ->
    pointer operator->() const noexcept {return &(*(*this));}

    // ++
    __Iterator& operator++() {
        current = next(current);
        return *this;
        }
    
    __Iterator operator++(int ){
        auto tmp = *this;
        current = next(current);
        return tmp;
        }

    // ==
    friend
    bool operator ==(const __Iterator& a, const __Iterator& b){return a.current == b.current;}
    
    // !=
    friend
    bool operator !=(const __Iterator& a, const __Iterator& b){return !(a == b);}

};

#endif

