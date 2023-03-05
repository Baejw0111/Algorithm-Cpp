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
    int size,mode;

public:
    Deque();
    void Push_Front(int x);
    void Push_Back(int x);
    int Pop_Front();
    int Pop_Back();
    void Size();
    void Empty();
    void Front();
    void Back();
    void Mode();
    int Pop();
    void Read();
    ~Deque();
};

int main(){
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        Deque deque;
        string oper;
        cin>>oper;

        int n,ele;
        cin>>n;
        
        char trash;

        cin>>trash;
        for(int j=0;j<n;j++){
            if(j!=0){
                cin>>trash;
            }
            cin>>ele;

            deque.Push_Back(ele);
        }
        cin>>trash;

        int s=1;
        for(int j=0;j<oper.length();j++){
            if(oper[j]=='R'){
                deque.Mode();
            }
            else if(oper[j]=='D'){
                s=deque.Pop();
                if(s==0){
                    break;
                }
            }
        }

        if(s){
            deque.Read();
        }
    }


    return 0;
}

Deque::Deque():head(new node),tail(new node),size(0),mode(0){
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

int Deque::Pop_Front(){
    if(size==0){
        cout<<"error\n";
        return 0;
    }

    link tmpnod=head->next;
    int tmp=tmpnod->num;

    head->next=tmpnod->next;
    head->next->prev=head;

    delete tmpnod;
    size--;

    return 1;
}

int Deque::Pop_Back(){
    if(size==0){
        cout<<"error\n";
        return 0;
    }

    link tmpnod=tail->prev;
    int tmp=tmpnod->num;

    tail->prev=tmpnod->prev;
    tail->prev->next=tail;

    delete tmpnod;
    size--;
    return 1;
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

void Deque::Mode(){
    mode=!mode;
}

int Deque::Pop(){
    if(mode==0){
        return Pop_Front();
    }
    else{
        return Pop_Back();
    }
}

void Deque::Read(){
    cout<<"[";
    if(mode==0){
        for(link tmp=head->next;tmp!=tail;tmp=tmp->next){
            if(tmp!=tail->prev){
                cout<<tmp->num<<",";
            }
            else{
                cout<<tmp->num;
            }
        }
    }
    else{
        for(link tmp=tail->prev;tmp!=head;tmp=tmp->prev){
            if(tmp!=head->next){
                cout<<tmp->num<<",";
            }
            else{
                cout<<tmp->num;
            }
        }

    }
    cout<<"]\n";
}

Deque::~Deque(){
    tail=NULL;

    while(head){
        link tmp=head;
        head=head->next;
        delete tmp;
    }
}