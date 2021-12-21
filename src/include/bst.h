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

template<typename pT, typename nT>
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
    
    
    //direction compare(F&& a, const kT&  b, OP& op);

//***** COMPARE *****
template <typename F>
direction compare(F&& a, const kT&  b, OP& op){///bisogna vedere come accedere ad attributo di attributo
    if(op(std::forward<F>(a), b)){
        return direction::left;
    }
    else if(!op(std::forward<F>(a), b)){
        return direction::right;
    }
    else{
        return direction::stop;
    }
}

    //node* move_on(node* it, direction& d);

node* move_on(node* it, direction& d){
    switch (d)
    {
    case direction::left:
        it = it->l_next.get();
        std::cout<< " I'm moving left" << std::endl;
        break;
    case direction::right:
        it = it->r_next.get();
        std::cout<< " I'm moving right" << std::endl;
        break;
    default:
        std::cout<< " freeze, don't move " << std::endl;
        break;
    }
    return it;
}


    template <typename F>
    std::pair<node*,direction> compare_and_move(F&& k)//;


    {
    auto tmp = root.get();
    node* tmp_previous_node;
    direction d;
    direction d_previous_node;
    while(tmp || d != direction::stop)
    {
        tmp_previous_node = tmp;
        d_previous_node = d;
        d = compare(std::forward<F>(k),tmp->element.first,op);
        tmp = move_on(tmp,d);
    }
    return std::make_pair(tmp_previous_node,d_previous_node);
}

    // template <typename F>
    // std::pair<node*,bool> _insert(F&& x); 

    void balancing(std::vector<pair_type>& b, typename std::vector<pair_type>::iterator& begin, typename std::vector<pair_type>::iterator& end);


    public:

    // ***** CTORS/DTORS ******

    Bst() noexcept = default;
    ~Bst() = default; 

    explicit Bst(const OP& x): op{std::move(x)} {};

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
        // auto tmp = root.get();
        // while(tmp->r_next){tmp = tmp->r_next.get();}
        // return iterator{tmp};
        return iterator{nullptr};
    }
    const_iterator end() const{ return const_iterator{this->end()};}
    const_iterator cend() const{ return const_iterator{this->end()};}



    // ***** METHODS *****
    
    // std::pair<iterator,bool> insert(const pair_type& x){
    //     auto result = _insert(x);
    //     return std::make_pair(iterator{result.first},result.second);
    // }
    // std::pair<iterator,bool> insert(pair_type&& x){
    //     auto result = _insert(std::move(x));
    //     return std::make_pair(iterator{result.first},result.second);
    // }
//################################################################################################################################################################
std::pair<iterator,bool> insert(const pair_type& x){    
    if(!root)
    {
        root.reset(new node(x));

        return std::make_pair(iterator{root.get()}, true);
    }

    auto previous_node_info = compare_and_move(x.first);


    switch (previous_node_info.second)
            {
        case direction::stop:
            //insertion.first = std::move(previous_node_info.first); // voglio fare una copia del puntatore questa cosa è corretta?
            //insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
            return std::make_pair(iterator{previous_node_info.first},false);
            break;
        case direction::left:
            previous_node_info.first->l_next.reset(new node(x, previous_node_info.first));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
            //insertion.first = std::move(previous_node_info.first);
            return std::make_pair(iterator{previous_node_info.first},true);
            break;
        case direction::right:
            previous_node_info.first->r_next.reset(new node(x, previous_node_info.first));//vedere new template come va utilizzato??????????
            //insertion.first = std::move(previous_node_info.first);
            return std::make_pair(iterator{previous_node_info.first},true);
            break;
        default:
        
            break;
            } 
    /////IMPLEMENTA LA SCRITTURA DEL NODO
    return std::make_pair(iterator{previous_node_info.first},false); 
}


std::pair<iterator,bool> insert(pair_type&& x){  
    if(!root)
    {
        root.reset(new node(std::move(x)));

        return std::make_pair(iterator{root.get()}, true);
    }

    auto previous_node_info = compare_and_move(std::move(x).first);


    switch (previous_node_info.second)
            {
        case direction::stop:
            //insertion.first = std::move(previous_node_info.first); // voglio fare una copia del puntatore questa cosa è corretta?
            //insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
            return std::make_pair(iterator{previous_node_info.first},false);
            break;
        case direction::left:
            previous_node_info.first->l_next.reset(new node(std::move(x), previous_node_info.first));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
            //insertion.first = std::move(previous_node_info.first);
            return std::make_pair(iterator{previous_node_info.first},true);
            break;
        case direction::right:
            previous_node_info.first->r_next.reset(new node(std::move(x), previous_node_info.first));//vedere new template come va utilizzato??????????
            //insertion.first = std::move(previous_node_info.first);
            return std::make_pair(iterator{previous_node_info.first},true);
            break;
        default:
        
            break;
            } 
    /////IMPLEMENTA LA SCRITTURA DEL NODO
    return std::make_pair(iterator{previous_node_info.first},false); 
}

//################################################################################################################################################################
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
        if(!x.root){
            os<<"The tree is empty"<<'\n';
            return os;}
        for (const auto& i : x) {os<< "key  " << i.first << " value " << i.second << '\n';}
            os<<"L'albero esiste"<<'\n';
        return os;
    }

    void tryfor(){
        for(auto i : *this){std::cout<< "bb \n";}
    }

};

/// friend std::ostream operator<<(const std::ostream os, const Bst<T,> tree)

#endif
