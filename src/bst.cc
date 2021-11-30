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


// ***** INSERT *****
/// analizzare assegnazione unique_pointer
template <typename kT,typename vT,typename OP>
std::pair<iterator,bool>  Bst<kT,vT,OP>::insert(const pair_type& x){
    //potrebbe essere meglio dichiarare questi due insert in
    //privato e mettere un unico insert pubblico
    std::pair<iterator,bool> insertion(nullptr, true);


std::pair<iterator,direction> Bst<kT,vT,OP>::compare_and_move(const kT& k){
    iterator tmp{root.get()};
    direction d;
    while(tmp || d != direction::stop)
    {
        insertion.first = tmp;
        d = compare(k.first,*tmp.first,op);
        tmp = move_on(tmp,d);
    }
    return std::make_pair(tmp,d);
}


    switch (d)
            {
        case direction::stop:
            insertion.first = std::move(tmp); // voglio fare una copia del puntatore questa cosa è corretta?
            insertion.second = false; //verificare se funziona questo tipo di assegnazione di std pair
            break;
        case direction::left:
            tmp.current = tmp.current->parent.get();
            tmp.current -> l_next.reset(new Node<kT, vT>(x, tmp.current));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
            insertion.first = std::move(tmp);
            break;
        case direction::right:
            tmp.current = tmp.current->parent.get();
            tmp.current -> r_next.reset(new Node<kT, Vt>(x, tmp.current));//vedere new template come va utilizzato??????????
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
    iterator it,d = find(x);  // compare_and_move

    if(it == *this.end()){
        std::cout << "The node you want to erase is not present" << std::endl;
        return;
        }

    auto up = it.current->parent.get();
    auto left = it.current->l_next.get();
    auto right = it.current->r_next.get();

    it.current->parent.reset();
    it.current->l_next.reset();
    it.current->r_next.reset();

    right->parent.reset(up);
    if(d == direction::left){
        up->l_next.reset{right};
    } else{
        up->r_next.reset{right};
    }

    it,d = find(left->elem.first);  // compare_and_move

    if(d == direction::left){
        it.current->l_next.reset{left};
    } else{
        it.current->r_next.reset{left};
    }
}