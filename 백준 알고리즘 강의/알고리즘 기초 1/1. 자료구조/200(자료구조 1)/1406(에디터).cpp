#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List{
    struct node{
        T data;
        node *prev,*next;
    };
    using link=node*;

    link head,cur,tail;
    //head와 tail은 더미노드
    //cur는 head를 제외한 모든 노드를 가리킬 수 있다.

public:
    List();
    void Left();
    void Right();
    void Add(T x);
    void Delete();
    void Display();
    ~List();
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    string str;
    cin>>str;

    List<char> editor;

    for(int i=0;i<str.length();i++){
        editor.Add(str[i]);
    }


    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        char m,tmp;
        cin>>m;

        switch(m){
            case 'L':
                editor.Left();
                break;
            case 'D':
                editor.Right();
                break;
            case 'B':
                editor.Delete();
                break;
            case 'P':
                cin>>tmp;
                editor.Add(tmp);
                break;
        }
    }

    editor.Display();

    return 0;
}

template <typename T>
List<T>::List():head(new node),tail(new node){
    head->prev=NULL;
    head->next=tail;

    tail->prev=head;
    tail->next=NULL;

    cur=tail;
}

template <typename T>
void List<T>::Left(){
    if(cur->prev!=head){
        cur=cur->prev;
    }
}

template <typename T>
void List<T>::Right(){
    if(cur->next!=NULL){
        cur=cur->next;
    }
}

template <typename T>
void List<T>::Add(T x){
    link tmp=new node;
    tmp->data=x;

    cur->prev->next=tmp;
    tmp->prev=cur->prev;

    cur->prev=tmp;
    tmp->next=cur;
}

template <typename T>
void List<T>::Delete(){
    if(cur->prev!=head){
        link tmp=cur->prev;
        tmp->prev->next=cur;
        cur->prev=tmp->prev;
        delete tmp;
    }
}

template <typename T>
void List<T>::Display(){
    link tmp=head->next;

    while(tmp!=tail){
        cout<<tmp->data;
        tmp=tmp->next;
    }
    cout<<'\n';
}

template <typename T>
List<T>::~List(){
    cur=NULL;
    tail=NULL;

    while(head){
        link tmp=head;
        head=head->next;
        delete tmp;
    }
}