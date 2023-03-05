#include <bits/stdc++.h>
using namespace std;

struct Operator
{
    char ch;   // 연산자 문자
    int order; // 연산자의 우선순위
};

// 기본 연산자들의 원형
Operator base[4] = {{'+', 0},
                    {'-', 0},
                    {'*', 1},
                    {'/', 1}};

// 연산자들을 저장할 스택
stack<Operator> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력받을 문자열
    string str;

    /*
    괄호 있을 시 괄호 안의 연산자들의
    우선순위를 올려주기 위한 변수
    */
    int bracket = 0;

    cin >> str;

    for (char i : str)
    {
        // 피연산자는 바로 출력
        if (i >= 'A' && i <= 'Z')
        {
            cout << i;
        }
        // 연산자의 경우
        else
        {
            Operator tmp;

            switch (i)
            {
            case '+':
                tmp = base[0];
                break;

            case '-':
                tmp = base[1];
                break;

            case '*':
                tmp = base[2];
                break;

            case '/':
                tmp = base[3];
                break;

            // 괄호는 스택에 넣지 않는다.
            case '(':
                bracket += 5;
                continue;

            case ')':
                bracket -= 5;
                continue;
            }

            // 연산자가 괄호 안에 있으면 우선순위가 올라간다
            tmp.order += bracket;

            /*
            현재 연산자의 우선순위가
            스택의 가장 위에 있는 연산자(top)보다 커질 때까지
            또는 스택의 원소가 없어질 때까지
            top을 출력하고 pop 실행
            */
            while (!stk.empty() && stk.top().order >= tmp.order)
            {
                cout << stk.top().ch;
                stk.pop();
            }

            // 스택에 연산자 push
            stk.push(tmp);
        }
    }

    // 문자열 다 읽었을 경우 스택에 남은 연산자 모두 출력
    while (!stk.empty())
    {
        cout << stk.top().ch;
        stk.pop();
    }

    return 0;
}