#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <map>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "bst.cc"
#include "include/ap_error.h"

bool custom_func(const int &a, const int &b){
    if (a>b){return true;}
    else{return false;}
}
using FunctionPtr = auto (*)(const int&, const int&) -> bool;

void fill_the_tree(Bst<int, char>& tree, const std::size_t count, unsigned seed){
    srand(seed);
    for (std::size_t i = 0; i < count; i++)
    {
        tree.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
    }
}
void fill_the_tree(Bst<int, char, FunctionPtr>& tree, const std::size_t count, unsigned seed){
    srand(seed);
    for (std::size_t i = 0; i < count; i++)
    {
        tree.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
    }
}
void fill_the_map(std::map<int,char>& m, const std::size_t count, unsigned seed){
    srand(seed);
    for (std::size_t i = 0; i < count; i++)
    {
        m.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
    }
}

int main(int argc, char**argv){




  try {
    int choice;
    bool get_out= true;
    unsigned seed = time(0);
    std::size_t count{100};

    if(argc > 1){
      choice = 10;
      get_out = false;
      count = std::stoi(argv[1]);
      seed = std::stoi(argv[2]);
    }


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
    std::cout<<"10 - Benchmarking walltime\n";
    std::cout<<"11 - print tests descriptions\n";
    std::cout<<"12 - Exit \n \n";
    std::cout<<"Enter your choice and press return :  \n \n";      

    std::cin >> choice;

    if (choice == 12)
    {
        exit(0);
    }
    else if(choice == 1) 
    {
        FunctionPtr operation = custom_func;
        std::cout<<"Test 1 \nwe create a tree and we print it \n \n";
        //inizializzo un albero
        Bst<int, char, FunctionPtr> tree(operation);
        //inserisco nodi (volendo con valori random)
        fill_the_tree(tree,count,seed);
        //printa l'albero
        std::cout << "Printing the tree\n \n";
        std::cout << tree << std::endl;

    }
    else if(choice == 2) 
    {   std::cout<<"Test 2 \nwe create a tree and we print it \n \n";
        // inizializzo un albero
        Bst<int, char> tree1;
        // inserisco nodi
        fill_the_tree(tree1,count,seed);
        // printa l'albero
        std::cout<< tree1 <<" \n \n";
        std::cout<<"Then we copy tree1 into tree 2 \n \n we insert a new node into tree2 and then we print both\n \n";

        // copia l'albero 
        Bst<int, char> tree2{tree1};

        // modifica il secondo albero
        std::cout << "inserting another node on the copy tree\n \n";
        fill_the_tree(tree2, 1, 42);
        // printa entrambi gli alberi
        std::cout << "printing both trees\n \n";
        std::cout<< tree1 <<" \n \n";
        std::cout<< tree2 <<" \n \n";

    }
    else if(choice == 3) 
    {   std::cout<<"Test 3 \nwe create a tree and we print it \n";
        // caso 3
        // inizializzo un albero
        Bst<int, char> tree1;
        // inserisco nodi
        fill_the_tree(tree1,count,seed);
        // printa l'albero
        std::cout<< tree1 <<" \n \n";
        std::cout<<"Then we move tree1 into tree2 \nwe insert a new node into tree2 and then we print both";
        // muovi su di un altro albero
        Bst<int, char> tree2 = std::move(tree1);
        // printa il secondo albero
        std::cout<< tree2 <<" \n \n";

    }
    else if(choice == 4) 
    {
        //caso 4
        // inizializzo un albero
        std::cout<<"Test 4 \nwe create a tree and we print it\n\n";
        Bst<int, char> tree;
        fill_the_tree(tree,count,seed);
        std::cout<< tree <<" \n \n";
        // inserisco nodi con emplace
        std::cout<<"we use emplace and we print the tree\n";
        tree.emplace(42,'b');
        // printo l'albero
        std::cout<< tree <<" \n \n";
    }
    else if(choice == 5) 
    {
        // caso 5
        // inizializzo un albero
        std::cout << "Test 5 \nwe create a tree and we print it\n\n";
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree,count,seed);
        // printo l'albero
        std::cout<<tree<<"\n\n";
        // eseguo clear
        std::cout << "Clearing the tree\n\n";
        tree.clear();
        // printo l'albero
        std::cout <<"Trying to print it again\n\n";
        std::cout<<tree<< "\n\n";
        // inserisco nodi
        std::cout << "Filling the tree again\n\n"; 
        fill_the_tree(tree,count, 56);
        // printo l'albero
        std::cout << "Printing the tree\n\n";
        std::cout<<tree<< "\n\n";
    }
        else if(choice == 6) 
    {   
      std::cout << "Test 6 \nwe create a tree and we print it\n\n";
      // inizializzo un albero
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree,count,seed);
        // printo l'albero
        std::cout<<tree<<" \n";
        std::cout << "Inserting node {42,'b'}\n\n";
        tree.emplace(42,'b');
        // cerco un nodo che c'è
        std::cout << "Looking for that node using find() method\n\n";
        auto i = tree.find(42);
        std::cout << "Accessing to the node using the returned iterator\n\n";
        std::cout << "key: " << (*i).first << " value: " << (*i).second << "\n\n";;
        //cerco un nodo a caso
        std::cout << "Looking for a node with key 182 which is not present in the tree\n\n";
        tree.find(182);
    }
        else if(choice == 7) 
    {
        std::cout << "Test 7 \nWe create an unbalanced tree and we print it\n\n";
        Bst<int, char> tree;
        // inserisco nodi in maniera sbilanciata
        fill_the_tree(tree,count,seed);
        // printo l'albero
        std::cout<<tree<<"\n\n";
        std::cout << "Balancing the tree\n\n";
        tree.balance();
        // bilancio l'albero
        std::cout << "Printing the tree again\n\n";
        std::cout<<tree<<"\n\n";
        // printo l'albero
    }
        else if(choice == 8) 
    {   
        std::cout << "Test 8 \nWe create a tree and we print it\n\n";
        // inizializzo un albero
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree,count,seed);
        std::cout<<tree<<"\n\n";
        std::cout << "Inserting node {42,'c'}\n\n";
        tree.emplace(42,'c');
        //fill_the_tree(tree,count, 42);
        std::cout << "Printing the tree\n\n";
        std::cout<<tree<<"\n\n";
        // inserisco nodi
        // printo l'albero
        // cancello un nodo
        std::cout << "Now erasing the node {42,'c'} from the tree\n\n";
        tree.erase(42);
        // printo l'albero
        std::cout << "Printing the tree again\n\n";
        std::cout<<tree<<"\n\n";
    }
        else if(choice == 9) 
    {
        std::cout << "Test 9 \nWe create a tree and we print it\n\n";
        Bst<int, char> tree;
        // inserisco nodi
        fill_the_tree(tree,count, 42);
        std::cout<<tree<<"\n\n";
        // accedo ad un nodo con []
        std::cout << "Inserting node {42,'c'}\n\n";
        tree.emplace(42,'c');
        std::cout << "Accessing to the node using subscripting operator []\n\n";
        std::cout<< tree[42] << "\n\n";
        // modifico il nodo
        std::cout << "Modifying the node\n\n";
        tree[42]='f';
        std::cout << "Accessing again to the node\n\n";
        std::cout<< tree[42] << "\n\n";
        // printo l'albero
        std::cout << "Printing again the tree\n\n";
        std::cout<<tree<<" \n";
        // inserisco un nodo senza value
        std::cout << "Accessing to a node with key 180 which isn't present in the tree\n"
                  << "this will insert a new empty node with that key\n\n";
        std::cout<< tree[180] << "\n\n";
        //a = tree.emplace(182,' ');
        // accedo al nodo con []
        std::cout << "Accessing again to that node to see if it's empty\n\n";
        std::cout<< tree[180] << "\n\n";
        // printo il value di quel nodo
        // printo l'albero

    }
        else if(choice == 10) 
    {
        std::cout << "Test 10\nBenchmarking walltime\n\n";

        Bst<int, char> tree;
        std::map<int,char> testing_map;
        srand(seed);

        auto bst_start_time = std::chrono::high_resolution_clock::now();
        auto bst_end_time = std::chrono::high_resolution_clock::now();
        auto map_start_time = std::chrono::high_resolution_clock::now();
        auto map_end_time = std::chrono::high_resolution_clock::now();
      //##################################################
        std::cout << "##################################################\n\n";
        std::cout << "Testing element insertion time\n\n";

        for(std::size_t i = 0; i<count; ++i){
        bst_start_time = std::chrono::high_resolution_clock::now();
        tree.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
        bst_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count() << " ns " << i << "\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count()
        //<< " ns to insert " << test_count << " nodes using Bst.\n \n";

        for(std::size_t i = 0; i<count; ++i){
        map_start_time = std::chrono::high_resolution_clock::now();
        testing_map.insert(std::pair{rand() % 100 + 1,'a' + rand()%26});
        map_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() << " ns " << i << " \n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() 
        //<< " ns to insert " << test_count << " nodes using map.\n \n";

      //########################################
        std::cout << "##################################################\n\n";
        std::cout << "Testing copying time\n\n";

        bst_start_time = std::chrono::high_resolution_clock::now();
        Bst<int, char> tree2{tree};
        bst_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count() << " ns\n";

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count()
        //<< " ns to copy the tree using Bst.\n \n";


        map_start_time = std::chrono::high_resolution_clock::now();
        std::map<int,char> testing_map2{testing_map};
        map_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() << " ns\n";

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() 
        //<< " ns to copy a testing map using map.\n \n";

      //###################################################
        std::cout << "##################################################\n\n";
        std::cout << "Testing time to find an element\n\n";


        //std::cout << "Now looking for it\n\n";
        for(auto& x : tree){
        bst_start_time = std::chrono::high_resolution_clock::now();
        tree.find(x.first);
        bst_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count() << " ns\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count()
        //<< " ns to find the node using Bst.\n \n";


        //std::cout << "Now looking for it\n\n";
        for(auto& x : testing_map){
        map_start_time = std::chrono::high_resolution_clock::now();
        testing_map.find(x.first);
        map_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() << " ns\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() 
        //<< " ns to find the node using map.\n \n";

      //###################################################################################
        std::cout << "##################################################\n\n";
        std::cout << "Testing time to modify an element with subscripting operator []\n\n";

        //std::cout << "Modifying {42, 'c'} in the tree with the subscripting operator []\n\n";
        for(auto& x : tree){
        bst_start_time = std::chrono::high_resolution_clock::now();
        tree[x.first] = ' ';
        bst_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count() << " ns\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count()
        //<< " ns to modify the node using Bst.\n \n";


        //std::cout << "Modifying {42, 'c'} in the testing map with the subscripting operator []\n\n";
        for(auto& x : testing_map){
        map_start_time = std::chrono::high_resolution_clock::now();
        testing_map[x.first] = ' ';
        map_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() << " ns\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() 
        //<< " ns to modify the node using map.\n \n";

      //####################################################
        std::cout << "##################################################\n\n";
        std::cout << "Testing time to erase an element\n\n";

        //std::cout << "Erasing {42, 'c'} in the tree\n\n";
                std::vector<int> vec;
        for(auto& x : tree){
            vec.push_back(x.first);
        }
        for(std::size_t i=0; i<20; ++i){
        bst_start_time = std::chrono::high_resolution_clock::now();
        tree.erase(vec[rand() % vec.size() + 1]);
        bst_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count() << " ns\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(bst_end_time - bst_start_time).count()
        //<< " ns to erase the node using Bst.\n \n";
        vec.clear();
        for(auto& x : testing_map){
            vec.push_back(x.first);
        }
        //std::cout << "Erasing {42, 'c'} in the testing map\n\n";
        for(std::size_t i=0; i<20; ++i){
        map_start_time = std::chrono::high_resolution_clock::now();
        testing_map.erase(vec[rand() % vec.size() + 1]);
        map_end_time = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() << " ns\n";
        }

        //std::cout << "It took " 
        //<< std::chrono::duration_cast<std::chrono::nanoseconds>(map_end_time - map_start_time).count() 
        //<< " ns to erase the node using map.\n \n";

    }
        else if(choice == 11) 
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
        <<"print the tree \n"
        <<"\n \n"
        <<"Test 10 \n"
        <<"Benchmarking walltime\n"
        <<"with std::chrono\n"
        <<"comparing our Bst against std::map \n";
    }

    else
    {
        std::cout<<"Sorry choice not implemented yet\n \n" ;
        get_out=false;

    }

    } while (get_out == true);

  return 0;

  } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
  } catch (...) {
      std::cerr << "Unknown exception\n \n" << std::endl;
  }

    
    
  return 0;
}
