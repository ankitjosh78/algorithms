#include "BinaryTreeNode.h"
#include <iostream>

using namespace std;

class BST {
  BinaryTreeNode<int> *root;

private:
  bool hasData(int data, BinaryTreeNode<int> *node) {
    if (node == NULL) {
      return false;
    }
    if (node->data > data) {
      return hasData(data, node->left);
    } else {
      return hasData(data, node->right);
    }
  }

  BinaryTreeNode<int> *insertData(int data, BinaryTreeNode<int> *node) {
    if (node == NULL) {
      BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
      return newNode;
    } else if (data < node->data) {
      insertData(data, node->left);
    } else {
      insertData(data, node->right);
    }
    return node;
  }

  BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node) {
    if (node == NULL) {
      return NULL;
    }
    if (node->data > data) {
      node->left = deleteData(data, node->left);
      return node;
    } else if (node->data < data) {
      node->right = deleteData(data, node->right);
      return node;
    } else {
      if (node->left == NULL && node->right == NULL) {
        delete node;
        return NULL;
      } else if (node->left == NULL) {
        BinaryTreeNode<int> *temp = node->right;
        delete node;
        return temp;
      } else if (node->right == NULL) {
        BinaryTreeNode<int> *temp = node->left;
        delete node;
        return temp;
      } else {
        BinaryTreeNode<int> *replacement = node->right;
        while (replacement->left != NULL) {
          replacement = replacement->left;
        }
        int rightMin = replacement->data;
        node->data = rightMin;
        node->right = deleteData(rightMin, node->right);
        return node;
      }
    }
    return node;
  }

public:
  BST() { root = NULL; }
  ~BST() { delete root; }

  void insert(int data) { this->root = insertData(data, this->root); }

  void deleteData(int data) { deleteData(data, this->root); }

  bool hasData(int data) {
    if (root->data == data) {
      return true;
    } else if (root->data > data) {
      return hasData(data, root->left);
    } else {
      return hasData(data, root->right);
    }
  }
};
