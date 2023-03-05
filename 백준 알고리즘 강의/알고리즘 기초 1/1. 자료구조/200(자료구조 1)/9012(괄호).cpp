#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
    struct node{
        T num;
        node* next;
    };
    using link=node*;

    link top;

public:
    Stack():top(NULL){}
    void Push(T x);
    int Pop();
    int Empty();
    ~Stack();
};

void VPS(string str){
    Stack<char> stk;

    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            stk.Push(str[i]);
        }
        else{
            if(stk.Pop()==0){
                cout<<"NO"<<'\n';
                return;
            }
            else{
                continue;
            }
        }
    }

    if(stk.Empty()==1){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);

        VPS(str);
    }


    return 0;
}


template <typename T>
void Stack<T>::Push(T x){
    if(top==NULL){
        top=new node;
        top->num=x;
        top->next=NULL;
    }
    else{
        link tmp=new node;
        tmp->num=x;
        tmp->next=top;
        top=tmp;
    }
}

template <typename T>
int Stack<T>::Pop(){
    if(top==NULL){
        return 0;
    }
    else{
        top=top->next;
        return 1;
    }
}

template <typename T>
int Stack<T>::Empty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
Stack<T>::~Stack(){
    while(top){
        link tmp=top;
        top=top->next;
        delete tmp;
    }
}