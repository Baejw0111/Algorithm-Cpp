#include <bits/stdc++.h>
using namespace std;

/* 주어진 조건
n*n 크기의 도시
한 집이 지불할 수 있는 비용 m
마름모 영역에서 제공
서비스 영역의 크기 k
비용: k*k+(k-1)*(k-1)
도시를 벗어난 영역에 서비스를 제공해도 운영 비용은 동일함
->손해 발생 가능성 올라감
 */

/* 구하는 것
손해 보지 않을 때,서비스 제공받는 집 최대일 때의 집 수
 */

/* 아이디어
BFS로 거리가 k 이내인 집 개수 구하기
k늘리기 전에 수익 계산
solve->전체 칸 훑으면서 BFS()실행
BFS를 영역이 맵 꽉채울때까지 돌리기
큐에 넣다가 dist 증가 시 수익 갱신(renewAns)
 */

// 변수

int n;                                                      // 도시 너비
int m;                                                      // 한 집이 지불하는 비용
bool city[20][20];                                          // 도시 지도
int k;                                                      // 서비스 영역의 크기
int ans;                                                    // 정답
pair<int, int> dir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 방향배열(상좌하우)

// 함수

// 입력
void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> city[i][j];
        }
    }
}

void renewAns(int a, int homeCnt)
{
    int earn = homeCnt * m - (a * a + (a - 1) * (a - 1));

    if (earn >= 0)
    {
        ans = max(ans, homeCnt);
    }
}

void BFS(int y, int x)
{
    queue<pair<pair<int, int>, int>> que;
    bool visited[20][20] = {0};
    int home = 0;
    int cur_dist = 1;

    que.push({{y, x}, 1});
    visited[y][x] = 1;

    while (!que.empty())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int dist = que.front().second;
        que.pop();

        if (dist > cur_dist)
        {
            renewAns(cur_dist, home);
            cur_dist = dist;
        }

        if (city[y][x])
        {
            home++;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i].first;
            int nx = x + dir[i].second;

            if (ny < 0 || n <= ny || nx < 0 || n <= nx || visited[ny][nx])
                continue;

            visited[ny][nx] = 1;
            que.push({{ny, nx}, dist + 1});
        }
    }

    renewAns(cur_dist, home);
}

void solve()
{
    input();
    ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            BFS(i, j);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        cout << '#' << i << ' ';
        solve();
    }
    return 0;
}
