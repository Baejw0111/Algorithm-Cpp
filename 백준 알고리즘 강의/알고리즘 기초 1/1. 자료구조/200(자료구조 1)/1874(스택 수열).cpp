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
    // 스택 작업에 이용될 변수
    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        // k가 수열의 i번째 수보다 같아질 때 까지 값을 늘려가며 스택에 push.
        // 동시에 스택 작업 기록
        while (k < seq[i])
        {
            ++k;
            stk.push(k);
            command.push('+');
        }

        // 위 작업이 끝난 후 수열의 i번째 수와 스택의 가장 위에 있는 수가 같을 시 pop
        // 역시 동시에 스택 작업 기록
        if (seq[i] == stk.top())
        {
            stk.pop();
            command.push('-');
        }
        // 같지 않다면 수열을 만드는 것이 불가능 함.
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

    // check의 반환값으로 입력받은 수열을 만드는 것이 가능한 지의 여부 판단 가능
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