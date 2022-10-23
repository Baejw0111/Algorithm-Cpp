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
    ~Stack();
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;
    string trash;
    getline(cin,trash);


    for(int i=0;i<n;i++){
        Stack <char>stack;

        string str;
        getline(cin,str);

        int start=0;
        for(int j=0;j<str.length();j++){
            if(str[j]==' '){
                for(int k=start;k<j;k++){
                    str[k]=stack.Pop();
                }
                start=j+1;
            }
            else{
                stack.Push(str[j]);
            }
        }
        for(int j=start;j<str.length();j++){
            str[j]=stack.Pop();
        }

        cout<<str<<'\n';
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
T Stack<T>::Pop(){
    int tmp=top->num;
    top=top->next;

    return tmp;
}


template <typename T>
Stack<T>::~Stack(){
    while(top){
        link tmp=top;
        top=top->next;
        delete tmp;
    }
}