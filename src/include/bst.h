#ifndef BST_H
#define BST_H 

#include "node.h"
#include "iterator.h" 
#include <utility> 
// controllare se serve includere <memory>

enum class direction{stop, left, right};

template <typename kT,typename vT,typename OP = std::less<kT>>

class Bst {

    private:

    template <typename kO, typename vO>
    struct Node;
    
    OP op;
    std::unique_ptr<Node> root;


    // ***** USEFYULL METHODS *****
    
    direction compare(const kT& a, const kT&  b, OP& op);

    iterator  next(iterator& it);

    iterator move_on(iterator& it, direction& d);

    std::pair<iterator,direction> compare_and_move(const kT& k);

    std::pair<iterator,bool>  _insert(pair_type& x);


    public:
    using pair_type = std::pair<kT, vT>

    // ***** CTORS/DTORS ******


    // ***** COPY SEMANTICS *****


    // ***** MOVE SEMANTICS *****


    // ***** ITERATOR CLASS *****
    template <typename kOT, typename vOT>
    class __Iterator;

    
    
    using iterator = __Iterator<kT,vT>;
    using const_iterator = __Iterator<kT,vT>;

    iterator begin() {
        auto tmp = root.get();
        while(tmp->l_next){tmp = tmp->l_next.get();}
        return iterator{tmp};
    }
    const_iterator begin() const{
        auto tmp = root.get();
        while(tmp->l_next){tmp = tmp->l_next.get();}
        return const_iterator{tmp};
    }
    const_iterator cbegin() const{
        auto tmp = root.get();
        while(tmp->l_next){tmp = tmp->l_next.get();}
        return const_iterator{tmp};
    }

    iterator end(){
        auto tmp = root.get();
        while(tmp->r-next){tmp = tmp->r-next.get();}
        return iterator{tmp};
    }
    const_iterator end() const{
        auto tmp = root.get();
        while(tmp->r-next){tmp = tmp->r-next.get();}
        return const_iterator{tmp};
    }
    const_iterator cend() const{
        auto tmp = root.get();
        while(tmp->r-next){tmp = tmp->r-next.get();}
        return const_iterator{tmp};
    }


    vT& operator[](const kT& x);  
    vT& operator[](kT&& x);       // riflettere su const[]
                                  // se non c'è il value
                                  // ritorna vT{} ovvero il
                                  // default value


    // ***** METHODS *****
    
    std::pair<iterator,bool> insert(const pair_type& x);
    
    std::pair<iterator,bool> insert(pair_type&& x);

    template <class... Types>
    std::pair<iterator,bool> emplace(Types&&... args);

    void clear();

    iterator find(const kT& x);
    const_iterator find(const kT& x) const;

    void balance();

    void erase(const kT& x);

        
    // ***** OPERATOR [] *****
    vT& operator[](const kT& x){
        auto  it = find(x);
        if(it!=this->end()){
            return *it.second;
        }
        else{
            auto p2 = insert(std::pair<vT, kT> p1{x,});
            return *(p2.first).second;
        }
    }


    vT& operator[](kT&& x){
        auto  it = find(std::move(x));
        if(it!=this->end()){
            return *it.second;// assicurarsi che quando il valore del nodo sia vuoto restituisca vuoto e non un valore random!!!!
        }
        else{
            auto p2 = insert(std::pair<vT, kT> p1{std::move(x),});
            return *(p2.first).second;
        }
    }


    // ***** OPERATOR << *****

    friend
    std::ostream& operator<<(std::ostream& os, const Bst& x){
        for (auto i : x) {std::cout<< "key  " << i.first << " value " << i.second << ' \n';}
        std::cout << std::endl;
    }

};

/// friend std::ostream operator<<(const std::ostream os, const Bst<T,> tree)

#endif
