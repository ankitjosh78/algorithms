#include <iostream>
using namespace std;

int subsequenceSize(string input, string outputStrings[]);

int main() {
  cout << "Enter string whose subsequences you want to see:" << endl;
  string input;
  cin >> input;
  string *outputStrings = new string[100];

  int totalSubs = subsequenceSize(input, outputStrings);
  for (int i = 0; i < totalSubs; i++) {
    cout << outputStrings[i] << " ";
  }
}

int subsequenceSize(string input, string outputStrings[]) {
  if (input.empty()) {
    outputStrings[0] = "";
    return 1;
  }
  string smallInput = input.substr(1);
  int smallSubsequenceSize = subsequenceSize(smallInput, outputStrings);
  for (int i = 0; i <= smallSubsequenceSize; i++) {
    outputStrings[i + smallSubsequenceSize] = input[0] + outputStrings[i];
  }
  return 2 * smallSubsequenceSize;
}
