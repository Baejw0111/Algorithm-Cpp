#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n;
// 수열을 입력받을 벡터
vector<int> seq;
// 입력받은 수열을 만들 스택
stack<int> stk;
// 스택 연산을 저장할 큐
queue<char> command;

int check()
{
    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        while (k < seq[i])
        {
            ++k;
            stk.push(k);
            command.push('+');
        }

        if (seq[i] == stk.top())
        {
            stk.pop();
            command.push('-');
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }

    if (check())
    {
        while (!command.empty())
        {
            cout << command.front() << '\n';
            command.pop();
        }
    }
    else
    {
        cout << "NO" << '\n';
    }

    return 0;
}