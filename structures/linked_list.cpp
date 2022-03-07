#include <bits/stdc++.h>

using namespace std;

// Creating node structure
struct node {
  int data;
  node *next;
};

// Creating linked list class
class linked_list {
public:
  node *head, *tail;
  // Default constructor assigning head and tail as NULL
  linked_list() {
    head = NULL;
    tail = NULL;
  }

  // Function to add a new node to our list
  void add_node(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;

    // When head is empty, the first node will be both the head and tail
    if (head == NULL) {
      head = temp;
      tail = temp;
    }
    // Other times, we will connect the previous tail to the new node and make
    // the new node our tail
    else {
      tail->next = temp;
      tail = tail->next;
    }
  }

  // Function to delete a node from our list
  void delete_node(int value) {
    node *temp = new node;
    temp = head;

    // When our value is the head node itself
    if (value == head->data) {
      head = head->next;
    }
    // Other times when the value is something else
    else {
      while (temp->next != NULL) {
        if (temp->next->data == value) {

          // If the value is the tail node, then we reassign tail to the
          // previous node.
          if (temp->next->data == tail->data) {
            tail = temp;
          }
          temp->next = temp->next->next;
          return;
        }
        temp = temp->next;
      }
    }
  }

  // Function to search a node from our list
  int search_node(int value) {
    node *temp = new node;
    temp = head;

    int position = 1;
    if (value == head->data) {
      return position;
    } else {
      while (temp->next != NULL) {
        position++;
        if (temp->next->data == value) {
          return position;
        }
        temp = temp->next;
      }
    }
    return -1;
  }
  // Function to get the head
  node get_head() { return *head; }
  // Function to get the tail
  node get_tail() { return *tail; }
};

int main() {
  linked_list L;
  L.add_node(1);
  // the head and tail is both node 1
  L.add_node(2);
  // the head is node 1, while tail is node 2
  L.add_node(3);
  // the head is node 1, while tail is node 3

  cout << "Initially...." << endl;
  cout << "Head is:" << L.get_head().data << " Tail is:" << L.get_tail().data
       << endl; // Head is:1 Tail is:3

  L.delete_node(1);
  cout << "After deleting node 1, current Head is:" << L.get_head().data
       << endl; // After deleting node 1, current Head is:2

  L.delete_node(3);
  cout << "After deleting node 2, current Tail is:" << L.get_tail().data
       << endl; // After deleting node 3, current Tail is:2

  cout << "Node 2 is at position:" << L.search_node(2)
       << " and Node 1 is at position:"
       << L.search_node(
              1); // Node 2 is at position:1 and Node 1 is at position:-1
  return 0;
}
