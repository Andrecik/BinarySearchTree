#include <iostream>
#include <memory>
#include <utility>
#include "include/node.h"
#include "include/iterator.h"
#include "include/bst.h"
#include "include/ap_error.h"


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
    std::cout<<"\n \nInserisco il secondo nodo \n";
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
    return 0;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

    return 0;
}