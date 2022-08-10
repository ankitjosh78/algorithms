#include <climits>
#include <iostream>
using namespace std;

<<<<<<< HEAD
template <typename T> class Stack {
  T *data;
=======
class Stack {
  int *data;
>>>>>>> 07943596e532ee836d6b888b5f9b8717c80c3d57
  int nextIndex;
  int capacity;

public:
<<<<<<< HEAD
  Stack(){this->data} T top() {}

  void pop() {}

  void push(T element) {}
=======
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
>>>>>>> 07943596e532ee836d6b888b5f9b8717c80c3d57
};
