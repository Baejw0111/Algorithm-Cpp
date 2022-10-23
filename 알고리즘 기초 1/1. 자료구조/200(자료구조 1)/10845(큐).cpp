#include <iostream>
#include <string>
using namespace std;

class Queue{
    struct node{
        int num;
        node *prev,*next;
    };
    using link=node*;

    link head,tail;
    int size;

public:
    Queue();
    void Push(int x);
    void Pop();
    void Size();
    void Empty();
    void Front();
    void Back();
    ~Queue();
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    cin>>n;

    Queue que;

    for(int i=0;i<n;i++){
        string tmpstr;
        cin>>tmpstr;

        if(tmpstr=="push"){
            int tmpn;
            cin>>tmpn;

            que.Push(tmpn);
        }
        else if(tmpstr=="pop"){
            que.Pop();
        }
        else if(tmpstr=="size"){
            que.Size();
        }
        else if (tmpstr=="empty")
        {
            que.Empty();
        }
        else if(tmpstr=="front"){
            que.Front(); 
        }
        else if(tmpstr=="back"){
            que.Back(); 
        }
    }

    return 0;
}

Queue::Queue():head(new node),tail(new node),size(0){
    head->prev=NULL;
    head->next=tail;

    tail->prev=head;
    tail->next=NULL;
}

void Queue::Push(int x){
    link tmp=new node;

    tmp->num=x;

    tmp->prev=tail->prev;
    tmp->next=tail;

    tail->prev=tmp;
    tmp->prev->next=tmp;

    size++;
}

void Queue::Pop(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        link tmpnod=head->next;
        int tmp=tmpnod->num;

        head->next=tmpnod->next;
        head->next->prev=head;

        delete tmpnod;
        size--;

        cout<<tmp<<'\n';
    }
}

void Queue::Size(){
    cout<<size<<'\n';
}

void Queue::Empty(){
    if(size==0){
        cout<<1<<'\n';
    }
    else{
        cout<<0<<'\n';
    }
}

void Queue::Front(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        cout<<head->next->num<<'\n';
    }
}

void Queue::Back(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        cout<<tail->prev->num<<'\n';
    }
}

Queue::~Queue(){
    tail=NULL;

    while(head){
        link tmp=head;
        head=head->next;
        delete tmp;
    }
}