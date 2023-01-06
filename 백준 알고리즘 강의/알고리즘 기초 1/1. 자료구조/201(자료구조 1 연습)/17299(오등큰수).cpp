#include <iostream>
#include <string>
using namespace std;

class Stack{
    struct node{
        int num;
        node* next;
    };
    using link=node*;

    link top;
    int size;

public:
    Stack():top(NULL),size(0){}
    void Push(int x);
    int Pop();
    int Top();
    ~Stack();
};

int main(){
    int n,max=0;
    cin>>n;

    int *arr=new int[n],*ans=new int[n];

    Stack stk;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max<arr[i]){
            max=arr[i];
        }
    }

    int f[max+1]={0};
    for(int i=0;i<n;i++){
        f[arr[i]]+=1;
    }

    stk.Push(-1);

    for(int i=n-1;i>=0;i--){
        while(stk.Top()>0 && f[stk.Top()]<=f[arr[i]]){
            stk.Pop();
        }
        ans[i]=stk.Top();
        stk.Push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    delete[] arr;
    delete[] ans;

    return 0;
}


void Stack::Push(int x){
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

    size++;
}

int Stack::Pop(){
    if(size==0){
        return -1;
    }
    else{
        int tmp=top->num;
        link tmpnod=top;
        top=top->next;
        delete tmpnod;
        size--;

        return tmp;
    }
}

int Stack::Top(){
    return top->num;
}

Stack::~Stack(){
    while(top){
        link tmp=top;
        top=top->next;
        delete tmp;
    }
}