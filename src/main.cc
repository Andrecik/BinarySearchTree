#include <iostream>
#include <memory>
#include <utility>
// #include "include/node.h"
// #include "include/iterator.h"
// #include "include/bst.h"
#include "bst.cc"
#include "include/ap_error.h"
#include <cstdlib>
#include <ctime>

void full_the_tree(Bst<int, char>& tree, size_t count){
  unsigned seed = time(0);
  srand(seed);
  for (size_t i = 0; i < count; i++)
  {
    tree.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
  }
}
//implementare un operatore custom
int main(){
  try {
  
// //caso 1
// //inizializzo un albero
// Bst<int, char> tree;
// //inserisco nodi (volendo con valori random)
// full_the_tree(tree,20);
// //printa l'albero
// std::cout<< tree <<" \n";

// // caso 2
// // inizializzo un albero
// Bst<int, char> tree1;
// // inserisco nodi
// full_the_tree(tree1,20);
// // printa l'albero
// std::cout<< tree1 <<" \n";
// // copia l'albero 
// Bst<int, char> tree2{tree1};
// // modifica il secondo albero
// full_the_tree(tree2, 1);
// // printa entrambi gli alberi
// std::cout<< tree1 <<" \n";
// std::cout<< tree2 <<" \n";

// // caso 3
// // inizializzo un albero
// Bst<int, char> tree1;
// // inserisco nodi
// full_the_tree(tree1, 1);
// // printa l'albero
// std::cout<< tree1 <<" \n";
// // muovi su di un altro albero

// // printa il secondo albero

// // caso 4
// // inizializzo un albero
// // inserisco nodi con emplace
// // printo l'albero

// caso 5
// inizializzo un albero
Bst<int, char> tree;
// inserisco nodi
full_the_tree(tree, 1);
// printo l'albero
std::cout<<tree<<" \n";
// eseguo clear
// printo l'albero
// inserisco nodi 
// printo l'albero

// caso 6
// inizializzo un albero
// inserisco nodi
// printo l'albero
// cerco un nodo specifico
// printo gli elementi del nodo

// caso 7
// inizializzo un albero
// inserisco nodi in maniera sbilanciata
// printo l'albero
// bilancio l'albero
// printo l'albero

// caso 8
// inizializzo un albero
// inserisco nodi
// printo l'albero
// cancello un nodo 
// printo l'albero

// caso 10
// inizializzo un albero
// inserisco nodi
// printo l'albero
// accedo ad un nodo con []
// modifico il nodo
// printo l'albero
// inserisco un nodo senza value
// accedo al nodo con []
// printo il value di quel nodo
// printo l'albero






    // Bst<int,char> tree;
    // std::pair<int,char> p1{10,'b'};
    // std::pair<int,char> p2{8,'c'};
    // std::pair<int,char> p3{7,'d'};
    // std::pair<int,char> p4{2,'f'};
    // std::pair<int,char> p5{1,'z'};
    // std::pair<int,char> p6{3,'y'};
    // std::pair<int,char> p7{4,'b'};
    // std::pair<int,char> p8{15,'t'};
    // std::pair<int,char> p9{14,'r'};
    // std::pair<int,char> p10{17,'s'};
    // std::pair<int,char> p11{13,'l'};
    // std::pair<int,char> p12{22,'m'};
    // std::pair<int,char> p13{11,'n'};
    // std::pair<int,char> p14{19,'u'};
    // std::pair<int,char> p15{16,'x'};
    // tree.insert(p1);
    // tree.insert(p2);
    // tree.insert(p3);
    // tree.insert(p4);
    // tree.insert(p5);
    // tree.insert(p6);
    // tree.insert(p7);
    // tree.insert(p8);
    // tree.insert(p9);
    // tree.insert(p10);
    // tree.insert(p11);
    // tree.insert(p12);
    // tree.insert(p13);
    // tree.insert(p14);
    // tree.insert(p15);
    // std::cout<<tree<<std::endl;
    // tree.erase(17);
    // std::cout<<tree<<std::endl;
    // auto a = tree.find(p12.first);
    // std::cout<<"\n FIND? "<< p12.first<< " " << (*a).first<<" \n";
    // a = tree.find(16);
    // std::cout<<"\n FIND? "<< 16 << " " << (*a).first<<" \n";

  //return 0;
  //   Bst<int,char,std::less<int>> tree1{std::less<int>()};
  //   std::cout << tree1 << std::endl; 
  //   //Bst<int,char,std::less<int>> tree2{tree1};
  //   std::cout<<"\n \nInserisco il primo nodo \n";
  //   auto i = tree1.insert(std::make_pair(3,'a'));

  //   std::cout << " \n provo vedere ";
  //   std::cout<<(*(i.first)).first<<std::endl;
  //   std::cout<<"\n \nInserisco il secondo nodo \n";
  //   i = tree1.insert(std::make_pair(3,'b'));

  //   std::cout << " \n provo vedere ";
  //   std::cout<<(*(i.first)).first<<std::endl;
  //   if (!i.second){
  //     std::cout<< "Already in the tree \n";

  //   }
  //   else{std::cout<< "insert \n";}
  //   std::cout<<"\n \nInserisco il terzo nodo \n";
  //   i = tree1.insert(std::make_pair(4,'b'));

  //   std::cout << " \n provo vedere ";
  //   std::cout<<(*(i.first)).first<<std::endl;
  //   if (!i.second){
  //     std::cout<< "Already in the tree \n";

  //   }
  //   else{std::cout<< "insert \n";}
  //       i = tree1.insert(std::make_pair(2,'c'));

  //   std::cout << " \n provo vedere ";
  //   std::cout<<(*(i.first)).first<<std::endl;
  //   if (!i.second){
  //     std::cout<< "Already in the tree \n";

  //   }
  //   else{std::cout<< "insert \n";}
  //   std::cout<<"\n \nInserisco il quarto nodo \n";
  //       i = tree1.insert(std::make_pair(5,'d'));

  //   std::cout << " \n provo vedere ";
  //   std::cout<<(*(i.first)).first<<std::endl;
  //   if (!i.second){
  //     std::cout<< "Already in the tree \n";

  //   }
  //   else{std::cout<< "insert \n";}
    
  //   tree1.tryfor();

  //   // const Bst<int,char,std::less<int>> tree2{std::less<int>()};

  //   //std::cout << *(tree2.end())

  //   std::cout<< "provo a printare \n";
  //   std::cout << tree1 << std::endl;
  //   i = tree1.emplace(8,'g');

  //   std::cout << " \n provo vedere ";
  //   std::cout<< " 8 " << std::endl;
  //   std::cout<<(*(i.first)).first<<std::endl;
  //   std::pair<const int, char> p2{1,'e'};
  //   std::pair<int, char> p3{7,'f'}; 
  //   i = tree1.insert(p2);
  //   std::cout << " \n provo vedere ";
  //   std::cout<<p2.first << " " << std::endl;
  //   std::cout<<(*(i.first)).first<<std::endl;



  //   i = tree1.insert(p3);
  //   std::cout << " \n provo vedere ";
  //   std::cout<<p3.first << " " << std::endl;
  //   std::cout<<(*(i.first)).first<<std::endl;
    
  //       std::cout<< "provo a printare 2\n";
  //       std::cout<<p2.first << " " << std::endl;
  //   std::cout << tree1 << std::endl;

  //   std::cout << " \n provo a bilanciare \n \n ";
    
  //   tree1.balance();
  //       std::cout<< "provo a printare 3 \n";
  //   std::cout << tree1 << std::endl;


  //   Bst<int,char,std::less<int>> tree2{tree1};
  //   std::cout<< "provo a printare il secondo albero \n";
  //   std::cout << tree2 << std::endl;


  //   auto a = tree1.find(p3.first);
  //   std::cout<<"\n FIND? "<< (*a).first<<" \n";
  //   std::cout<< "provo a printare il secondo albero \n";
  //   std::cout << tree2 << std::endl;
  //   std::cout<< "TESTO LE PARENTESI \n";
  //   auto k = tree2[3];
  //   std::cout<< "\n PARENTESI QUEDRE \n";
  //   std::cout << k << std::endl;


  //   k = tree2[17];
  //   std::cout<< "\n PARENTESI QUEDRE \n";
  //   std::cout << k << std::endl;

  // std::cout<< "TESTO LE PARENTESI 2 \n";
  //   int bun=7;
  //   k = tree2[bun];
  //   std::cout<< "\n PARENTESI QUEDRE \n";
  //   std::cout << k << std::endl;

  //   bun= 17;

  //   k = tree2[bun];
  //   std::cout<< "\n PARENTESI QUEDRE \n";
  //   std::cout << k << std::endl;



  //   std::cout<< "provo a printare il primo albero \n";
  //   std::cout << tree1 << std::endl;
  //   tree1.erase(p3.first);
  //   std::cout<< "provo a printare il primo albero \n";
  //   std::cout << tree1 << std::endl;


  //   std::cout<< "provo a printare il secondo albero \n";
  //   std::cout << tree2 << std::endl;

  //   tree1.clear();
  //   std::cout<< "provo a printare il secondo albero \n";
  //   std::cout << tree2 << std::endl;


    return 0;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

  
  
    return 0;
}