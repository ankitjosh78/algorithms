#include "BinaryTreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

void printBinaryTreeLevelWise(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    BinaryTreeNode<int> *currentNode = pendingNodes.front();
    cout << endl;
    cout << currentNode->data << ":";
    pendingNodes.pop();
    if (currentNode->left) {
      cout << "L" << currentNode->left->data << " ";
      pendingNodes.push(currentNode->left);
    }
    if (currentNode->right) {
      cout << "R" << currentNode->right->data << endl;
      pendingNodes.push(currentNode->right);
    }
  }
}

BinaryTreeNode<int> *takeInputLevelWise() {
  int rootData;
  cout << "Enter root data:" << endl;
  cin >> rootData;
  if (rootData == -1) {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    BinaryTreeNode<int> *currentNode = pendingNodes.front();
    pendingNodes.pop();
    int leftChildData;
    cout << "Enter left child of:" << currentNode->data << endl;
    cin >> leftChildData;
    if (leftChildData != -1) {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
      currentNode->left = child;
      pendingNodes.push(child);
    }
    int rightChildData;
    cout << "Enter right child of:" << currentNode->data << endl;
    cin >> rightChildData;
    if (rightChildData != -1) {
      BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
      currentNode->right = child;
      pendingNodes.push(child);
    }
  }
  return root;
}

int numNodes(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return 0;
  return 1 + numNodes(root->left) + numNodes(root->right);
}

int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise();
  printBinaryTreeLevelWise(root);
  cout << "Number of nodes is:" << numNodes(root) << endl;
}
