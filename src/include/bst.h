#ifndef BST_H
#define BST_H 

#include<iostream>
#include <utility>
#include <memory>
#include <vector>
#include <iterator>
// controllare se serve includere <memory>
//##########################################################################################################################################
//Direction
//##########################################################################################################################################
enum class direction{stop, left, right};

// namespace Bst_features
// {
//##########################################################################################################################################
//Node  and Iterator Declaration
//##########################################################################################################################################
template <typename pT>
struct Node;

template<typename pT, typename nT>
class _Iterator;


// }
// using namespace Bst_features;
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

    
    
    //direction compare(F&& a, const kT&  b, OP& op);

//***** COMPARE *****
template <typename F>
    direction compare(F&& a, const kT&  b, OP& op){///bisogna vedere come accedere ad attributo di attributo
        std::cout<<"SONO IN COMPARE \n";
        std::cout<<"k "<< a << "element "<< b << "\n";
        if(op(std::forward<F>(a), b)){
            std::cout<<"ESCO DA COMPARE LEFT \n";
            return direction::left;
        }
        else if(op(b,std::forward<F>(a))){
            std::cout<<"ESCO DA COMPARE RIGHT \n";
            return direction::right;
        }
        else{
            std::cout<<"ESCO DA COMPARE STOP \n";
            return direction::stop;
        }
    }


//***** MOVE ON *****
    //node* move_on(node* it, direction& d);

    node* move_on(node* it, direction& d){
        std::cout<<"SONO IN MOVE ON \n";
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
        std::cout<<"ESCO DA MOVE ON \n";
        return it;
    }

//***** COMPARE AND MOVE*****
    template <typename F>
    std::pair<node*,direction> compare_and_move(F&& k)//;
    {std::cout<<"SONO IN COMPARE AND MOVE \n";
    std::cout<<"questo è root"<< root.get()<< " \n";
    auto tmp = root.get();
    std::cout<< tmp->element.first << "\n";
    node* tmp_previous_node;
    direction d;
    //direction d_previous_node;
    while(tmp && d != direction::stop)
    {   std::cout<<"fino a quando d=stop o tm è nullptr "<< " " <<tmp <<" \n";
        tmp_previous_node = tmp;
        //d_previous_node = d;
        std::cout<<"k "<< k << " element "<<   "\n";
        d = compare(std::forward<F>(k),tmp->element.first,op);
        tmp = move_on(tmp,d);
    }
    std::cout<<"ESCO DA COMPARE AND MOVE \n";
    return std::make_pair(tmp_previous_node, d);
}
//***** INSERTINO *****
    template <typename F>
    std::pair<node*,bool>  _insert(F&& x){
        std::cout<<"SONO IN INSERTINO \n";
        if(!root)
        {
            root.reset(new node(std::forward<F>(x)));

            return std::make_pair(root.get(), true);
        }

        auto previous_node_info = compare_and_move(std::forward<F>(x).first);


        switch (previous_node_info.second)
                {
            case direction::stop:
                //insertion.first = std::move(previous_node_info.first); // voglio fare una copia del puntatore questa cosa è corretta?
                //insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
                std::cout<<"NODO GIÀ ESISTENTE \n";
                return std::make_pair(previous_node_info.first,false);
                break;
            case direction::left:
                previous_node_info.first->l_next.reset(new node(std::forward<F>(x), previous_node_info.first));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
                //insertion.first = std::move(previous_node_info.first);
                std::cout<<"NUOVO NODO CREATO A SINISTRA \n";
                return std::make_pair(previous_node_info.first,true);
                break;
            case direction::right:
                previous_node_info.first->r_next.reset(new node(std::forward<F>(x), previous_node_info.first));//vedere new template come va utilizzato??????????
                //insertion.first = std::move(previous_node_info.first);
                std::cout<<"NUOVO NODO CREATO A DESTRA \n";
                return std::make_pair(previous_node_info.first,true);
                break;
            default:
            
                break;
                } 
        /////IMPLEMENTA LA SCRITTURA DEL NODO
        return std::make_pair(previous_node_info.first,false); 
    }

    // template <typename F>
    // std::pair<node*,bool> _insert(F&& x); 
// ***** BALANCING *****


    void balancing(std::vector<pair_type>& b, typename std::vector<pair_type>::iterator& begin,  typename std::vector<pair_type>::iterator& end){
        auto gap = std::distance(begin,end);
        // std::cout<<std::endl;
        // std::cout<< " begin "<< *begin << " \n" << std::endl;
        // std::cout<< " end "<< *end << " \n" << std::endl;
        // std::cout<< " size "<< gap << " \n" << std::endl;
        // std::cout<< " mid "<< *(begin + gap/2) << " \n" << std::endl;
        
    if(std::distance(begin, end) <= 0){
            std::cout<<"chiudo un scope"<< std::endl;
            return;}
        else{
            b.push_back(*(begin + gap/2));
            auto middle_end = begin + gap/2;
            auto middle_begin = begin + gap/2+1;
            balancing(b, begin, middle_end);
            balancing(b, middle_begin , end);
            return;
        }
    }
    //void balancing(std::vector<pair_type>& b, typename std::vector<pair_type>::iterator& begin, typename std::vector<pair_type>::iterator& end);

    void copy_tree(node* x1, node* x2) {
        std::cout<<"COPY TREE \n";
        if (x1->l_next){
            // if there's a left node go left
            //x1 = x1->l_next.get();
            // copy left node in the copy tree
            x2->l_next.reset(new node{x1->l_next.get()->element,x2});
            // go left in the copy tree
            //x2 = x2->l_next.get();
            // recursion
            std::cout<<"SINISTRA \n";
            copy_tree(x1->l_next.get(),x2->l_next.get());
        }
        if (x1->r_next){
            // if there's a right node go right
            //x1 = x1->r_next.get();
            // copy right node in the copy tree
            x2->r_next.reset(new node{x1->r_next.get()->element,x2});
            // go right in the copy tree
            //x2 = x2->r_next.get();
            // recursion
            std::cout<<"DESTRA \n";
            copy_tree(x1->r_next.get(),x2->r_next.get());
        }
        std::cout<<"FINITO \n";
    }
    //void copy_tree(node* x1, node* x2);

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
        std::cout<<"SONO IN BEGIN \n";
        auto tmp = root.get();
        std::cout<< tmp<< "\n";
        while(tmp->l_next){tmp = tmp->l_next.get();}
        std::cout<< tmp<< "\n";
        std::cout<<"ESCO DA BEGIN \n";
        return iterator{tmp};
    }
    const_iterator begin() const{//return const_iterator{this->begin()};
        std::cout<<"SONO IN BEGIN CONST\n";
        auto tmp = root.get();
        std::cout<< tmp<< "\n";
        while(tmp->l_next){tmp = tmp->l_next.get();}
        std::cout<< tmp<< "\n";
        std::cout<<"ESCO IN BEGIN \n";
        return const_iterator{tmp};}     
    
    const_iterator cbegin() const{//return const_iterator{this->begin()};}
        std::cout<<"SONO IN BEGIN CONST CONST\n";
        auto tmp = root.get();
        while(tmp->l_next){tmp = tmp->l_next.get();}
        std::cout<<"ESCO IN BEGIN \n"; 
        return const_iterator{tmp};}
    
    iterator end() noexcept {return iterator{nullptr};}
    const_iterator end() const{ return const_iterator{nullptr};}
    const_iterator cend() const{ return const_iterator{nullptr};}

//##########################################################################################################################################
// ***** METHODS *****
//##########################################################################################################################################

    
    
    std::pair<iterator,bool> insert(const pair_type& x){
        std::cout<<"SONO IN INSERT LEFT\n";
        auto result = _insert(x);
        return std::make_pair(iterator{result.first},result.second);
    }
    std::pair<iterator,bool> insert(pair_type&& x){
        std::cout<<"SONO IN INSERT RIGHT\n";
        auto result = _insert(std::move(x));
        return std::make_pair(iterator{result.first},result.second);
    }
//################################################################################################################################################################
// std::pair<iterator,bool> insert(const pair_type& x){    
//     std::cout<<"SONO IN INSERT LEFT\n";
//     if(!root)
//     {   std::cout<<"CREO UN NUOVO ALBERO \n";
//         root.reset(new node(x));

//         return std::make_pair(iterator{root.get()}, true);
//     }

//     auto previous_node_info = compare_and_move(x.first);


//     switch (previous_node_info.second)
//             {
//         case direction::stop:
//             //insertion.first = std::move(previous_node_info.first); // voglio fare una copia del puntatore questa cosa è corretta?
//             //insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
//             std::cout<<"NODO GIÀ ESISTENTE \n";
//             return std::make_pair(iterator{previous_node_info.first},false);
//             break;
//         case direction::left:
//             previous_node_info.first->l_next.reset(new node(x, previous_node_info.first));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
//             //insertion.first = std::move(previous_node_info.first);
//             std::cout<<"NUOVO NODO CREATO A SINISTRA \n";
//             return std::make_pair(iterator{previous_node_info.first},true);
//             break;
//         case direction::right:
//             previous_node_info.first->r_next.reset(new node(x, previous_node_info.first));//vedere new template come va utilizzato??????????
//             //insertion.first = std::move(previous_node_info.first);
//             std::cout<<"NUOVO NODO CREATO A DESTRA\n";
//             return std::make_pair(iterator{previous_node_info.first},true);
//             break;
//         default:
        
//             break;
//             } 
//     /////IMPLEMENTA LA SCRITTURA DEL NODO
//     return std::make_pair(iterator{previous_node_info.first},false); 
// }


// std::pair<iterator,bool> insert(pair_type&& x){  
//     std::cout<<"SONO IN INSERT RIGHT\n";
//     if(!root)
//     {   std::cout<<"CREO UN NUOVO ALBERO \n";
//         root.reset(new node(std::move(x)));

//         return std::make_pair(iterator{root.get()}, true);
//     }

//     auto previous_node_info = compare_and_move(std::move(x).first);
//     std::cout<<"PREVIOUS NODE INFO"<< static_cast<std::underlying_type<direction>::type>(previous_node_info.second);

//     switch (previous_node_info.second)
//             {
//         case direction::stop:
//             //insertion.first = std::move(previous_node_info.first); // voglio fare una copia del puntatore questa cosa è corretta?
//             //insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
//             std::cout<<"NODOD GIÀ ESISTENTE \n";
//             return std::make_pair(iterator{previous_node_info.first},false);
//             break;
//         case direction::left:
//             previous_node_info.first->l_next.reset(new node(std::move(x), previous_node_info.first));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
//             //insertion.first = std::move(previous_node_info.first);
//             std::cout<<"NUOVO NODO CREATO A SINISTRA \n";
//             return std::make_pair(iterator{previous_node_info.first},true);
//             break;
//         case direction::right:
//             previous_node_info.first->r_next.reset(new node(std::move(x), previous_node_info.first));//vedere new template come va utilizzato??????????
//             //insertion.first = std::move(previous_node_info.first);
//             std::cout<<"NUOVO NODO CREATO A DESTRA\n";
//             return std::make_pair(iterator{previous_node_info.first},true);
//             break;
//         default:
        
//             break;
//             } 
//     /////IMPLEMENTA LA SCRITTURA DEL NODO
//     return std::make_pair(iterator{previous_node_info.first},false); 
// }

//################################################################################################################################################################
    

template <class... Types>
std::pair<iterator,bool> emplace(Types&&... args){
    std::cout<<"SONO IN EMPLACE \n";
    pair_type emplace_pair{std::forward<Types>(args)...};

    std::pair<node*,bool> return_pair;
    return_pair = _insert(emplace_pair);
    std::cout<<"ESCO DA EMPLACE \n";
    return std::make_pair(iterator{return_pair.first},return_pair.second);
}
    
    
    
    
    // template <class... Types>
    // std::pair<iterator,bool> emplace(Types&&... args);
// ***** CLEAR *****


void clear(){
    std::cout<<"SONO IN CLEAR \n";
    if(!root) {
        std::cout<<"L'ALBERO NON C'È \n";
        return;}
    //auto tmp = root.get();
    root.reset();
    std::cout<<"ESCO DA CLEAR \n";
    //tmp->~Node();
}

// ***** FIND *****


iterator find(const kT& x){
    std::cout<<"SONO IN FIND \n";
    auto tmp = root.get();
    direction d;
    while(tmp && d != direction::stop)
    {   
        d = compare(x,tmp->element.first,op);
        tmp = move_on(tmp,d);
        std::cout<<"fino a quando d=stop o tm è nullptr"<< static_cast<std::underlying_type<direction>::type>(d) << " " <<tmp <<" \n";
    }
    if(d == direction::stop)
        {std::cout<<"ramo d=stop  \n";
            return iterator{tmp};}
    else {std::cout<<"ritorno end \n";
        return this->end();}///check end
}

const_iterator find(const kT& x) const{
    std::cout<<"SONO IN FIND CONST\n";
    auto tmp = find(x);
    std::cout<<"ESCO DA FIND CONST \n";
    return const_iterator{tmp};
}
    // void clear();

    // iterator find(const kT& x);
    // const_iterator find(const kT& x) const;

void balance(){

    // write the pairs of all the nodes ordered in a vector
    std::vector<pair_type> ordered_vector;
    for(auto& i : *this){
        ordered_vector.push_back(i);
    }
    // if the vector has size 2 or lower, return
    if(ordered_vector.size() < 3){return;}
    // delete the tree
    this->clear();
    // create a new vector with a balanced order of insertion
        std::vector<pair_type> balanced_vector;
        auto begin = ordered_vector.begin();
        auto end = ordered_vector.end();
        balancing(balanced_vector, begin, end);
        for (auto i: balanced_vector){
        std::cout<< i.first << " ";
        std::cout<<std::endl;
    }
    // create a new tree inserting pairs using the second vector
    for(auto& x : balanced_vector){
        this->insert(std::move(x));
    }
}

    //void balance();
// ***** ERASE *****


void erase(const kT& x){
    if(!root)
    {
        return;
    }

    // move to the node before the one to erase
    //std::pair<iterator,direction> previous_node_info;
    auto previous_node_info = compare_and_move(x);

    node* it;

    // check if the node to be erased is on l_next or r_next 
    // and reset to nullptr the corresponding unique_ptr
    if(previous_node_info.second == direction::left){
        it = previous_node_info.first->l_next.release();
        previous_node_info.first->l_next.reset();
    } else{
        it = previous_node_info.first->r_next.release();
        previous_node_info.first->l_next.reset();
    } 

    // checking if the node to be erased exists
    if(!it){
        std::cout << "The node you want to erase is not present" << std::endl;
        return;
        }

    // copy of pointers from the node to be erased
    auto up = it->parent;
    auto left = it->l_next.release();
    auto right = it->r_next.release();

    // reset all unique_ptrs of the node to be erased
    //it->parent.reset();
    //it->l_next.reset();
    //it->r_next.reset();

    // Node destruction
    it->~Node();


    // check if there was something attached to the node to be erased
    auto branch = right;

    if(right){
        right->parent = up;
    }
    else if(left){
        left->parent = up;
        branch = left;
    }
    else{
        return;
    }

    // attach an existing branch to the node before the erased one
    if(previous_node_info.second == direction::left){
        up->l_next.reset(branch);
    } else{
        up->r_next.reset(branch);}

    //if right branch exists, attach the left branch to the right one
    if(right){
        previous_node_info = compare_and_move(left->element.first);

        if(previous_node_info.second == direction::left){
            previous_node_info.first->l_next.reset(left);
        } else{
            previous_node_info.first->r_next.reset(left);
        }
    }
}

    //void erase(const kT& x);

        
    // ***** OPERATOR [] *****
    vT& operator[](const kT& x){
        auto it = find(x);
        if(it!=this->end()){
            return (*it).second;
        }
        else{
            vT s{};
            return s;
            // std::pair<vT, kT> p1{x,second};
            // auto p2 = insert(p1);
            // return (*(p2.first)).second;
        }
    }


    vT& operator[](kT&& x){
        auto it = find(std::move(x));
        if(it!=this->end()){
            return (*it).second;// assicurarsi che quando il valore del nodo sia vuoto restituisca vuoto e non un valore random!!!!
        }
        else{
            vT s{};
            return s;
            // std::pair<vT, kT> p1{std::move(x),second};
            // auto p2 = insert(p1);
            // return (*(p2.first)).second;
        }
    }


    // ***** OPERATOR << *****

    friend
    std::ostream& operator<<(std::ostream& os, const Bst& x){
        if(!x.root){
            os <<"The tree is empty"<<'\n';
            return os;}
        for (const auto& i : x) {
            os << "begin "<< (*x.begin()).first << "\n";
            os << "key  " << i.first << " value " << i.second << '\n';}
            os <<"L'albero esiste"<<'\n';
        return os;
    }

    void tryfor(){
        for(const auto& i : *this){std::cout<< i.second <<"\n";}
    }

};

/// friend std::ostream operator<<(const std::ostream os, const Bst<T,> tree)

#endif
