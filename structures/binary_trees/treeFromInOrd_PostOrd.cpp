#include "BinaryTreeNode.h"
#include <iostream>
#include <queue>
#include <vector>

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

BinaryTreeNode<int> *buildTreeHelper(vector<int> &inorder,
                                     vector<int> &postorder, int ioS, int ioE,
                                     int poS, int poE) {
  if (ioS > ioE) {
    return NULL;
  }
  int rootData = postorder.at(poE);
  int rootIndex = -1;

  for (int i = ioS; i <= ioE; i++) {
    if (inorder.at(i) == rootData) {
      rootIndex = i;
      break;
    }
  }

  // left sub tree
  int lioS = ioS;
  int lioE = rootIndex - 1;
  int lpoS = poS;
  int lpoE = lioE - lioS + lpoS;

  // right sub tree
  int rioS = rootIndex + 1;
  int rioE = ioE;
  int rpoS = lpoE + 1;
  int rpoE = poE - 1;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  root->left = buildTreeHelper(inorder, postorder, lioS, lioE, lpoS, lpoE);
  root->right = buildTreeHelper(inorder, postorder, rioS, rioE, rpoS, rpoE);
  return root;
}

BinaryTreeNode<int> *buildTree(vector<int> &inorder, vector<int> &postorder,
                               int size) {
  return buildTreeHelper(inorder, postorder, 0, size - 1, 0, size - 1);
}
int main() {
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
  vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
  BinaryTreeNode<int> *root = buildTree(inorder, postorder, 7);
  printBinaryTreeLevelWise(root);
}
