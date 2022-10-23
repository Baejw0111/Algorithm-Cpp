#include <iostream>
#include <string>
using namespace std;

class Stack{
    struct node{
        char elem;
        node* next;
    };
    using link=node*;

    link top;
    int size;

public:
    Stack():top(NULL),size(0){}
    void Push(char x);
    int Pop();
    int Size();
    ~Stack();
};

int main(){
    string str;
    cin>>str;

    int total=0;

    Stack stk;

    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            if(i+1<str.length() && str[i+1]==')'){
                total+=stk.Size();
                i++;
                continue;
            }
            else{
                stk.Push(str[i]);
                total+=1;
            }
        }
        else if(str[i]==')'){
            stk.Pop();
        }
    }

    cout<<total;

    return 0;
}


void Stack::Push(char x){
    if(top==NULL){
        top=new node;
        top->elem=x;
        top->next=NULL;
    }
    else{
        link tmp=new node;
        tmp->elem=x;
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
        int tmp=top->elem;
        link tmpnod=top;
        top=top->next;
        delete tmpnod;
        size--;

        return tmp;
    }
}

int Stack::Size(){
    return size;
}

Stack::~Stack(){
    while(top){
        link tmp=top;
        top=top->next;
        delete tmp;
    }
}