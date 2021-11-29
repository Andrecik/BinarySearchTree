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
direction Bst<kT,vT,OP>::compare(const pair_type& a, const pair_type&  b, OP& op){///bisogna vedere come accedere ad attributo di attributo
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
        it.current = it.current -> l_next;///necessità di cambiare l'operatore freccia al posto di cedere element cediamo il nodo?????
        std::cout<< " I'm moving left" << std::endl;
        break;
    case direction::right:
        it.current = it.current -> r_next;
        std::cout<< " I'm moving right" << std::endl;
        break;
    default:
        std::cout<< " freeze, don't move " << std::endl;
        break;
    }
    return it;
}

// ***** INSERT *****
/// analizzare assegnazione unique_pointer
template <typename kT,typename vT,typename OP>
std::pair<iterator,bool>  Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico
    iterator tmp;
    tmp.current = root.get(); // verificare se riesco ad ottenere un iterator cosi vedere i costruttori;
    std::pair<iterator,bool> insertion(tmp, true);
    while(tmp || d != direction::stop)
    {
        d = compare(*tmp, x, op);
        tmp = move_on(tmp,d);
    }
    
    switch (d)
            {
        case direction::stop:
            insertion.first = std::move(tmp); // voglio fare una copia del puntatore questa cosa è corretta?
            insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
            break;
        case direction::left:
            tmp.current = tmp.current->parent.get();
            tmp.current -> l_next.reset(new node{x});//per creare il nuovo nodo
            insertion.first = std::move(tmp);
            break;
        case direction::right:
            tmp.current = tmp.current->parent.get();
            tmp.current -> r_next.reset(new node{x});//per creare il nuovo nodoinsertion.first = tmp;
            insertion.first = std::move(tmp);
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
    //bool is true if the node is already present, false
    //otherwise

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