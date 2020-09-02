#include <iostream>
#include <fstream>
#include <exception>

#include "Node.h"
#include "Comparator.h"
#include "BalancedTree.h"

using namespace std;
using namespace ericawithlove208::cxxSamples::balancedTree;

void usage();
void readFile(const char*, BalancedTree<int>&); 

int main(int argc, const char** argv) {
  if (argc != 2) {
    usage();
    return 0;
  }

  const char* keyFileName = argv[1];

  Comparator<int> cmp;
  BalancedTree<int> btree(cmp);

  cout << "Reading keys" << endl;
  readFile(keyFileName, btree);
  cout << "Done reading file" << endl;

  cout << "Printing tree ordered" << endl;
  btree.printOrdered();
  cout << "Done printing tree ordered" << endl;

  cout << "\nPrinting tree top down" << endl;
  btree.printTopDown();
  cout << "Done printing top down" << endl;
}

void readFile(const char* keyFileName, BalancedTree<int>& btree) {
  fstream file(keyFileName, ios_base::in);

  if (file.fail()) {
    cout << "Could not open " << keyFileName << endl;
    exit(1);
  }

  int val = 0;

  while (file >> val) {
    cout << "Inserting " << val << endl;
    bool ok = btree.insert(val);

    if (ok == false) {
      cout << "Could not insert " << val << endl;
    }
  }
}

void usage() {
  cout << "BalancedTree keyfile.txt" << endl;
}
