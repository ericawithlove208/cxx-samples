#include <iostream>
#include <fstream>
#include <exception>

#include "Node.h"
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
  BalancedTree<int> btree;

  cout << "Reading keys" << endl;
  readFile(keyFileName, btree);
  cout << "Done reading file" << endl;

  cout << "Printing tree" << endl;
  btree.print();
  cout << "Done printing tree" << endl;
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
