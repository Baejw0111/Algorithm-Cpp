#include <iostream>
#include <string>
using namespace std;

class Deque{
    struct node{
        int num;
        node *prev,*next;
    };
    using link=node*;

    link head,tail;
    int size;

public:
    Deque();
    void Push_Front(int x);
    void Push_Back(int x);
    void Pop_Front();
    void Pop_Back();
    void Size();
    void Empty();
    void Front();
    void Back();
    ~Deque();
};

int main(){
    int n;
    cin>>n;

    Deque que;

    for(int i=0;i<n;i++){
        string tmpstr;
        cin>>tmpstr;

        if(tmpstr=="push_front"){
            int tmpn;
            cin>>tmpn;

            que.Push_Front(tmpn);
        }
        else if(tmpstr=="push_back"){
            int tmpn;
            cin>>tmpn;

            que.Push_Back(tmpn);
        }
        else if(tmpstr=="pop_front"){
            que.Pop_Front();
        }
        else if(tmpstr=="pop_back"){
            que.Pop_Back();
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

Deque::Deque():head(new node),tail(new node),size(0){
    head->prev=NULL;
    head->next=tail;

    tail->prev=head;
    tail->next=NULL;
}

void Deque::Push_Front(int x){
    link tmp=new node;

    tmp->num=x;

    tmp->prev=head;
    tmp->next=head->next;

    head->next=tmp;
    tmp->next->prev=tmp;

    size++;
}

void Deque::Push_Back(int x){
    link tmp=new node;

    tmp->num=x;

    tmp->prev=tail->prev;
    tmp->next=tail;

    tail->prev=tmp;
    tmp->prev->next=tmp;

    size++;
}

void Deque::Pop_Front(){
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

void Deque::Pop_Back(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        link tmpnod=tail->prev;
        int tmp=tmpnod->num;

        tail->prev=tmpnod->prev;
        tail->prev->next=tail;

        delete tmpnod;
        size--;

        cout<<tmp<<'\n';
    }
}

void Deque::Size(){
    cout<<size<<'\n';
}

void Deque::Empty(){
    if(size==0){
        cout<<1<<'\n';
    }
    else{
        cout<<0<<'\n';
    }
}

void Deque::Front(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        cout<<head->next->num<<'\n';
    }
}

void Deque::Back(){
    if(size==0){
        cout<<-1<<'\n';
    }
    else{
        cout<<tail->prev->num<<'\n';
    }
}

Deque::~Deque(){
    tail=NULL;

    while(head){
        link tmp=head;
        head=head->next;
        delete tmp;
    }
}