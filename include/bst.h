#ifndef BST_H
#define BST_H

#include <functional>
#include <iostream>

class BST {
public:
  class Node {
  public:
    Node(int value, Node *left, Node *right);
    Node() {
      value = 0;
      left = nullptr;
      right = nullptr;
    }
    Node(const Node &node);

    int value;
    Node *left;
    Node *right;
    friend std::ostream &operator<<(std::ostream &os, const Node &n) {
      os << n.value << std::endl;
      if (n.left != nullptr) {
        std::cout << n.left << std::endl;
      }
      if (n.right != nullptr) {
        std::cout << n.right << std::endl;
      }
      return os;
    }
    bool operator<(const int &n) { return this->value < n; }
    friend bool operator<(int lv, const Node &n) { return lv < n.value; }
    bool operator>(const int &n) { return this->value > n; }
    friend bool operator>(int lv, const Node &n) { return lv > n.value; }
    bool operator>=(const int &n) { return this->value >= n; }
    friend bool operator>=(int lv, const Node &n) { return lv >= n.value; }
    bool operator<=(const int &n) { return this->value <= n; }
    friend bool operator<=(int lv, const Node &n) { return lv <= n.value; }
    bool operator==(const int &n) { return this->value == n; }
    friend bool operator==(int lv, const Node &n) { return lv == n.value; }
  };

  BST(std::initializer_list<int> list) : root(nullptr) {
    len = 0;
    for (int value : list) {
      add_node(value);
    }
  }

  Node *&get_root();
  void bfs(std::function<void(Node *&node)> func);
  size_t length();
  bool add_node(int value);
  Node **find_node(int value);
  Node **find_parrent(int value);
  Node **find_successor(int value);
  bool delete_node(int value);
  friend std::ostream &operator<<(std::ostream &os, const BST &n) {
    os << n.root << std::endl;
    return os;
  }
  BST &operator++() { return *this; }
  BST &operator++(int v) { return *this; }

private:
  Node *root;
  size_t len;
};

#endif // BST_H
