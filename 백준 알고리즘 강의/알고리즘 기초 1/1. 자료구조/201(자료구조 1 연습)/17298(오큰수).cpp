#include <bits/stdc++.h>
using namespace std;

int n;
/*
arr: 수열 A를 입력받을 배열
ans: 수열 A의 각 수의 오큰수를 저장할 배열
*/
vector<int> arr, ans;

// 오큰수를 알아낼 때 사용할 스택
stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr.resize(n);
    ans.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //오큰수가 없는 수를 고려해 코드 작성에 용이하도록 -1을 push
    stk.push(-1);

    // 수열 A를 거꾸로 읽어나간다.
    for (int i = n - 1; i >= 0; --i)
    {
        /*
        현재 스캔 중인 수보다 스택의 가장 위에 있는 수(top)가 더 크면 pop
        또는 top이 -1이면 pop
        */
        while (stk.top() > 0 && stk.top() <= arr[i])
        {
            stk.pop();
        }

        //위 과정이 끝났을 때의 top을 오큰수로 저장
        ans[i] = stk.top();

        //현재 스캔 중인 수를 스택에 저장
        stk.push(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}