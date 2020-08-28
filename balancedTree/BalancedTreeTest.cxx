#include <iostream>

#include "Node.h"
#include "BalancedTree.h"

using namespace std;
using namespace ericawithlove208::cxxSamples::balancedTree;

void usage();

int main(int argc, const char** argv) {
  if (argc != 2) {
    usage();
    return 0;
  }

  const char* keyFileName = argv[1];

  BalancedTree<int> btree;


  btree.print();
}

void usage() {
  cout << "BalancedTree keyfile.txt" << endl;
}
