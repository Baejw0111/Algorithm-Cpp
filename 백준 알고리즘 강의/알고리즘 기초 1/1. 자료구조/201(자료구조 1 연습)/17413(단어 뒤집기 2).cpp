#include <bits/stdc++.h>
using namespace std;

// 단어 전용 스택
stack<char> word;
// 꺽쇠 기호 존재 상태
int bracket = 0;

// word를 비우면서 출력하는 함수
void clear()
{
    while (!word.empty())
    {
        cout << word.top();
        word.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    string S;

    getline(cin, S);

    for (char a : S)
    {
        if (!bracket)
        {
            if (a == ' ' || a == '<')
            {
                clear();
                cout << a;
            }
            else
            {
                word.push(a);
            }
        }
        else
        {
            cout << a;
        }

        if (a == '<')
        {
            bracket = 1;
            continue;
        }
        else if (a == '>')
        {
            bracket = 0;
        }
    }

    clear();

    return 0;
}