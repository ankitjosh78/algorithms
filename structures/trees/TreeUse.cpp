#include "TreeNode.h"
#include <iostream>
#include <queue>

// Input
queue<TreeNode<int> *> q;

TreeNode<int> *takeInput(TreeNode<int> *node) {
  TreeNode<int> *root = new TreeNode<int>(0);
  if (node == NULL) {
    int data;
    cout << "Enter data for root node:" << endl;
    cin >> data;
    root->data = data;
    q.push(root);
    int n;
    cout << "Enter number of children of " << data << endl;
    cin >> n;
    q.pop();
    while (n--) {
      int childData;
      cout << "Enter data of child:" << endl;
      cin >> childData;
      TreeNode<int> *child = new TreeNode<int>(childData);
      q.push(child);
      root->children.push_back(child);
    }
    while (!q.empty()) {
      takeInput(q.front());
    }
  } else {
    while (!q.empty()) {
      int n;
      cout << "Enter number of children of:" << q.front()->data << endl;
      cin >> n;
      while (n--) {
        int childData;
        cout << "Enter data of child:" << endl;
        cin >> childData;
        TreeNode<int> *child = new TreeNode<int>(childData);
        q.push(child);
        q.front()->children.push_back(child);
      }
      q.pop();
    }
  }
  return root;
}

// PreOrder
void printTree(TreeNode<int> *root) {
  if (root == NULL)
    return;
  cout << root->data << ":";
  for (int i = 0; i < root->children.size(); i++) {
    cout << root->children[i]->data << " ";
  }
  cout << endl;
  for (int i = 0; i < root->children.size(); i++) {
    printTree(root->children[i]);
  }
}

void printTreeLevelWise(TreeNode<int> *root, queue<TreeNode<int> *> &q) {
  if (root == NULL)
    return;
  cout << root->data << " ";
  for (int i = 0; i < root->children.size(); i++) {
    q.push(root->children[i]);
  }
  while (q.size() != 0) {
    TreeNode<int> *child = q.front();
    q.pop();
    printTreeLevelWise(child, q);
  }
}

void postOrder(TreeNode<int> *root) {
  if (root == NULL)
    return;
  for (int i = 0; i < root->children.size(); i++) {
    postOrder(root->children[i]);
  }
  cout << root->data << " ";
}

// Number of Nodes
int numNodes(TreeNode<int> *root) {
  if (root == NULL) {
    return 0;
  }
  int ans = 1;
  for (int i = 0; i < root->children.size(); i++) {
    ans += numNodes(root->children[i]);
  }
  return ans;
}

// Sum of Nodes
int sumNodes(TreeNode<int> *root) {
  if (root == NULL) {
    return 0;
  }
  int ans = root->data;
  for (int i = 0; i < root->children.size(); i++) {
    ans += sumNodes(root->children[i]);
  }
  return ans;
}

void printAtLevelK(TreeNode<int> *root, int k) {
  if (root == NULL)
    return;
  if (k == 1)
    cout << root->data << " ";
  for (int i = 0; i < root->children.size(); i++) {
    printAtLevelK(root->children[i], k - 1);
  }
}

// Height of Tree
int heightTree(TreeNode<int> *root) {
  if (root == NULL) {
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < root->children.size(); i++) {
    ans = max(ans, heightTree(root->children[i]));
  }
  return ans + 1;
}

// Number of leaves
int countLeaf(TreeNode<int> *root) {
  if (root == NULL) {
    return 0;
  }
  if (root->children.size() == 0) {
    return 1;
  }
  int ans = 0;
  for (int i = 0; i < root->children.size(); i++) {
    ans += countLeaf(root->children[i]);
  }
  return ans;
}

void deleteTree(TreeNode<int> *root) {
  if (root == NULL)
    return;
  for (int i = 0; i < root->children.size(); i++) {
    deleteTree(root->children[i]);
  }
  delete root;
}

int main() {
  TreeNode<int> *root = takeInput(NULL);
  // printAtLevelK(root, 3);
  postOrder(root);
  // queue<TreeNode<int> *> temp;
  // printTreeLevelWise(root, temp);
  // cout << "Number of Nodes are:" << numNodes(root) << endl;
  //  cout << "Sum of Nodes are:" << sumNodes(root) << endl;
  // cout << "Height of tree is:" << heightTree(root) << endl;
  // cout << "Number of Leaf Nodes of tree is:" << countLeaf(root) << endl;
  deleteTree(root);
}
