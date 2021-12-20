#include "include/bst.h"
#include "include/node.h"
#include "include/iterator.h"

#include "include/ap_error.h"


int main(){
  try {

    Bst<int,char,std::less<int>> tree1;
    Bst<int,char,std::less<int>> tree2{tree1};
    auto i = tree1.insert(std::make_pair(3,'a'));
    
    std::cout<< tree1 << std::endl; 
    return 0;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

    return 0;
}