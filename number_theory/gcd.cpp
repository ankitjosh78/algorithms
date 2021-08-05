#include <bits/stdc++.h>

using namespace std;

// calculating gcd of two numbers
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    return 0;
}
