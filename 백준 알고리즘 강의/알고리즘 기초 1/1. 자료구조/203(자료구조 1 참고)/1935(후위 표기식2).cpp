#include <bits/stdc++.h>
using namespace std;

int n;

// 후위표기식을 저장할 문자열
string str;

// 피연산자를 저장할 스택
stack<double> stk;

// 피연산자의 실제 값을 저장할 벡터
vector<double> operand;

double cal(char oper)
{
    double a, b, ret;
    // 연산의 우항
    b = stk.top();
    stk.pop();

    // 연산의 좌항
    a = stk.top();
    stk.pop();

    switch (oper)
    {
    case '+':
        ret = a + b;
        break;

    case '-':
        ret = a - b;
        break;

    case '*':
        ret = a * b;
        break;

    case '/':
        ret = a / b;
        break;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> str;

    for (int i = 0; i < n; ++i)
    {
        double tmp;
        cin >> tmp;

        operand.push_back(tmp);
    }

    for (char i : str)
    {
        // 피연산자
        if (i >= 'A' && i <= 'Z')
        {
            stk.push(operand[i - 'A']);
        }
        // 연산자
        else
        {
            stk.push(cal(i));
        }
    }

    // 소수점 둘째 자리까지 출력
    cout << fixed;
    cout.precision(2);
    cout << stk.top();

    return 0;
}