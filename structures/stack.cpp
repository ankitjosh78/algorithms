#include <climits>
#include <iostream>
#include <iterator>
using namespace std;

template <typename T> class Stack {
  int nextIndex;
  int capacity;
  T *elements;

public:
  Stack(int size) {
    capacity = size;
    nextIndex = 0;
    elements = new T[size];
  }
  void push(T data) {
    if (nextIndex == capacity) {
      cout << "Stack is full." << endl;
    } else {
      elements[nextIndex] = data;
      nextIndex++;
    }
  }
  void pop() {
    if (nextIndex == 0) {
      cout << "Stack is empty." << endl;
    } else {
      nextIndex--;
      cout << "Element:" << elements[nextIndex] << " popped out." << endl;
    }
  }
  void top() {
    if (nextIndex == 0) {
      cout << "Stack is empty." << endl;
      return;
    }
    cout << "Top element is:" << elements[nextIndex - 1] << endl;
  }
  int size() { return nextIndex; }
};

int main() {
  Stack<int> s(3);
  while (1) {
    cout << "Enter 1 for push:" << endl;
    cout << "Enter 2 for pop:" << endl;
    cout << "Enter 3 for top:" << endl;
    cout << "Enter 4 for exit:" << endl;
    int choice;
    cin >> choice;
    if (choice == 4) {
      break;
    }
    if (choice == 1) {
      cout << "Enter data:" << endl;
      int data;
      cin >> data;
      s.push(data);
    }
    if (choice == 2) {
      s.pop();
    }
    if (choice == 3) {
      s.top();
    }
  }
}
