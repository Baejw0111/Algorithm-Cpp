#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
    struct node
    {
        T num;
        node *next;
    };
    using link = node *;

    link top;

public:
    Stack() : top(NULL) {}
    void Push(T x);
    T Pop();
    ~Stack();
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin >> n;

    // 테스트 케이스를 입력 받은 후 다음 버퍼를 비워줘야 실행이 제대로 된다.
    cin.ignore();
    /*
    예전에 풀었을 때는 아래와 같이 임시 방편으로 string 변수를 따로 만들어 버렸는데,
    이번 포스팅을 하면서 찾아보니 위 코드를 써서 버퍼를 비우는 방법이 있었다.
    */
    // string trash;
    // getline(cin,trash);

    for (int i = 0; i < n; i++)
    {
        Stack<char> stack;

        string str;
        getline(cin, str);

        // str 내의 각 단어의 첫 시작 문자의 index이다.
        int start = 0;

        // str을 처음부터 끝까지 훑으며 각 단어를 뒤집어 저장하는 과정이다.
        for (int j = 0; j < str.length(); j++)
        {
            /*
            현재 index에 저장된 문자가 공백일 시,
            현재 스택에 저장된 문자들을 하나씩 꺼내 start부터 차례대로 저장
            이 과정에서 단어가 뒤집혀 저장된다.
            */
            if (str[j] == ' ')
            {
                for (int k = start; k < j; k++)
                {
                    str[k] = stack.Pop();
                }
                // start 값 갱신
                start = j + 1;
            }

            // 그 외의 경우 문자를 스택에 넣기
            else
            {
                stack.Push(str[j]);
            }
        }

        // 문장을 끝까지 훑었을 시 스택에 저장된 문자들 모두 꺼내기
        for (int j = start; j < str.length(); j++)
        {
            str[j] = stack.Pop();
        }

        cout << str << '\n';
    }

    return 0;
}

template <typename T>
void Stack<T>::Push(T x)
{
    if (top == NULL)
    {
        top = new node;
        top->num = x;
        top->next = NULL;
    }
    else
    {
        link tmp = new node;
        tmp->num = x;
        tmp->next = top;
        top = tmp;
    }
}

template <typename T>
T Stack<T>::Pop()
{
    int tmp = top->num;
    top = top->next;

    return tmp;
}

template <typename T>
Stack<T>::~Stack()
{
    while (top)
    {
        link tmp = top;
        top = top->next;
        delete tmp;
    }
}