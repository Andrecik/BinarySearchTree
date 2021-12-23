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

    std::cout << " \n provo vedere ";
    std::cout<<(*(i.first)).first<<std::endl;
    std::cout<<"\n \nInserisco il secondo nodo \n";
    i = tree1.insert(std::make_pair(3,'b'));

    std::cout << " \n provo vedere ";
    std::cout<<(*(i.first)).first<<std::endl;
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
    std::cout<<"\n \nInserisco il terzo nodo \n";
    i = tree1.insert(std::make_pair(4,'b'));

    std::cout << " \n provo vedere ";
    std::cout<<(*(i.first)).first<<std::endl;
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
        i = tree1.insert(std::make_pair(2,'c'));

    std::cout << " \n provo vedere ";
    std::cout<<(*(i.first)).first<<std::endl;
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
    std::cout<<"\n \nInserisco il quarto nodo \n";
        i = tree1.insert(std::make_pair(5,'d'));

    std::cout << " \n provo vedere ";
    std::cout<<(*(i.first)).first<<std::endl;
    if (!i.second){
      std::cout<< "Already in the tree \n";

    }
    else{std::cout<< "insert \n";}
    
    tree1.tryfor();

    // const Bst<int,char,std::less<int>> tree2{std::less<int>()};

    //std::cout << *(tree2.end())

    std::cout<< "provo a printare \n";
    std::cout << tree1 << std::endl;
    i = tree1.emplace(8,'g');

    std::cout << " \n provo vedere ";
    std::cout<< " 8 " << std::endl;
    std::cout<<(*(i.first)).first<<std::endl;
    std::pair<const int, char> p2{1,'e'};
    std::pair<int, char> p3{7,'f'}; 
    i = tree1.insert(p2);
    std::cout << " \n provo vedere ";
    std::cout<<p2.first << " " << std::endl;
    std::cout<<(*(i.first)).first<<std::endl;



    i = tree1.insert(p3);
    std::cout << " \n provo vedere ";
    std::cout<<p3.first << " " << std::endl;
    std::cout<<(*(i.first)).first<<std::endl;
    
        std::cout<< "provo a printare 2\n";
        std::cout<<p2.first << " " << std::endl;
    std::cout << tree1 << std::endl;

    std::cout << " \n provo a bilanciare \n \n ";
    
    tree1.balance();
        std::cout<< "provo a printare 3 \n";
    std::cout << tree1 << std::endl;


    Bst<int,char,std::less<int>> tree2{tree1};
    std::cout<< "provo a printare il secondo albero \n";
    std::cout << tree2 << std::endl;


    auto a = tree1.find(p3.first);
    //std::cout<<"\n FIND? "<< (*a).first<<" \n";
    std::cout<< "provo a printare il secondo albero \n";
    std::cout << tree2 << std::endl;
    std::cout<< "TESTO LE PARENTESI \n";
    auto k = tree2[3];
    std::cout<< "\n PARENTESI QUEDRE \n";
    std::cout << k << std::endl;


    k = tree2[17];
    std::cout<< "\n PARENTESI QUEDRE \n";
    std::cout << k << std::endl;

  std::cout<< "TESTO LE PARENTESI 2 \n";
    int bun=7;
    k = tree2[bun];
    std::cout<< "\n PARENTESI QUEDRE \n";
    std::cout << k << std::endl;

    bun= 17;

    k = tree2[bun];
    std::cout<< "\n PARENTESI QUEDRE \n";
    std::cout << k << std::endl;


    tree1.clear();
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