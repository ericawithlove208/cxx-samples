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
      if (containsKey(key) == true) {
        return false;
      }

      Node<T>* node = find(key, true /* update */);

      if (node == NULL) {
        if (root != NULL) {
          throw exception(/*"BalancedTree::insert invalid tree"*/);
        }

        #ifdef TRACE
          cout << "BalancedTree::insert adding root key " << key << endl;
        #endif

        root = new Node<T>(NULL /* parent */, key);
        root->setBalance(0);

        return true;
      }

      if (cmp.compare(node->getKey(), key) == 0) {
        throw exception(/*"BalancedTree::insert concurrency"*/);
      }

      #ifdef TRACE
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
      Node<T>* node = find(key, false /* update */);
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

    void printOrdered() const {
      printOrdered(root);
    }

    void printTopDown() const {
      if (root == NULL) {
        return;
      }

      int max = (root->getLeftHeight() >= root->getRightHeight()) ? 
        root->getLeftHeight() : root->getRightHeight();

      for(int x = 0; x < max; x++) {
        cout << "Depth " << x << " ";
        printDepth(root, x);
      }
    }

  protected:
    Node<T>* find(const T key, bool update) {
      return walk(root, key, update);
    }

    Node<T>* walk(Node<T>* cur, const T key, bool update) {
      if (cur == NULL) {
        return cur;
      }

      if (cmp.compare(cur->getKey(), key) == 0) {
        return cur;
      }

      if (cmp.compare(key, cur->getKey()) < 0) {
        if (update == true) {
          #ifdef TRACE
            cur->setLeftHeight(cur->getLeftHeight() + 1);
            cur->setBalance(cur->getLeftHeight() - cur->getRightHeight());
          #else
            cur->setBalance(cur->getBalance() - 1);
          #endif
        }

        if (cur->getLeft() == NULL) {
          return cur;
        }
        return walk(cur->getLeft(), key, update);
      }

      if (update == true) {
        #ifdef TRACE
          cur->setRightHeight(cur->getRightHeight() + 1);
          cur->setBalance(cur->getLeftHeight() - cur->getRightHeight());
        #else
          cur->setBalance(cur->getBalance() + 1);
        #endif
      }

      if (cur->getRight() == NULL) {
        return cur;
      }
      return walk(cur->getRight(), key, update);
    }

    void printOrdered(const Node<T>* node) const {
      if (node == NULL) {
        return;
      }

      if (node->getLeft() != NULL) {
        printOrdered(node->getLeft());
      }

      cout << node->getKey() << endl;

      if (node->getRight() != NULL) {
        printOrdered(node->getRight());
      }
    }

    void printDepth(Node<T>* node, int depth) const {
      if (node == NULL) {
        return;
      }

      if (depth == 0) {
        #ifdef TRACE
          cout << "Key " << node->getKey() << " Bal " << ((int)node->getBalance())
               << " LH " << node->getLeftHeight() << " RH " << node->getRightHeight() << endl;
        #else
          cout << "Key " << node->getKey() << " Bal " << node->getBalance() << endl;
        #endif

        return;
      }

      printDepth(node->getLeft(), depth - 1);
      printDepth(node->getRight(), depth - 1);
    }

  private:
    Comparator<T> cmp;

    Node<T>* root;
    int _size;
};

} } }
