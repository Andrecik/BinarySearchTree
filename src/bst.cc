#include "include/bst.h"


    
template <typename kOT, typename vOT>
using iterator = __Iterator<std::pair<kOT, vOT>>;
template <typename kOT, typename vOT>
using const_iterator = __Iterator<const  std::pair<kOT, vOT>>;
template <typename kT,typename vT>
using pair_type = std::pair<kT,vT>;


// ***** INSERT *****
template <typename kT,typename vT,typename OP>
template <class kO, class vO>
direction Bst<kT,vT,OP>::compare(Node<kO,vO>& a, Node<kO,vO>& b, OP& op){
    direction y;
    if(op(a.first, b.first) && !op(a.first, b.first)){
        y = direction::stop;
        return y;
    }
    else if(!op(a.first, b.first)){
         y = direction::right;
        return y;
    }
    else if(op(a.first, b.first)){
         y = direction::left;
        return y;
    }

}


template <typename kT,typename vT,typename OP>
template <class kO, class vO>
iterator Bst<kT,vT,OP>::next(Node<kO,vO>* current, direction& d){
    switch (d)
    {
    case direction::left:
        current = current -> l_next;
        break;
    case direction::right:
        current = current -> r_next;
        break;
    default:
        break;
    }
    

    return current;
}
/// analizzare assegnazione unique_pointer
template <typename kT,typename vT,typename OP>
std::pair<iterator,bool>  Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico
    
    }

template <typename kT,typename vT,typename OP>
std::pair<iterator,bool> Bst<kT,vT,OP>::insert(pair_type&& x){
    //bool is true if the node is already present, false
    //otherwise

    return ;
}

// ***** EMPLACE *****

template <typename kT,typename vT,typename OP>
template <class... Types>
std::pair<iterator,bool> Bst<kT,vT,OP>::emplace(Types&&... args){

    return
}

// ***** CLEAR *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::clear(){

}

it = find(f)
// ***** FIND *****


template <typename kT,typename vT,typename OP>
iterator Bst<kT,vT,OP>::find(const kT& x){

    return;
}

template <typename kT,typename vT,typename OP>
const_iterator Bst<kT,vT,OP>::find(const kT& x) const{

    return;
}

// ***** BALANCE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::balance(){


}

// ***** ERASE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::erase(const kT& x){


}