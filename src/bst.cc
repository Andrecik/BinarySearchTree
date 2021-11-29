#include "include/bst.h"
#include "include/iterator.h"

template <typename kT,typename vT,typename OP>   
template <typename kOT, typename vOT>
using iterator = typename Bst<kT,vT,OP>::__Iterator<kOT, vOT>;
template <typename kOT, typename vOT>
using const_iterator = __Iterator<const  std::pair<kOT, vOT>>;
template <typename kT,typename vT>
using pair_type = std::pair<kT,vT>;


template <typename kT,typename vT,typename OP>
direction Bst<kT,vT,OP>::compare(typename Bst<kT,vT,OP>::Node<kT,vT>& a, typename Bst<kT,vT,OP>::Node<kT,vT>& b, OP& op){
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
            while( direction::right!= compare(*it , tmp, op) );
        return tmp;
        }
    }

// ***** MOVE ON*****
template <typename kT,typename vT,typename OP>
iterator Bst<kT,vT,OP>::move_on(iterator current, direction& d){////sistemare iterator to address
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

// ***** INSERT *****
/// analizzare assegnazione unique_pointer
template <typename kT,typename vT,typename OP>
std::pair<iterator,bool>  Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico
    Node x_node;
    p = root.get();
    std::pair<iterator,bool> position;
    while()
    {
    d = compare(p*);
    switch (d)
            {
        case direction::stop:
            position = make_pair ( , 2.22e-1 );
            return position;
            break;
        default:
            it = move_on(d)
            break;
        }   
    
     

    
    
    }

template <typename kT,typename vT,typename OP>
template <typename kOT, typename vOT>
std::pair<iterator<kOT, vOT>,bool> Bst<kT,vT,OP>::insert(pair_type&& x){
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
    auto tmp = root.get();
    root.reset();
    tmp->~Node();
}

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