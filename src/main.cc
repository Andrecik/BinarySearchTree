#include <iostream>
#include <memory>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "bst.cc"
#include "include/ap_error.h"


void fill_the_tree(Bst<int, char>& tree, size_t count, unsigned seed){
    srand(seed);
    for (size_t i = 0; i < count; i++)
    {
        tree.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
    }
    }

int main(){
    try {
    int choice;
    bool get_out= true;
    unsigned seed = time(0);
do
{
    
    std::cout<<"********************************************\n"; 
    std::cout<<"1 - Test 1 \n";
    std::cout<<"2 - Test 2 \n";
    std::cout<<"3 - Test 3 \n";
    std::cout<<"4 - Test 4 \n";
    std::cout<<"5 - Test 5 \n";
    std::cout<<"6 - Test 6 \n";
    std::cout<<"7 - Test 7 \n";
    std::cout<<"8 - Test 8 \n";
    std::cout<<"9 - Test 9 \n";
    std::cout<<"10 - print tests decriptions\n";
    std::cout<<"11 - Exit \n";
    std::cout<<"Enter your  choce and press return :  ";      

    std::cin >> choice;

    if (choice == 11)
    {
        exit(0);
    }
    else if(choice == 1) 
    {
        std::cout<<"Test 1 \nwe create a tree and we print it \n";
        //inizializzo un albero
        Bst<int, char> tree;
        //inserisco nodi (volendo con valori random)
        fill_the_tree(tree,20,seed);
        //printa l'albero
        std::cout<< tree <<" \n";

    }
    else if(choice == 2) 
    {   std::cout<<"Test 2 \nwe create a tree and we print it \n";
        // inizializzo un albero
        Bst<int, char> tree1;
        // inserisco nodi
        fill_the_tree(tree1,20,seed);
        // printa l'albero
        std::cout<< tree1 <<" \n";
        std::cout<<"Then we copy tree1 into tree 2 \nwe insert a new node into tree2 and then we print both";
        // copia l'albero 
        Bst<int, char> tree2{tree1};
        // modifica il secondo albero
        fill_the_tree(tree2, 1, 42);
        // printa entrambi gli alberi
        std::cout<< tree1 <<" \n";
        std::cout<< tree2 <<" \n";

    }
    else if(choice == 3) 
    {   std::cout<<"Test 3 \nwe create a tree and we print it \n";
        // caso 3
        // inizializzo un albero
        Bst<int, char> tree1;
        // inserisco nodi
        fill_the_tree(tree1, 20,seed);
        // printa l'albero
        std::cout<< tree1 <<" \n";
        std::cout<<"Then we move tree1 into tree2 \nwe insert a new node into tree2 and then we print both";
        // muovi su di un altro albero
        Bst<int, char> tree2 = std::move(tree1);
        // printa il secondo albero
        std::cout<< tree2 <<" \n";

    }
    else if(choice == 4) 
    {
        //caso 4
        // inizializzo un albero
        std::cout<<"Test 4 \nwe create a tree and we print it \n";
        Bst<int, char> tree;
        fill_the_tree(tree, 20,seed);
        std::cout<< tree <<" \n";
        // inserisco nodi con emplace
        std::cout<<"we use emplace and we print the tree\n";
        tree.emplace(42,'b');
        // printo l'albero
        std::cout<< tree <<" \n";
    }
    else if(choice == 5) 
    {
        // caso 5
        // inizializzo un albero
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree, 20,seed);
        // printo l'albero
        std::cout<<tree<<" \n";
        // eseguo clear
        tree.clear();
        // printo l'albero
        std::cout<<tree<< " \n";
        // inserisco nodi 
        fill_the_tree(tree, 20, 56);
        // printo l'albero
        std::cout<<tree<< " \n";

    }
        else if(choice == 6) 
    {   // inizializzo un albero
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree, 20,seed);
        // printo l'albero
        std::cout<<tree<<" \n";
        tree.emplace(42,'b');
        // cerco un nodo che c'è
        tree.find(42);
        tree[42];
        //cerco un nodo a caso
        tree.find(82);
        tree[82];
    }
        else if(choice == 7) 
    {
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree, 20,seed);
        // inserisco nodi in maniera sbilanciata
        // printo l'albero
        std::cout<<tree<<" \n";
        tree.balance();
        // bilancio l'albero
        std::cout<<tree<<" \n";
        // printo l'albero
    }
        else if(choice == 8) 
    {   
        // inizializzo un albero
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree, 10,seed);
        // inserisco nodi in maniera sbilanciata
        // printo l'albero
        tree.emplace(42,'c');
        fill_the_tree(tree, 10, 42);
        std::cout<<tree<<" \n";
        // inserisco nodi
        // printo l'albero
        // cancello un nodo
        tree.erase(42);
        // printo l'albero
        std::cout<<tree<<" \n";
    }
        else if(choice == 9) 
    {
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree, 20, 42);
        std::cout<<tree<<" \n";
        // accedo ad un nodo con []
        auto a = tree.emplace(42,'c');
        std::cout<< tree[42] << " \n";
        // modifico il nodo
        tree[42]='f';
        std::cout<< tree[42] << " \n";
        // printo l'albero
        std::cout<<tree<<" \n";
        // inserisco un nodo senza value
        std::cout<< tree[180] << " \n";
        // accedo al nodo con []
        a = tree.emplace(182,' ');
        std::cout<< tree[182] << " \n";
        // printo il value di quel nodo
        // printo l'albero

    }
        else if(choice == 10) 
    {   
        std::cout<<"Test 1 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 2 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"copy the tree \n"
        <<"modify the second tree \n"
        <<"print both trees \n"
        <<"\n \n"
        <<"Test 3 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"move the tre into a second tree \n"
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 4 \n"
        <<"initialize a tree \n"
        <<"use emplace \n"
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 5 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"use clear"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 6 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"find a specific node \n"
        <<"print the node element \n"
        <<"\n \n"
        <<"Test 7 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"balance the tree \n"
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 8 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"erase the node \n"
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 9 \n"
        <<"initialize a tree \n"
        <<"insert nodes \n"
        <<"print the tree \n"
        <<"access a node with square bracket \n"
        <<"modify the node \n"
        <<"print the tree \n"
        <<"print the tree \n";
        }

    else
    {
        std::cout<<"Sorry choice not implemented yet\n" ;
        get_out=false;

    }

} while (get_out == true);

    return 0;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception" << std::endl;
    }

    
    
        return 0;
}
