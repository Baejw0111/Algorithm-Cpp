#include <iostream>
#include <string>
using namespace std;

class CDLL{
    struct node{
        int num;
        node *prev,*next;
    };
    using link=node*;

    link head;

public:
    CDLL();
    void Add(int x);
    void Delete(int x);
    int Empty();
    void Josephus(int n,int k);
    void Display();
    ~CDLL();
};

int main(){
    int n,k;
    cin>>n>>k;

    CDLL ring;

    for(int i=1;i<=n;i++){
        ring.Add(i);
    }

    ring.Josephus(n,k);

    return 0;
}

CDLL::CDLL():head(new node){
    head->prev=head;
    head->next=head;
}

void CDLL::Add(int x){
    link tmp=new node;
    tmp->num=x;

    if(Empty()){
        tmp->next=tmp;
        tmp->prev=tmp;

        head->next=tmp;
    }
    else{
        tmp->prev=head->next->prev;
        tmp->next=head->next;

        head->next->prev->next=tmp;
        head->next->prev=tmp;
    }
}

void CDLL::Delete(int x){
    if(Empty()){
        return;
    }

    link i=head->next;
    do{
        if(i->num==x){
            if(i==head->next){
                if(head->next->next==head->next){
                    head->next=head;
                }
                else{
                    head->next=i->next;
                }
            }
            i->prev->next=i->next;
            i->next->prev=i->prev;
            delete i;
            return;
        }

        i=i->next;
    }while(i!=head->next);

}

int CDLL::Empty(){
    if(head->next==head){
        return 1;
    }
    else{
        return 0;
    }

}

void CDLL::Josephus(int n,int k){
    int order=0;
    link cur=head;

    cout<<"<";

    while(!Empty()){
        cur=cur->next;
        order+=1;

        if(order==k){
            order=0;
            cur=cur->prev;
            cout<<cur->next->num;
            Delete(cur->next->num);
            if(Empty()){
                cout<<">";
            }
            else{
                cout<<", ";
            }
        }

    }
    cout<<endl;
}

void CDLL::Display(){
    link tmp=head->next;

    do{
        cout<<tmp->num<<" ";
        tmp=tmp->next;
    }while(tmp!=head->next);
    cout<<endl;
}

CDLL::~CDLL(){
    head->next->prev->next=NULL;

    while(head){
        link tmp=head;
        head=head->next;
        delete tmp;
    }
}