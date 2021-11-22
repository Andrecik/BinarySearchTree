#include "include/bst.h"


// ***** INSERT *****

template <typename kT,typename vT,typname OP>
std::pair<iterator,bool> Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico

    return
}

template <typename kT,typename vT,typname OP>
std::pair<iterator,bool> Bst<kT,vT,OP>::insert(pair_type&& x){
    //bool is true if the node is already present, false
    //otherwise

    return
}

// ***** EMPLACE *****

template <typename kT,typename vT,typname OP>
template <class... Types>
std::pair<iterator,bool> Bst<kT,vT,OP>::emplace(Types&&... args){

    return
}

// ***** CLEAR *****

template <typename kT,typename vT,typname OP>
void Bst<kT,vT,OP>::clear(){

}

// ***** FIND *****


template <typename kT,typename vT,typname OP>
iterator Bst<kT,vT,OP>::find(const kT& x){

    return
}

template <typename kT,typename vT,typname OP>
const_iterator Bst<kT,vT,OP>::find(const kT& x) const{

    return
}

// ***** BALANCE *****

template <typename kT,typename vT,typname OP>
void Bst<kT,vT,OP>::balance(){


}

// ***** ERASE *****

template <typename kT,typename vT,typname OP>
void Bst<kT,vT,OP>::erase(const kT& x){


}