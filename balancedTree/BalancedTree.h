#pragma once

#include <exception>

#include "Node.h"

namespace ericawithlove208 { namespace cxxSamples { namespace balancedTree {

template <typename T> class BalancedTree {
  public:
    BalancedTree() {
      root = NULL;
      _size = 0;
     }

    const bool insert(const T key) {
      Node<T>* node = find(key);

      if (node == NULL) {
        if (root != NULL) {
          throw exception(/*"BalancedTree::insert invalid tree"*/);
        }

        root == new Node<T>(NULL /* parent */, key);
        return true;
      }

      if (node->getKey() == key) {
        return false;
      }

      Node<T>* newNode = new Node<T>(node, key);
      if (key < node->getKey()) {
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

    void print() const { }

  protected:
    Node<T>* find(const T key) {
      return walk(root, key);
    }

    Node<T>* walk(Node<T>* cur, const T key) {
      if (cur == NULL) {
        return cur;
      }

      if (cur->getKey() == key) {
        return cur;
      }

      if (key < cur->getKey()) {
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

  private:
    Node<T>* root;
    int _size;
};

} } }
