#include "BinaryTreeNode.h"
#include <bits/stdc++.h>

using namespace std;

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

// try to find min, max, isBST all at once
vector<int> checkBST(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    vector<int> ans;
    ans.push_back(INT_MAX);
    ans.push_back(INT_MIN);
    ans.push_back(true);
    return ans;
  }
  vector<int> leftAns = checkBST(root->left);
  vector<int> rightAns = checkBST(root->right);
  int leftMin = leftAns[0];
  int leftMax = leftAns[1];
  bool leftBST = leftAns[2];
  int rightMin = rightAns[0];
  int rightMax = rightAns[1];
  bool rightBST = rightAns[2];

  vector<int> ans;
  ans.push_back(min(leftMin, min(root->data, rightMin)));
  ans.push_back(max(leftMax, max(root->data, rightMax)));
  ans.push_back(rightBST && leftBST && (root->data > leftMax) &&
                (root->data < rightMin));
  return ans;
}

vector<int> inorder;

void work(BinaryTreeNode<int> *root) {
  if (root == NULL) {
    return;
  }
  work(root->left);
  inorder.push_back(root->data);
  work(root->right);
}
int main() {
  BinaryTreeNode<int> *root = takeInputLevelWise();
  cout << (checkBST(root)[2] == 1 ? "True" : "False") << endl;
  work(root);
  for (auto x : inorder) {
    cout << x << " ";
  }
}
