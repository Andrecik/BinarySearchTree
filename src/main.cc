#include <iostream>
#include <memory>
#include <utility>
#include "include/node.h"
#include "include/iterator.h"
#include "include/bst.h"
#include "include/ap_error.h"

//implementare un operatore custom
int main(){
  try {

    Bst<int,char,std::less<int>> tree1{std::less<int>()};
    std::cout << tree1 << std::endl; 
    //Bst<int,char,std::less<int>> tree2{tree1};
    std::cout<<"\n \nInserisco il primo nodo \n";
    auto i = tree1.insert(std::make_pair(3,'a'));
    std::cout<<"\n \nInserisco il secondo nodo \n";
    i = tree1.insert(std::make_pair(3,'a'));
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
    std::cout<<"\n \nInserisco il terzo nodo \n";
    i = tree1.insert(std::make_pair(4,'a'));
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
        i = tree1.insert(std::make_pair(2,'a'));
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
    std::cout<<"\n \nInserisco il quarto nodo \n";
        i = tree1.insert(std::make_pair(5,'a'));
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
    
    tree1.tryfor();

    // const Bst<int,char,std::less<int>> tree2{std::less<int>()};

    //std::cout << *(tree2.end())

    std::cout<< "provo a printare \n";
    std::cout << tree1 << std::endl;
    i = tree1.emplace(8,'a');
    std::pair<const int, char> p2{1,'a'};
    std::pair<int, char> p3{7,'a'}; 
    i = tree1.insert(p2);
    i = tree1.insert(p3);
        std::cout<< "provo a printare 2\n";
    std::cout << tree1 << std::endl;
    //tree1.balance();
        std::cout<< "provo a printare 3 \n";
    std::cout << tree1 << std::endl;


    Bst<int,char,std::less<int>> tree2{tree1};
      std::cout<< "provo a printare il secondo albero \n";
    std::cout << tree2 << std::endl;
    return 0;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

  
  
    return 0;
}