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

      #ifdef TRACE
        lh = 0;
        rh = 0;
      #endif
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

    const char getBalance() const {
      return bal;
    }
    void setBalance(const char val) {
      bal = val;
    }

    #ifdef TRACE
      const int getLeftHeight() const {
        return lh;
      }

      void setLeftHeight(const int val) {
        lh = val;
      }

      const int getRightHeight() const {
        return rh;
      }

      void setRightHeight(const int val) {
        rh = val;
      }
    #endif

  private:
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;

    T key;
    char bal;

    #ifdef TRACE
      int lh;
      int rh;
    #endif
};

} } }
