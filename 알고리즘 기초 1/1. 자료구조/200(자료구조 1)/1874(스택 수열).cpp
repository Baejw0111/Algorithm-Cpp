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
    int Pop();
    int Top();
    ~Stack();
};

int check(int *arr,int n){
    Stack<int> stk;
    int k=1;

    for(int i=0;i<n;i++){
        while(stk.Top()<arr[i]){
            stk.Push(k);
            k++;
        }

        if(stk.Top()==arr[i]){
            stk.Pop();
        }
        else{
            return 0;
        }
    } 

    return 1;
}

void sequence(int *arr,int n){
    Stack<int> stk;
    int k=1;

    for(int i=0;i<n;i++){
        while(stk.Top()<arr[i]){
            stk.Push(k);
            k++;
            cout<<"+"<<'\n';
        }

        stk.Pop();
        cout<<"-"<<'\n';
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(check(arr,n)){
        sequence(arr,n);
    }
    else{
        cout<<"NO"<<'\n';
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
int Stack<T>::Top(){
    if(top==NULL){
        return 0;
    }
    else{
        return top->data;
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