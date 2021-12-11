#include "include/bst.h"
#include "include/node.h"
#include "include/iterator.h"
#include "include/ap_error.h"

int main(){
  try {

    Bst<int,char> tree;

    return 0;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

    return 0;
}