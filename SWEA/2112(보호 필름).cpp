#include <bits/stdc++.h>
using namespace std;

int T;                      // 테스트 케이스 개수
int ans;                    // 각 테스트 케이스 별 정답
int d;                      // 두께
int w;                      // 너비
int k;                      // 합격 기준
int film[13][20];           // 현재 필름 상태
int film_copy[13][20];      // 원래의 필름 상태 사본

void input();                   // 변수 입력
int qualify();                  // 검사
void inject(int row, int mode); /* 약품 투여
                                row: 약품을 투여할 층
                                mode:
                                    - 0: A 약품 투여
                                    - 1: B 약품 투여
                                    - 2: 원상태로 복구 */
void DFS(int cnt, int index);   /* 최소 약품 투여 회수 구하기 위한 DFS 실행
                                cnt: 약품 투여 회수
                                index: index 층부터 약품 주입 */
void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
};

void input()
{
    cin >> d >> w >> k;

    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> film[i][j];
            film_copy[i][j] = film[i][j];
        }
    }
}

int qualify()
{
    for (int i = 0; i < w; ++i)
    {
        int cnt = 1;   // 연속으로 나오는 수 카운트
        int check = 0; // 열 검사 통과 여부

        for (int j = 1; j < d; ++j)
        {
            if (film[j][i] == film[j - 1][i])
            {
                ++cnt;
            }
            else
            {
                // 앞으로 k개의 연속된 수가 나올 수 없을 경우 해당 열 검사 종료
                if (j == d - k + 1)
                {
                    return 0;
                }
                cnt = 1;
            }

            if (cnt >= k)
            {
                check = 1;
                break;
            }
        }
        if (!check)
        {
            return 0;
        }
    }

    return 1;
}

void inject(int row, int mode)
{
    if (mode == 2)
    {
        for (int i = 0; i < w; ++i)
        {
            film[row][i] = film_copy[row][i];
        }
    }
    else
    {
        for (int i = 0; i < w; ++i)
        {
            film[row][i] = mode;
        }
    }
}

void DFS(int cnt, int index)
{
    /*
    투여 횟수가 k 이상이거나
    현재 최소값 이상일 경우
    또는 index가 d와 같은 경우 가지치기
    */
    if (cnt >= k || cnt >= ans || index > d)
    {
        return;
    }

    // 검사 통과 시 최소값 갱신
    if (qualify())
    {
        ans = cnt;
        return;
    }

    //================= 시간초과의 원인 =================
    // 어차피 recursion에서 index는 자동으로 내려갈테니, index -> d까지 다시 중복되는 조합을
    // 돌려볼 필요가 없습니다!

    // 약 투여 안하고 다음 층으로
    DFS(cnt, index + 1);

    inject(index, 0);

    // A 투여
    DFS(cnt + 1, index + 1);

    inject(index, 1);

    // B 투여
    DFS(cnt + 1, index + 1);

    inject(index, 2);
}

void solve()
{
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        ans=20;
        input();

        /*
        k가 1이거나
        검사 바로 통과하는 경우
        투약 안해도 됨
        */
        if (k == 1 || qualify())
        {
            ans = 0;
        }
        else
        {
            DFS(0, 0);
            /*
            DFS에서 cnt가 k와 같을 경우
            ans가 갱신이 안되고 함수를 그래도 종료시키므로
            정답이 k와 같을 경우는 ans의 상태가 초기값 그대로일 것임
            */
            if (ans == 20)
            {
                ans = k;
            }
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }
}