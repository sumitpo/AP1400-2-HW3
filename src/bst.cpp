#include "bst.h"
#include <queue>

BST::Node::Node(int value, BST::Node *left, BST::Node *right) {
  this->value = value;
  this->left = left;
  this->right = right;
}

BST::Node::Node(const BST::Node &node) {
  this->value = node.value;
  this->left = node.left;
  this->right = node.right;
}

BST::Node *&BST::get_root() { return root; }
bool BST::add_node(int value) {
  BST::Node **node_ptr = find_node(value);
  if (node_ptr != nullptr) {
    return false;
  }
  BST::Node *new_node_ptr = new BST::Node(value, nullptr, nullptr);
  if (root == nullptr) {
    root = new_node_ptr;
    len += 1;
    return true;
  }
  node_ptr = find_parrent(value);
  if ((*node_ptr)->value < value) {
    (*node_ptr)->right = new_node_ptr;
  } else {
    (*node_ptr)->left = new_node_ptr;
  }
  len += 1;
  return true;
}

BST::Node **BST::find_node(int value) {
  if (root == nullptr)
    return nullptr;
  if (root->value == value) {
    return &root;
  }
  BST::Node **curr = &root;
  while ((*curr) != nullptr) {
    if ((*curr)->value < value) {
      curr = &((*curr)->right);
    } else if ((*curr)->value == value) {
      return curr;
    } else {
      curr = &((*curr)->left);
    }
  }
  return nullptr;
}
BST::Node **BST::find_parrent(int value) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->value == value) {
    return &root;
  }
  BST::Node **par = &root, **curr = &root;
  while ((*curr) != nullptr) {
    if ((*curr)->value < value) {
      par = curr;
      curr = &((*curr)->right);
    } else if ((*curr)->value == value) {
      return par;
    } else {
      par = curr;
      curr = &((*curr)->left);
    }
  }
  return par;
}
BST::Node **BST::find_successor(int value) { return &root; }
bool BST::delete_node(int value) {
  BST::Node **node_ptr = find_node(value);
  if (nullptr == node_ptr) {
    return false;
  }
  BST::Node **par = find_parrent(value);
  BST::Node *node = *node_ptr;
  (*par)->left = node->left;
  delete node;
  *node_ptr = nullptr;
  len -= 1;
  return true;
}

void BST::bfs(std::function<void(BST::Node *&node)> func) {
  std::queue<BST::Node *> que;
  que.push(root);
  while (!que.empty()) {
    BST::Node *curr = que.front();
    que.pop();
    if (curr == nullptr) {
      continue;
    }
    func(curr);
    if (curr->left != nullptr) {
      que.push(curr->left);
    }
    if (curr->right != nullptr) {
      que.push(curr->right);
    }
  }
}

size_t BST::length() { return len; }
