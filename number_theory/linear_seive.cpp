#include <vector>
using namespace std;

vector<int> linear_seive(int N) {
  vector<int> spf(N + 1);
  vector<int> primes;
  for (int i = 2; i <= N; i++) {
    if (spf[i] == 0) {
      spf[i] = i;
      primes.push_back(i);
    }
    for (int j = 0;
         j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] <= N;
         j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
  return spf;
}
