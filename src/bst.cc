#include "include/bst.h"


template <typename vOT>
using iterator = __Iterator<vOT>;
template <typename vOT>
using const_iterator = __Iterator<const vOT>;
template <typename kT,typename vT>
using pair_type = std::pair<kT,vT>;

// ***** INSERT *****
template <typename kT,typename vT,typename OP>
template <typename vOT>
Node* compare_key(OP OP, pair_type& a, std::pair<__Iterator<vOT>,bool> y){
    if(OP(a.first, b.first) && !OP(a.first, b.first)){
        
    }
    else if(!OP(a.first, b.first)){
        
    }
    else if(OP(a.first, b.first)){
        
    }

}
/// analizzare assegnazione unique_pointer
template <typename kT,typename vT,typename OP>
template <typename vOT>
std::pair<__Iterator<vOT>,bool> Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico
    std::pair<__Iterator<vOT>,bool> y;
    if !root{
        p = root;//vedere come gestire lo unique pointer
        y.second = true;
        while (p == nullptr)
        {
            if(OP(a.first, *p.element.first) && !OP(a.first, *p.element.first){
            y.first = false;
            y.second =  p;
            p = nullptr;
        }
            else if(!OP(a.first, *p.element.first)){
                p = *p.r_next;
            }
            else if(OP(a.first, *p.element.first)){
                p = *p.l_next;
            }    
        }
        

        

    }
    else{
        root = *Node(x);
        y.first = *Node(x);
    }
    
    return y;
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