#include <bits/stdc++.h>
using namespace std;

int n;

/*
seq: 수열 A를 저장할 스택
stk: 오큰수를 알아낼 때 사용할 스택
ans: 수열 A의 각 수의 오큰수를 저장할 스택
*/
stack<int> seq,stk,ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        seq.push(tmp);
    }

    /*
    오큰수가 무조건 없는 수열의 마지막 수를 고려해
    코드 작성에 용이하도록 -1을 push
    */
    stk.push(-1);

    // 수열 A를 거꾸로 읽어나간다.
    while(!seq.empty())
    {
        /*
        현재 스캔 중인 수보다 stk의 가장 위에 있는 수(top)가 더 크면 pop
        top이 -1일 시 중단
        */
        while (stk.top() > 0 && stk.top() <= seq.top())
        {
            stk.pop();
        }

        //위 과정이 끝났을 때의 stk의 top을 오큰수로 저장
        ans.push(stk.top());

        //현재 스캔 중인 수를 스택에 저장
        stk.push(seq.top());

        //다음 수 스캔
        seq.pop();
    }

    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }

    return 0;
}