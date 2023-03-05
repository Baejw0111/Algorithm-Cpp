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
    int tc;
    cin >> tc;

    //최빈값
    int ans;
    //최빈값의 개수
    int max_count = 0;
    //각 점수의 개수를 저장할 배열
    int count[101] = {0};

    for (int i = 0; i < 1000; ++i) {
      int score;
      cin >> score;

      count[score] += 1;
      if (count[score] > max_count) {
        ans = score;
        max_count = count[score];
      }
      else if (count[score] == max_count && score > ans) {
        ans = score;
      }
    }

    cout << '#' << tc << ' ' << ans << '\n';
  }
  return 0;
}