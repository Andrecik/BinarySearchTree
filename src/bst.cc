#include "include/bst.h"


// //***** COMPARE *****

template <typename kT,typename vT,typename OP>
template <typename F>
    direction Bst<kT,vT,OP>::compare(F&& a, const kT&  b, OP& op) noexcept {
        //std::cout<<"SONO IN COMPARE \n";
        //std::cout<<"Checking "<< a << " I'm in  "<< b << "\n";
        if(op(std::forward<F>(a), b)){
            //std::cout<<"ESCO DA COMPARE LEFT \n";
            return direction::left;
        }
        else if(op(b,std::forward<F>(a))){
            //std::cout<<"ESCO DA COMPARE RIGHT \n";
            return direction::right;
        }
        else{
            //std::cout<<"ESCO DA COMPARE STOP \n";
            return direction::stop;
        }
    }

// ***** MOVE ON*****

template <typename kT,typename vT,typename OP>
typename Bst<kT,vT,OP>::node* Bst<kT,vT,OP>::move_on(node* it, direction& d) noexcept {
    //std::cout<<"SONO IN MOVE ON \n";
    switch (d)
    {

    case direction::left:

        it = it->l_next.get();
        //std::cout<< "I'm moving left \n" << std::endl;
        break;

    case direction::right:

        it = it->r_next.get();
        //std::cout<< "I'm moving right \n" << std::endl;
        break;

    default:

        //std::cout<< "freeze, don't move \n" << std::endl;
        break;

    }
    //std::cout<<"ESCO DA MOVE ON \n";
    return it;
}

// ***** COMPARE_AND_MOVE *****

template <typename kT,typename vT,typename OP>
template <typename F>
std::pair<typename Bst<kT,vT,OP>::node*,direction> Bst<kT,vT,OP>::compare_and_move(F&& k) noexcept {

    //std::cout<<"SONO IN COMPARE AND MOVE \n";
    //std::cout<<"questo è root"<< root.get()<< " \n";
    auto tmp = root.get();
    //std::cout<< tmp->element.first << "\n";
    node* tmp_previous_node;
    direction d = direction::stop;
    
    do{   

        d = compare(std::forward<F>(k),tmp->element.first,op);
        tmp_previous_node = tmp;
        tmp = move_on(tmp,d);   

    }while(tmp && d != direction::stop);

    //std::cout<<"ESCO DA COMPARE AND MOVE \n";
    return std::make_pair(tmp_previous_node, d);
}

// ***** _INSERT *****

template <typename kT,typename vT,typename OP>
template <typename F>
std::pair<typename Bst<kT,vT,OP>::node*,bool>  Bst<kT,vT,OP>::_insert(F&& x){
    //std::cout<<"SONO IN INSERTINO \n";
    if(!root){

        root.reset(new node(std::forward<F>(x)));
        return std::make_pair(root.get(), true);

    }

    auto previous_node_info = compare_and_move(std::forward<F>(x).first);


    switch (previous_node_info.second)
    {
        case direction::stop:

            //std::cout<<"NODO GIÀ ESISTENTE \n";
            return std::make_pair(previous_node_info.first,false);
            break;

        case direction::left:

            previous_node_info.first->l_next.reset(new node(std::forward<F>(x), previous_node_info.first));//tmp.current è un pointer a nodo dovrebbw invocare il custom costructor
            //std::cout<<"NUOVO NODO CREATO A SINISTRA \n";
            return std::make_pair(previous_node_info.first->l_next.get(),true);
            break;

        case direction::right:

            previous_node_info.first->r_next.reset(new node(std::forward<F>(x), previous_node_info.first));//vedere new template come va utilizzato??????????
            //std::cout<<"NUOVO NODO CREATO A DESTRA \n";
            return std::make_pair(previous_node_info.first->r_next.get(),true);
            break;

        default:

            break;

    } 

    return std::make_pair(previous_node_info.first,false); 

}

// ***** COPY TREE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::copy_tree(node* x1, node* x2) {
        //std::cout<<"COPY TREE \n";
    if (x1->l_next){
        // copy left node in the copy tree
        x2->l_next.reset(new node{x1->l_next.get()->element,x2});
        //std::cout<<"SINISTRA \n";
        // recursion going left in both trees
        copy_tree(x1->l_next.get(),x2->l_next.get());
    }
    if (x1->r_next){
        // copy right node in the copy tree
        x2->r_next.reset(new node{x1->r_next.get()->element,x2});
        //std::cout<<"DESTRA \n";
        // recursion going right in both trees
        copy_tree(x1->r_next.get(),x2->r_next.get());
    }
    //std::cout<<"FINITO \n";
}

// ***** EMPLACE *****

template <typename kT,typename vT,typename OP>
template <class... Types>
std::pair<typename Bst<kT,vT,OP>::iterator,bool> Bst<kT,vT,OP>::emplace(Types&&... args){
    //std::cout<<"SONO IN EMPLACE \n";
    pair_type emplace_pair{std::forward<Types>(args)...};

    std::pair<node*,bool> return_pair;
    return_pair = _insert(emplace_pair);
    //std::cout<<"ESCO DA EMPLACE \n";
    return std::make_pair(iterator{return_pair.first},return_pair.second);
}

// // ***** CLEAR *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::clear() noexcept {
    //std::cout<<"SONO IN CLEAR \n";
    root.reset();
    //std::cout<<"ESCO DA CLEAR \n";
}

// // ***** FIND *****

template <typename kT,typename vT,typename OP>
typename Bst<kT,vT,OP>::iterator Bst<kT,vT,OP>::find(const kT& x) noexcept {
    //std::cout<<"SONO IN FIND \n";

    auto node_info = compare_and_move(x);

    if(node_info.second == direction::stop){
        //std::cout<<"ramo d=stop  \n";
        return iterator{node_info.first};}
    else{
        //std::cout<<"ritorno end \n";
        return this->end();
    }
}


template <typename kT,typename vT,typename OP>
typename Bst<kT,vT,OP>::const_iterator Bst<kT,vT,OP>::find(const kT& x) const noexcept {
    //std::cout<<"SONO IN FIND CONST\n";
    auto tmp = find(x);
    //std::cout<<"ESCO DA FIND CONST \n";
    return const_iterator{tmp};
}
//***** BALANCING *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::balancing(std::vector<Bst<kT,vT,OP>::pair_type>& b, typename std::vector<Bst<kT,vT,OP>::pair_type>::iterator& begin, typename std::vector<Bst<kT,vT,OP>::pair_type>::iterator& end){

    auto gap = std::distance(begin,end);

    if(std::distance(begin, end) <= 0){
        //std::cout<<"chiudo un scope"<< std::endl;
        return;
    }else{
        b.push_back(*(begin + gap/2));
        auto middle_end = begin + gap/2;
        auto middle_begin = begin + gap/2+1;
        balancing(b, begin, middle_end);
        balancing(b, middle_begin , end);
        return;
    }
}

// ***** BALANCE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::balance(){
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


// // ***** ERASE *****

template <typename kT,typename vT,typename OP>
void Bst<kT,vT,OP>::erase(const kT& x) noexcept {
    //std::cout<<"SONO IN ERASE \n";

    // checking if the tree is empty
    if(!root)
    {   
        std::cout << "The tree is empty." << std::endl;
        return;
    }

    // move at the node to erase
    auto node_info = compare_and_move(x);


    // checking if the node to be erased exists
    if(node_info.second != direction::stop){
        std::cout << "The node you want to erase is not present" << std::endl;
        return;
    }

    // copy of pointers from the node to be erased
    auto up = node_info.first->parent;
    auto left = node_info.first->l_next.release();
    auto right = node_info.first->r_next.release();

    // check if there was something attached to the node to be erased
    auto branch = right;

    if(right){
        right->parent = up;
    }
    else if(left){
        left->parent = up;
        branch = left;
    }

    // check if the node to be erased is not root node
    if(up){
    // check if the node to be erased is on l_next or r_next 
    // and reset to branch the corresponding unique_ptr
        if(up->l_next.get()==node_info.first){
            up->l_next.reset(branch);
        }else{
            up->r_next.reset(branch);
        } 

    }else{

        root.reset(branch);

    }

    //if both right and left branches exist, attach the left branch to the right one
    if(right && left){
        node_info = compare_and_move(left->element.first);
        left->parent = node_info.first;
        if(node_info.second == direction::left){
            node_info.first->l_next.reset(left);
        } else{
            node_info.first->r_next.reset(left);
        }
    }
    //std::cout<<"ESCO ERASE \n";
}


