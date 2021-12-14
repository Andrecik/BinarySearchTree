#ifndef BST_H
#define BST_H 

#include<iostream>
#include <utility>
#include <memory>
#include <vector>
// controllare se serve includere <memory>

enum class direction{stop, left, right};

template <typename kT,typename vT,typename OP = std::less<kT>>
class Bst {

    private:

    template <typename kO, typename vO>
    struct Node;
    using node = Node<kT, vT>;


    OP op;
    std::unique_ptr<node> root;


    // ***** USEFYULL METHODS *****
    
    template <typename F>
    direction compare(F&& a, const kT&  b, OP& op);

    node* next(node* it);

    node* move_on(node* it, direction& d);

    template <typename F>
    std::pair<node*,direction> compare_and_move(F&& k);

    template <typename F>
    std::pair<node*,bool> _insert(F&& x); 

    void balancing(std::vector<pair_type>& b, typename std::vector<pair_type>::iterator& begin, typename std::vector<pair_type>::iterator& end);


    public:

    using pair_type = std::pair<kT, vT>;

    // ***** CTORS/DTORS ******

    Bst() noexcept = default;
    ~Bst() = default; 

    // ***** MOVE SEMANTICS *****

    Bst(Bst<kT,vT,OP>&& x) noexcept = default;
    Bst<kT,vT,OP> operator=(Bst<kT,vT,OP>&& x) noexcept = default;

    // ***** COPY SEMANTICS *****

    Bst(const Bst<kT,vT,OP>& x){
        
        std::copy(x.begin(),x.end(),this->begin());
    }

    Bst<kT,vT,OP> operator=(const Bst<kT,vT,OP>& x){

        Bst<kT,vT,OP> tmp{x};
        return std::move(tmp);
    }


    // ***** ITERATOR CLASS *****
    template <typename kOT, typename vOT>
    class __Iterator;

    
    
    using iterator = __Iterator<kT,vT>;
    using const_iterator = __Iterator<const kT, const vT>;

    iterator begin() noexcept {
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

    iterator end() noexcept {
        auto tmp = root.get();
        while(tmp->r_next){tmp = tmp->r_next.get();}
        return iterator{tmp};
    }
    const_iterator end() const{
        auto tmp = root.get();
        while(tmp->r_next){tmp = tmp->r_next.get();}
        return const_iterator{tmp};
    }
    const_iterator cend() const{
        auto tmp = root.get();
        while(tmp->r-next){tmp = tmp->r_next.get();}
        return const_iterator{tmp};
    }



    // ***** METHODS *****
    
    std::pair<iterator,bool> insert(const pair_type& x){
        auto result = _insert(x);
        return std::make_pair(iterator{result.first},result.second);
    }
    std::pair<iterator,bool> insert(pair_type&& x){
        auto result = _insert(std::move(x));
        return std::make_pair(iterator{std::move(result.first)},std::move(result.second));
    }

    template <class... Types>
    std::pair<iterator,bool> emplace(Types&&... args);

    void clear();

    iterator find(const kT& x);
    const_iterator find(const kT& x) const;

    void balance();

    void erase(const kT& x);

        
    // ***** OPERATOR [] *****
    vT& operator[](const kT& x){
        auto it = find(x);
        if(it!=this->end()){
            return *it.second;
        }
        else{
            std::pair<vT, kT> p1{x,};
            auto p2 = insert(p1);
            return *(p2.first).second;
        }
    }


    vT& operator[](kT&& x){
        auto it = find(std::move(x));
        if(it!=this->end()){
            return *it.second;// assicurarsi che quando il valore del nodo sia vuoto restituisca vuoto e non un valore random!!!!
        }
        else{
            std::pair<vT, kT> p1{std::move(x),};
            auto p2 = insert(p1);
            return *(p2.first).second;
        }
    }


    // ***** OPERATOR << *****

    friend
    std::ostream& operator<<(std::ostream& os, const Bst& x){
        for (auto i : x) {os<< "key  " << i.first << " value " << i.second << '\n';}
        return os;
    }

};

/// friend std::ostream operator<<(const std::ostream os, const Bst<T,> tree)

#endif
