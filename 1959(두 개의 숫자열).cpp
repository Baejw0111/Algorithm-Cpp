#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  int T;

  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case) {
    int n, m, big, small, ans;
    //입력 받을 숫자열들을 저장할 배열
    int A[20] = {0}, B[20] = {0};
    // bigArr은 길이가 더 긴 배열을 가리키는 포인터, smallArr은 길이가 더 짧은
    // 배열을 가리키는 포인터
    int *bigArr, *smallArr;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }

    for (int i = 0; i < m; ++i) {
      cin >> B[i];
    }

    if (n > m) {
      bigArr = A;
      smallArr = B;
      big = n;
      small = m;
    } else {
      bigArr = B;
      smallArr = A;
      big = m;
      small = n;
    }

    for (int start = 0; start <= big - small; ++start) {
      int total = 0;
      for (int i = 0; i < big; ++i) {
        if (i >= start && i < start + small) {
          total += bigArr[i] * smallArr[i - start];
        }
      }
      if (start == 0) {
        ans = total;
      } else {
        if (ans < total) {
          ans = total;
        }
      }
    }

    cout << '#' << test_case << ' ' << ans << '\n';
  }
  return 0;
}