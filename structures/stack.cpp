#include <climits>
#include <iostream>
using namespace std;

class Stack {
  int *data;
  int nextIndex;
  int capacity;

public:
  Stack(int totalSize) {
    data = new int[totalSize];
    nextIndex = 0;
    capacity = totalSize;
  }

  bool isEmpty() { return nextIndex == 0; }

  int size() { return nextIndex; }

  void push(int element) {
    if (nextIndex >= capacity) {
      cout << "Stack is full." << endl;
      return;
    }
    data[nextIndex] = element;
    nextIndex++;
  }

  int pop() {
    if (isEmpty()) {
      cout << "Stack is empty." << endl;
      return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
  }

  int top() {
    if (isEmpty()) {
      cout << "Stack is empty." << endl;
      return INT_MIN;
    }
    return data[nextIndex - 1];
  }
};
