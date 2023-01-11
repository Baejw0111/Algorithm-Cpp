#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
//각각 커서의 왼쪽과 오른쪽에 있는 글자들을 저장할 스택
stack<char> left_stk,right_stk;

void input(){
    string str;

    cin>>str;

    for(char c:str){
        left_stk.push(c);
    }
}

void L(){
    if(!left_stk.empty()){
        right_stk.push(left_stk.top());
        left_stk.pop();
    }

    return;
}

void D(){
    if(!right_stk.empty()){
        left_stk.push(right_stk.top());
        right_stk.pop();
    }

    return;
}

void B(){
    if(!left_stk.empty()){
        left_stk.pop();
    }
}

void P(char c){
    left_stk.push(c);
}

void output(){
    while(!left_stk.empty()){
        L();
    }

    while(!right_stk.empty()){
        cout<<right_stk.top();
        right_stk.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    input();

    cin>>n;

    for(int i=0;i<n;++i){
        char command;
        char c;

        cin>>command;

        switch(command){
            case 'L':
                L();
                break;

            case 'D':
                D();
                break;

            case 'B':
                B();
                break;

            case 'P':
                cin>>c;
                P(c);
                break;
        }
    }

    output();

    return 0;
}