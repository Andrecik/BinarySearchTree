#ifndef BST_H
#define BST_H 

#include<iostream>
#include <utility>
#include <memory>
#include <vector>
// controllare se serve includere <memory>

enum class direction{stop, left, right};

// namespace Bst_features
// {
template <typename pT>
struct Node;

template <typename pT, typename nT>
class _Iterator;

// }
// using namespace Bst_features;

template <typename kT,typename vT,typename OP = std::less<kT>>
class Bst {

    private:

    
    using pair_type = std::pair<const kT,vT>;
    using node = Node<pair_type>;
    using iterator = _Iterator<pair_type, node>;
    using const_iterator = _Iterator<const pair_type, node>;

    OP op;
    std::unique_ptr<node> root;


    // ***** USEFYULL METHODS *****
    
    template <typename F>
    direction compare(F&& a, const kT&  b, OP& op);

    node*  next(const node* it);

    node* move_on(node* it, direction& d);

    template <typename F>
    std::pair<node*,direction> compare_and_move(F&& k);

    template <typename F>
    std::pair<node*,bool> _insert(F&& x); 

    void balancing(std::vector<pair_type>& b, typename std::vector<pair_type>::iterator& begin, typename std::vector<pair_type>::iterator& end);


    public:

    

    // ***** CTORS/DTORS ******

    Bst() noexcept = default;
    ~Bst() = default; 

    explicit Bst(const OP& x) op{std::move(x)} {};

    // ***** MOVE SEMANTICS *****

    Bst(Bst<kT,vT,OP>&& x) noexcept = default;
    Bst<kT,vT,OP>& operator=(Bst<kT,vT,OP>&& x) noexcept = default;

    // ***** COPY SEMANTICS *****

    Bst(const Bst<kT,vT,OP>& x){
        
        std::copy(x.begin(),x.end(),this->begin());
    }

    Bst<kT,vT,OP>& operator=(const Bst<kT,vT,OP>& x){
        root.reset();
        Bst<kT,vT,OP> tmp{x};
        return std::move(tmp);
    }


    iterator begin() noexcept {
        auto tmp = root.get();
        while(tmp->l_next){tmp = tmp->l_next.get();}
        return iterator{tmp};
    }
    const_iterator begin() const{return const_iterator{this->begin()};}
    const_iterator cbegin() const{return const_iterator{this->begin()};}
    
    iterator end() noexcept {
        auto tmp = root.get();
        while(tmp->r_next){tmp = tmp->r_next.get();}
        return iterator{tmp};
    }
    const_iterator end() const{ return const_iterator{this->end()};}
    const_iterator cend() const{ return const_iterator{this->end()};}



    // ***** METHODS *****
    
    std::pair<iterator,bool> insert(const pair_type& x){
        auto result = _insert(x);
        return std::make_pair(iterator{result.first},result.second);
    }
    std::pair<iterator,bool> insert(pair_type&& x){
        auto result = _insert(std::move(x));
        return std::make_pair(iterator{result.first},result.second);
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
