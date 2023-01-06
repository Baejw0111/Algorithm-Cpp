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
    T Pop();
    int Empty();
    ~Stack();
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    string str;
    getline(cin,str);

    Stack <char>stk1,stk2;

    int start=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='<'){
            stk2.Push(str[i]);
            for(int k=start;k<i;k++){
                str[k]=stk1.Pop();
            }
            start=i+1;
        }
        else if(str[i]=='>'){
            stk2.Pop();
            start=i+1;
        }

        if(stk2.Empty()){
            if(str[i]==' '){
                for(int k=start;k<i;k++){
                    str[k]=stk1.Pop();
                }
                start=i+1;
            }
            else{
                stk1.Push(str[i]);
            }
        }
        else{
            continue;
        }
    }

    if(str[str.length()-1]!='>'){
        for(int i=start;i<str.length();i++){
            str[i]=stk1.Pop();
        }
    }

    cout<<str<<'\n';

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
T Stack<T>::Pop(){
    int tmp=top->num;
    top=top->next;

    return tmp;
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