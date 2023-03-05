#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // int test_case;
  // int T;

  // cin >> T;

  // for (test_case = 1; test_case <= T; ++test_case) {
  for (int test_case = 0; test_case < 10; ++test_case) {
    int T;
    cin >> T;

    //입력 받을 배열
    int mat[100][100] = {0};
    int ans = 0;

    //각 열의 합
    int col_sum[100] = {0};

    //각 대각선의 합
    int diag_sum = 0, reverse_diag_sum = 0;

    for (int i = 0; i < 100; ++i) {
      //각 행의 합
      int row_sum = 0;
      for (int j = 0; j < 100; ++j) {
        cin >> mat[i][j];
        row_sum += mat[i][j];
        col_sum[j] += mat[i][j];
        if (i == j) {
          diag_sum += mat[i][j];
        }

        if (i == j - 99) {
          reverse_diag_sum += mat[i][j];
        }
      }

      if (ans < row_sum) {
        ans = row_sum;
      }
    }

    for (int i = 0; i < 100; ++i) {
      if (col_sum[i] > ans) {
        ans = col_sum[i];
      }
    }

    if (diag_sum > ans) {
      ans = diag_sum;
    }

    if (reverse_diag_sum > ans) {
      ans = reverse_diag_sum;
    }

    cout << '#' << T << ' ' << ans << '\n';
  }
  return 0;
}