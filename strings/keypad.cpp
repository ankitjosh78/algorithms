#include <iostream>
#include <vector>
using namespace std;

vector<string> keys = {"",    "NULL", "abc",  "def", "ghi",
                       "jkl", "mno",  "pqrs", "tuv", "wxyz"};
vector<string> output;

long long int keyPadSubSize(int input) {
  if (input == 0) {
    output.push_back("");
    return 1;
  }
  int currentDigit = input % 10;
  int smallInput = (input / 10);
  int smallKeyPadSize = keyPadSubSize(smallInput);
  string currentLetters = keys[currentDigit];
  for (char ch : currentLetters) {
    for (int i = 0; i < smallKeyPadSize; i++) {
      output.push_back(output[i] + ch);
    }
  }
  for (size_t i = smallKeyPadSize; i <= output.size(); i++) {
    output[i - smallKeyPadSize] = output[i];
  }
  output.erase(output.begin() + (output.size() - smallKeyPadSize),
               output.end());
  return currentLetters.size() * smallKeyPadSize;
}

int main() {
  cout << "Enter a number:" << endl;
  int n;
  cin >> n;
  long long int ans = keyPadSubSize(n);
  cout << ans << endl;
  for (int i = 0; i <= ans; i++) {
    cout << output[i] << endl;
  }
}
