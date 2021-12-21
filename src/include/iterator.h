#ifndef _ITERATOR_H
#define _ITERATOR_H



#include <utility>
#include <iterator>
#include "bst.h"

template <typename pT, typename nT>
class _Iterator{

    private:
    nT* current;

    public:

    // Constructors
    _Iterator() noexcept = default;
    
    explicit _Iterator(nT* p) noexcept: current{p}{}

    ~_Iterator() = default;
    
    using value_type = pT;
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

    _Iterator& operator++() {
        auto tmp = current;
        
        if(tmp->r_next){
            tmp = tmp->r_next.get();
            while(tmp->l_next){tmp = tmp->l_next.get();}
            current = tmp;               
        }
        else{
            while(tmp->parent && tmp->parent->l_next.get() != tmp)
                {tmp = tmp->parent;}
            current = tmp->parent; 
        }
        return *this;
    }

    _Iterator operator++(int ){
        auto tmp = this;
        ++this;
        return *tmp;
        }

    // ==
    friend
    bool operator ==(const _Iterator& a, const _Iterator& b){return a.current == b.current;}
    
    // !=
    friend
    bool operator !=(const _Iterator& a, const _Iterator& b){return !(a == b);}

};

#endif

