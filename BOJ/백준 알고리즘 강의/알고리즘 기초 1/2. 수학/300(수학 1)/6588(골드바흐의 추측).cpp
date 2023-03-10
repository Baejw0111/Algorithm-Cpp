#include <bits/stdc++.h>
using namespace std;

/* 주어진 것
골드바흐의 추측
4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
n은 각 테스트 케이스마다 주어지는 수
*/

/* 구해야 할 것
주어진 짝수들에 대해 골드바흐 검증
*/

/* 아이디어
n의 최대값은 100만이다.
-> 100만까지의 홀수 소수들을 먼저 찾아내자(DAT 사용)

각 홀수의 배수들을 100만까지 지워나가면서 소수 걸러내기
(에라토스테네스의 체)
prime 배열에 0으로 저장된 값이 소수

지역 변수로 배열 선언 시 100000이 최대 크기
지역 변수는 스택 영역에 쌓이고, 스택 영역의 크기는 제한되어 있기 때문
그러니 존나 큰 배열은 웬만하면 전역 변수로 선언해야 함
*/

#define MAX 1000'000

bool prime[MAX] = {0}; // 소수 여부 저장

// 소수 판별
void findPrime() {
  for (int i = 3; i < MAX; i += 2) {
    if (prime[i])
      continue;

    for (int j = 2 * i; j < MAX; j += i) {
      prime[j] = 1;
    }
  }
}

// 출력값 출력
void output(int n) {
  for (int i = 3; i <= n / 2; i += 2) {
    if (!prime[n - i] && !prime[i]) {
      cout << n << " = " << i << " + " << n - i << '\n';
      return;
    }
  }

  cout << "Goldbach's conjecture is wrong.";
}

void solve() {
  findPrime();

  while (1) {
    int n;
    cin >> n;

    if (n == 0)
      return;

    output(n);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}