#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    // '('를 저장할 스택
    stack<char> stk;
    /* 정답을 저장할 변수.
    잘려진 쇠막대기 조각의 총 개수를 의미한다. */
    int ans = 0;
    // 문자열에서 현재 문자의 앞 문자를 저장할 변수다.
    char prev = '(';

    for (char a : str)
    {
        if (a == '(')
        {
            stk.push(a);
        }
        else
        {
            stk.pop();
            if (prev == '(')
            {
                ans += stk.size();
            }
            else
            {
                ans += 1;
            }
        }

        prev = a;
    }

    cout << ans;

    return 0;
}