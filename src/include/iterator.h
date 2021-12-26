#ifndef _ITERATOR_H
#define _ITERATOR_H



#include <utility>
#include <iterator>


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

    // ++  (Pre increment)
    _Iterator& operator++() noexcept {
        auto tmp = current;
        
        if(tmp->r_next){
            tmp = tmp->r_next.get();
            #ifdef DEBUG
            std::cout << "moving right to node with key: " << tmp->element.first << std::endl;
            #endif
            while(tmp->l_next){
                tmp = tmp->l_next.get();
                #ifdef DEBUG
                std::cout << "moving left to node with key: " << tmp->element.first << std::endl;
                #endif
            }
            current = tmp;               
        }
        else{
            while(tmp->parent && tmp->parent->l_next.get() != tmp){
                tmp = tmp->parent;
                #ifdef DEBUG
                std::cout << "moving parent to node with key: " << tmp->element.first << std::endl;
                #endif
            }
            current = tmp->parent; 
        }
        return *this;
    }

    // ++  (Post increment)
    _Iterator operator++(int ) noexcept {
        auto tmp = this;
        ++(*this);
        return *tmp;
        }

    // ==
    friend
    bool operator ==(const _Iterator& a, const _Iterator& b) noexcept {return a.current == b.current;}
    
    // !=
    friend
    bool operator !=(const _Iterator& a, const _Iterator& b) noexcept {return !(a == b);}

};

#endif

