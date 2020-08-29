#pragma once

using namespace std;

namespace ericawithlove208 { namespace cxxSamples { namespace balancedTree {

template <class T> class Node {
  public:
    Node(Node* parent, const T key) { 
      this->parent = parent;
      left = NULL;
      right = NULL;      

      this->key = key;
      bal = 0;
    }

    bool operator<(const Node<T>& val) const {
      return compare(val) < 0;
    }

    bool operator>(const Node<T>& val) const {
      return compare(val) > 0;
    }

    bool operator<=(const Node<T>& val) const {
      return compare(val) <= 0;
    }

    bool operator>=(const Node<T>& val) const {
      return compare(val) >= 0;
    }

    bool operator==(const Node<T>& val) const {
      return compare(val) == 0;
    }

    const int compare(const Node<T>* val) const {
      if (key < val->getKey()) {
        return -1;

      } else if (key > val->getKey()) {
        return 1;
      }

      return 0;
    }

    Node<T>* getParent() const {
      return parent;
    }
    void setParent(const Node<T>* val) {
      parent = val;
    }

    Node<T>* getLeft() const {
      return left;
    }
    void setLeft(Node<T>* val) {
      left = val;
    }

    Node<T>* getRight() const {
      return right;
    }
    void setRight(Node<T>* val) {
      right = val;
    }

    const T getKey() const {
      return key;
    }
    void setKey(const T val) {
      key = val;
    }

    const char getBal() const {
      return bal;
    }
    void setBal(const char val) {
      bal = val;
    }

  private:
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;

    T key;
    char bal;
};

} } }
