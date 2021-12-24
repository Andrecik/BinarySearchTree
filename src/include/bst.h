#ifndef BST_H
#define BST_H 

#include<iostream>
#include <utility>
#include <memory>
#include <vector>
#include <iterator>
#include "node.h"
#include "iterator.h"

//##########################################################################################################################################
//Direction
//##########################################################################################################################################
enum class direction{stop, left, right};


//##########################################################################################################################################
//Node  and Iterator Declaration
//##########################################################################################################################################
template <typename pT>
struct Node;

template<typename pT, typename nT>
class _Iterator;


//##########################################################################################################################################
//Binary search tree
//##########################################################################################################################################
template <typename kT,typename vT,typename OP = std::less<kT>>
class Bst {

    private:

    
    using pair_type = std::pair<const kT,vT>;
    using node = Node<pair_type>;
    using iterator = _Iterator<pair_type, node>;
    using const_iterator = _Iterator<const pair_type, node>;

    OP op;
    std::unique_ptr<node> root;

//##########################################################################################################################################
// ***** USEFYULL METHODS *****
//##########################################################################################################################################

    
//***** COMPARE ***** 

    template <typename F>
    direction compare(F&& a, const kT&  b, OP& op);

//***** MOVE ON *****

    node* move_on(node* it, direction& d);

//***** COMPARE AND MOVE*****
    
    template <typename F>
    std::pair<node*,direction> compare_and_move(F&& k);

//***** INSERTINO *****

    template <typename F>
    std::pair<node*,bool> _insert(F&& x); 

// ***** BALANCING *****
    
    void balancing(std::vector<pair_type>& b, typename std::vector<pair_type>::iterator& begin, typename std::vector<pair_type>::iterator& end);

// ***** COPY TREE *****

    void copy_tree(node* x1, node* x2);

    public:
//##########################################################################################################################################
// ***** CTORS/DTORS ******
//##########################################################################################################################################

    Bst() noexcept = default;
    
    ~Bst() = default; 

    explicit Bst(const OP& x): op{std::move(x)} {};

// ***** MOVE SEMANTICS *****

    Bst(Bst&& x) noexcept = default;
    
    Bst& operator=(Bst&& x) noexcept = default;

// ***** COPY SEMANTICS *****

    Bst(const Bst& x): op{x.op}{
        std::cout<<"SONO NEL COPY COSTRUCTOR \n";
        if(x.root) {
            std::cout<<"L'ALBERO ESISTE \n";
            auto tmp_original_tree = x.root.get(); 
            // start inserting the root node
            root.reset(new node{tmp_original_tree->element,nullptr});
            std::cout<<"HO COSTRUITO IL PRIMO NODO \n";
            auto tmp_copy_tree = root.get();
            // loop through the tree to be copied a node at a time
            // go left and insert
            // if can't go left, go right and insert
            // if can't go right, go back untill it can go right and insert
            copy_tree(tmp_original_tree,tmp_copy_tree);

        }

    }

    Bst& operator=(const Bst& x){
        std::cout<<"SONO NEL COPY asssssainment \n";
        root.reset();
        auto tmp = x;
        return std::move(tmp);
    }

//##########################################################################################################################################
// ***** BEGIN/END******
//##########################################################################################################################################
    
    iterator begin() noexcept {
        //std::cout<<"SONO IN BEGIN \n";
        auto tmp = root.get();
        std::cout<< tmp<< "\n";
        while(tmp->l_next){tmp = tmp->l_next.get();}
        //std::cout<< tmp<< "\n";
        //std::cout<<"ESCO DA BEGIN \n";
        return iterator{tmp};
    }
    
    const_iterator begin() const{//return const_iterator{this->begin()};
        //std::cout<<"SONO IN BEGIN CONST\n";
        auto tmp = root.get();
        std::cout<< tmp<< "\n";
        while(tmp->l_next){tmp = tmp->l_next.get();}
        //std::cout<< tmp<< "\n";
        //std::cout<<"ESCO IN BEGIN \n";
        return const_iterator{tmp};}     
    
    const_iterator cbegin() const{//return const_iterator{this->begin()};}
        //std::cout<<"SONO IN BEGIN CONST CONST\n";
        auto tmp = root.get();
        while(tmp->l_next){tmp = tmp->l_next.get();}
        //std::cout<<"ESCO IN BEGIN \n"; 
        return const_iterator{tmp};}
    
    iterator end() noexcept {return iterator{nullptr};}
    
    const_iterator end() const{ return const_iterator{nullptr};}
    
    const_iterator cend() const{ return const_iterator{nullptr};}

//##########################################################################################################################################
// ***** METHODS *****
//##########################################################################################################################################

// ***** INSERT *****
    
    std::pair<iterator,bool> insert(const pair_type& x){
        std::cout<<"I'm inside insert left" << std::endl;
        auto result = _insert(x);
        return std::make_pair(iterator{result.first},result.second);
    }
    
    std::pair<iterator,bool> insert(pair_type&& x){
        std::cout<<"I'm inside insert right" << std::endl;
        auto result = _insert(std::move(x));
        return std::make_pair(iterator{result.first},result.second);
    }
// ***** EMPLACE *****

    template <class... Types>
    std::pair<iterator,bool> emplace(Types&&... args);

// ***** CLEAR *****

    void clear();

// ***** FIND *****

    iterator find(const kT& x);

    const_iterator find(const kT& x) const;

// ***** BALANCE *****

    void balance();

// ***** ERASE *****

    void erase(const kT& x);
        
// ***** OPERATOR [] *****
    
    vT& operator[](const kT& x){
        //auto it = find(x);
        //if(it!=this->end()){
        //    return (*it).second;
        //}
        //else{
            std::cout << "I'm inside Subscripting operator left" << std::endl;
            vT s{};
            //std::pair<vT, kT> p1{x,s};
            pair_type p1{x,s};
            auto p2 = insert(p1);
            return (*(p2.first)).second;
        //}
    }

    vT& operator[](kT&& x){
        //auto k = x;
        //auto it = find(k);
        //if(it!=this->end()){
        //    return (*it).second;// assicurarsi che quando il valore del nodo sia vuoto restituisca vuoto e non un valore random!!!!
        //}
        //else{
            std::cout << "I'm inside Subscripting operator right" << std::endl;
            vT s{};
            //std::pair<vT, kT> p1{std::move(x),s};
            pair_type p1{std::move(x),s};
            auto p2 = insert(std::move(p1));
            return (*(p2.first)).second;
        //}
    }

// ***** OPERATOR << *****

    friend
    std::ostream& operator<<(std::ostream& os, const Bst& x){
        if(!x.root){
            os <<"The tree is empty"<<'\n';
            return os;
        }
        for (const auto& i : x) {
            //os << "begin key value"<< (*x.begin()).first << "\n";
            os << "key  " << i.first << " value " << i.second << '\n';
        }
        os <<"The tree exist"<<'\n';
        return os;
    }

    void tryfor(){
        for(const auto& i : *this){std::cout<< i.second <<"\n";}
    }

};

/// friend std::ostream operator<<(const std::ostream os, const Bst<T,> tree)

#endif
