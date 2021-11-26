#ifndef BST_H
#define BST_H 

#include "node.h"
#include "iterator.h" 
#include <utility> 
// controllare se serve includere <memory>

enum class direction{stop , left, right};

template <typename kT,typename vT,typename OP = std::less<kT>>
class Bst {

    private:

    template <class kO, class vO>
    class Node;
    
    OP op;
    std::unique_ptr<Node> root;


    public:
    using pair_type=std::pair<kT, vT>

    // ***** CTORS/DTORS ******


    // ***** COPY SEMANTICS *****


    // ***** MOVE SEMANTICS *****

    // ***** USEFYULL METHODS *****



    // ***** ITERATOR CLASS *****

    template <class kOT, class vOT>
    class __Iterator;

    using iterator = __Iterator<std::pair<kOT,vOT>>;
    using const_iterator = __Iterator<const  std::pair<kOT,vOT>>;
    
    template <typename kO, typename vO>
    direction compare(Node<kO,vO>& a, Node<kO,vO>& b, OP& op);

    template <class kO, class vO>
    iterator next(Node<kO,vO>* current, direction& d);

    iterator begin() {
        
        if(hasnext(OP))
        next;
        else return iterator
        }

    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;

    const_iterator cend() const;



    vT& operator[](const kT& x);  
    vT& operator[](kT&& x);       // riflettere su const[]
                                  // se non c'è il value
                                  // ritorna vT{} ovvero il
                                  // default value



    // ***** METHODS *****
    //template <class kOT, class vOT>
    std::pair<iterator,bool> insert(const pair_type& x);
    template <class kOT, class vOT>
    std::pair<iterator,bool> insert(pair_type&& x);

    template <class... Types>
    std::pair<iterator,bool> emplace(Types&&... args);

    void clear(); // vedere shared pointers

    iterator find(const kT& x);
    const_iterator find(const kT& x) const;

    void balance();

    void erase(const kT& x);



    // ***** OPERATOR << *****

    friend
    std::ostream& operator<<(std::ostream& os, const Bst& x);
    

};

/// friend std::ostream operator<<(const std::ostream os, const Bst<T,> tree)

#endif
