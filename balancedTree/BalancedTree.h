#pragma once

#include <iostream>
#include <exception>

#include "Node.h"
#include "Comparator.h"

namespace ericawithlove208 { namespace cxxSamples { namespace balancedTree {

template <typename T> class BalancedTree {
  public:
    BalancedTree(const Comparator<T>& cmp) {
      this->cmp = cmp;

      root = NULL;
      _size = 0;
     }

    const bool insert(const T key) {
      Node<T>* node = find(key);

      if (node == NULL) {
        if (root != NULL) {
          throw exception(/*"BalancedTree::insert invalid tree"*/);
        }

        #ifdef trace
          cout << "BalancedTree::insert adding root key " << key << endl;
        #endif

        root = new Node<T>(NULL /* parent */, key);
        return true;
      }

      if (cmp.compare(node->getKey(), key) == 0) {
        return false;
      }

      #ifdef trace
        cout << "BalancedTree::insert adding key " << key << endl;
      #endif

      Node<T>* newNode = new Node<T>(node, key);
      if (cmp.compare(key, node->getKey()) < 0) {
        node->setLeft(newNode);
        return true;
      }

      node->setRight(newNode);
      return true;
    }

    const bool containsKey(const T key) {
      Node<T>* node = find(key);
      if ((node != NULL) && (node->getKey() == key)) {
        return true;
      }

      return false;
    }

    const bool remove(const T key) {
      return true;
    }

    const int size() const {
      return _size;
    }

    void print() const {
      print(root);
    }

  protected:
    Node<T>* find(const T key) {
      return walk(root, key);
    }

    Node<T>* walk(Node<T>* cur, const T key) {
      if (cur == NULL) {
        return cur;
      }

      if (cmp.compare(cur->getKey(), key) == 0) {
        return cur;
      }

      if (cmp.compare(key, cur->getKey()) < 0) {
        if (cur->getLeft() == NULL) {
          return cur;
        }
        return walk(cur->getLeft(), key);
      }

      if (cur->getRight() == NULL) {
        return cur;
      }
      return walk(cur->getRight(), key);
    }

    void print(const Node<T>* node) const {
      if (node == NULL) {
        return;
      }

      if (node->getLeft() != NULL) {
        print(node->getLeft());
      }

      cout << node->getKey() << endl;

      if (node->getRight() != NULL) {
        print(node->getRight());
      }
    }

  private:
    Comparator<T> cmp;

    Node<T>* root;
    int _size;
};

} } }
