// https://www.acmicpc.net/problem/1934

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    if (a < b) {
      int tmp = a;
      a = b;
      b = tmp;
    }

    cout << a * b / gcd(a, b) << endl;
  }

  return 0;
}