#include "include/bst.h"
#include "include/iterator.h"

template <typename kT,typename vT,typename OP>   
template <typename kOT, typename vOT>
using iterator = typename Bst<kT,vT,OP>::__Iterator<kOT, vOT>;
template <typename kOT, typename vOT>
using const_iterator = __Iterator<const  std::pair<kOT, vOT>>;
template <typename kT,typename vT>
using pair_type = std::pair<kT,vT>;

// ***** COMPARE *****
template <typename kT,typename vT,typename OP>
direction Bst<kT,vT,OP>::compare(const kT& a, const kT&  b, OP& op){///bisogna vedere come accedere ad attributo di attributo
    if(op(a, b)){
        return direction::left;
    }
    else if(!op(a, b)){
        return direction::right;
    }
    else{
        return direction::stop;
    }
}

//***** NEXT *****
template <typename kT,typename vT,typename OP>
iterator  Bst<kT,vT,OP>::next(iterator& it){
    auto tmp = it;
    if(tmp.current->r_next){ 
        while(tmp.current->l_next){tmp.current = tmp.current->l_next.get();}
        return tmp;
        }
    else{
        do{tmp.current = tmp.current->parent.get();}
            while( direction::right!= compare(*it, *tmp, op) );
        return tmp;
        }
    }

// ***** MOVE ON*****
template <typename kT,typename vT,typename OP>
iterator Bst<kT,vT,OP>::move_on(iterator& it, direction& d){////sistemare iterator to address
    switch (d)
    {
    case direction::left:
        it.current = it.current -> l_next.get();///necessità di cambiare l'operatore freccia al posto di cedere element cediamo il nodo?????
        std::cout<< " I'm moving left" << std::endl;
        break;
    case direction::right:
        it.current = it.current -> r_next.get();
        std::cout<< " I'm moving right" << std::endl;
        break;
    default:
        std::cout<< " freeze, don't move " << std::endl;
        break;
    }
    return it;
}

// ***** COMPARE_AND_MOVE *****

std::pair<iterator,direction> Bst<kT,vT,OP>::compare_and_move(const kT& k){
    iterator tmp{root.get()};
    iterator tmp_previous_node;
    direction d;
    direction d_previous_node;
    while(tmp || d != direction::stop)
    {
        tmp_previous_node = tmp;
        d_previous_node = d;
        d = compare(k.first,*tmp.first,op);
        tmp = move_on(tmp,d);
    }
    return std::make_pair(tmp_previous_node,d_previous_node);
}

// ***** INSERT *****
/// analizzare assegnazione unique_pointer
template <typename kT,typename vT,typename OP>
std::pair<iterator,bool>  Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico
    std::pair<iterator,bool> insertion(nullptr, true);

    std::pair<iterator,direction> previous_node_info;

    previous_node_info = compare_and_move(x.first);


    switch (previous_node_info.second)
            {
        case direction::stop:
            insertion.first = std::move(previous_node_info.first); // voglio fare una copia del puntatore questa cosa è corretta?
            insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
            break;
        case direction::left:
            previous_node_info.first.current -> l_next.reset(new Node<kT, vT>(x, previous_node_info.first.current));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
            insertion.first = std::move(previous_node_info.first);
            break;
        case direction::right:
            previous_node_info.first.current -> r_next.reset(new Node<kT, Vt>(x, previous_node_info.first.current));//vedere new template come va utilizzato??????????
            insertion.first = std::move(previous_node_info.first);
            break;
        default:
            break;
            } 
    /////IMPLEMENTA LA SCRITTURA DEL NODO
    return insertion;  
}

template <typename kT,typename vT,typename OP>
template <typename kOT, typename vOT>
std::pair<iterator<kOT, vOT>,bool> Bst<kT,vT,OP>::insert(pair_type&& x){


    return ;
}


// ***** EMPLACE *****

template <typename kT,typename vT,typename OP>
template <class... Types>
std::pair<iterator,bool> Bst<kT,vT,OP>::emplace(Types&&... args){

    return;
}


// ***** CLEAR *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::clear(){
    auto tmp = root.get();
    root.reset();
    tmp->~Node();

}

// ***** FIND *****

template <typename kT,typename vT,typename OP>
iterator Bst<kT,vT,OP>::find(const kT& x){
    iterator tmp{root.get()};
    direction d;
    while(tmp || d != direction::stop)
    {
        d = compare(x,*tmp.first,op);
        tmp = move_on(tmp,d);
    }
    if(d == direction::stop)
        {return tmp;}
    else {return this->end();}///check end
}

template <typename kT,typename vT,typename OP>
const_iterator Bst<kT,vT,OP>::find(const kT& x) const{
    auto tmp = find(x);
    return const_iterator{tmp};
}

// ***** BALANCE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::balance(){


}

// ***** ERASE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::erase(const kT& x){

    // move to the node before the one to erase
    std::pair<iterator,diretion> previous_node_info;
    previous_node_info = compare_and_move(x);

    iterator it;

    // check if the node to be erased is on l_next or r_next 
    // and reset to nullptr the corresponding unique_ptr
    if(previous_node_info.second == direction::left){
        it.current = previous_node_info.first.current->l_next.get();
        previous_node_info.first.current->l_next.reset();
    } else{
        it.current = previous_node_info.first.current->r_next.get();
        previous_node_info.first.current->l_next.reset();
    } 

    // checking if the node to be erased exists
    if(!it.current){
        std::cout << "The node you want to erase is not present" << std::endl;
        return;
        }

    // copy of pointers from the node to be erased
    auto up = it.current->parent.get();
    auto left = it.current->l_next.get();
    auto right = it.current->r_next.get();

    // reset all unique_ptrs of the node to be erased
    it.current->parent.reset();
    it.current->l_next.reset();
    it.current->r_next.reset();

    // Node destruction
    it.current->~Node();
dadsadsdadsadadsddssasadas

    // check if there is something attached to the node to be erased
    auto branch = right;

    if(right){
        right->parent.reset(up);
    }
    else if(left){
        left->parent.reset(up);
        branch = left;
    }
    else{
        return;
    }

    // attach an existing branch to the node before the erased one
    if(previous_node_info.second == direction::left){
        up->l_next.reset{branch};
    } else{
        up->r_next.reset{branch}};
    }

    //if right branch exists, attach the left branch to the right one
    if(right){
        previous_node_info = compare_and_move(left->elem.first);

        if(previous_node_info.second == direction::left){
           previous_node_info.first.current->l_next.reset{left};
        } else{
            previous_node_info.first.current->r_next.reset{left};
        }
    }
}