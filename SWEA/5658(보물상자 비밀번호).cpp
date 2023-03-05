#include <bits/stdc++.h>
using namespace std;

/* 주어진 조건
 */

/* 구하는 것
 */

/* 아이디어
회전시키면서 걍 다 처넣기
16진수로 만드는 함수(hex_to_dec)
Hex 구조체 만들어 정렬시키기
배열 훑으면서 중복되면 order 세지 말기
 */

// 변수

struct Hex
{
    string hex;
    long long dec;

    bool operator<(Hex next)
    {
        return dec > next.dec;
    }
};

int n;      // 숫자 개수
int k;      // 크기 순서
string str; // 입력받는 문자열
vector<Hex> arr;

// 함수

// 입력
void input()
{
    cin >> n >> k >> str;
}

long long hex_to_dec(string hex)
{
    long long sum = 0;
    long long mul = 1;

    for (int i = 0; i < n / 4 - 1; ++i)
    {
        mul *= 16;
    }

    for (char i : hex)
    {
        if (i < 'A')
        {
            sum += (i - '0') * mul;
        }
        else
        {
            sum += (i - 'A' + 10) * mul;
        }
        mul /= 16;
    }

    return sum;
}

void solve()
{
    input();
    arr.clear();
    for (int i = 0; i < n / 4; ++i)
    {
        // cout<<"str: "<<str<<'\n';
        for (int j = 0; j < 4; ++j)
        {
            string hex = str.substr(j * n / 4, n / 4);
            // cout<<hex<<'\n';
            arr.push_back({hex, hex_to_dec(hex)});
        }
        // 회전
        char tmp = str[0];
        str.erase(0, 1);
        str.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    int order = 1;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i != 0 && arr[i].hex == arr[i - 1].hex)
        {
            continue;
        }

        if (order == k)
        {
            cout << arr[i].dec << '\n';
            break;
        }
        else
        {
            // cout<<i<<'\n';
            order++;
        }
    }
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
