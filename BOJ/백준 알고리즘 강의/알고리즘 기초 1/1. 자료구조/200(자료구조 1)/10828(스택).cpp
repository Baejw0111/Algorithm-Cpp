#include <iostream>
#include <string>
using namespace std;

// 문제에 주어진 조건대로 스택 클래스 구현
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
    void Pop();
    void Size();
    void Empty();
    void Top();
    ~Stack();
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;

    Stack stack;

    for(int i=0;i<n;i++){
        string tmpstr;
        cin>>tmpstr;

        if(tmpstr=="push"){
            int tmpn;
            cin>>tmpn;

            stack.Push(tmpn);
        }
        else if(tmpstr=="pop"){
            stack.Pop();
        }
        else if(tmpstr=="size"){
            stack.Size();
        }
        else if (tmpstr=="empty")
        {
            stack.Empty();
        }
        else if(tmpstr=="top"){
            stack.Top(); 
        }
    }

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

void Stack::Pop(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        int tmp=top->num;
        link tmpnod=top;
        top=top->next;
        delete tmpnod;
        size--;

        cout<<tmp<<'\n';
    }
}

void Stack::Size(){
    cout<<size<<'\n';
}

void Stack::Empty(){
    if(size==0){
        cout<<1<<'\n';
    }
    else{
        cout<<0<<'\n';
    }
}

void Stack::Top(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        cout<<top->num<<'\n';
    }
}

Stack::~Stack(){
    while(top){
        link tmp=top;
        top=top->next;
        delete tmp;
    }
}