#pragma once

#include "Node.h"

namespace ericawithlove208 { namespace cxxSamples { namespace balancedTree {

template <typename T> class BalancedTree {
  public:
    BalancedTree() {
      root = NULL;
     }

    const bool insert(const T key) { }
    const bool remove(const T key) { }

    const int size() const { }

    void print() const { }

  private:
    Node<T>* root;
};

} } }
