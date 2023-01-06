#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
    struct node{
        T data;
        node* next;
    };
    using link=node*;

    link top;

public:
    Stack():top(NULL){}
    void Push(T x);
    T Pop();
    T Top();
    int Empty();
    ~Stack();
};

int order(char x){
    int r;
    if(x=='+'||x=='-'){
        r=1;
    }
    else if(x=='*'||x=='/'){
        r=2;
    }
    else if(x=='('){
        r=0;
    }

    return r;
}

int main(){
    string str;
    cin>>str;

    Stack<char> stk;

    for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z'){
            cout<<str[i];
        }
        else if(str[i]=='('){
            stk.Push(str[i]);
        }
        else if(str[i]==')'){
            while(stk.Top()!='('){
                cout<<stk.Pop();
            }
            stk.Pop();
        }
        else{
            while(order(stk.Top())>=order(str[i])){
                cout<<stk.Pop();
            }
            stk.Push(str[i]);
        }
    }

    while(!stk.Empty()){
        cout<<stk.Pop();
    }

    return 0;
}


template <typename T>
void Stack<T>::Push(T x){
    if(top==NULL){
        top=new node;
        top->data=x;
        top->next=NULL;
    }
    else{
        link tmp=new node;
        tmp->data=x;
        tmp->next=top;
        top=tmp;
    }
}

template <typename T>
T Stack<T>::Pop(){
    T tmp=top->data;
    top=top->next;

    return tmp;
}

template <typename T>
T Stack<T>::Top(){
    if(top==NULL){
        return 0;
    }
    else{
        return top->data;
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