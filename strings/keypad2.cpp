#include <iostream>
#include <vector>
using namespace std;

vector<string> keys = {"",    "NULL", "abc",  "def", "ghi",
                       "jkl", "mno",  "pqrs", "tuv", "wxyz"};
void keyPad(int input, string output) {
  int currentDigit = input % 10;
  if (input == 0) {
    cout << output << endl;
    return;
  }
  for (char ch : keys[currentDigit]) {
    keyPad(input / 10, ch + output);
  }
}

int main() {
  int input;
  cin >> input;
  keyPad(input, "");
  return 0;
}
