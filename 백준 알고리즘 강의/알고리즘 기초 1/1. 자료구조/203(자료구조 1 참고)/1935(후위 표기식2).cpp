#include <iostream>
#include <string>
using namespace std;

class Stack{
    struct node{
        double num;
        node* next;
    };
    using link=node*;

    link top;

public:
    Stack():top(NULL){}
    void Push(double x);
    double Pop();
    ~Stack();
};

int main(){
    int n;
    cin>>n;
    double *operand=new double[n];

    string str;
    cin>>str;

    Stack stk;

    for(int i=0;i<n;i++){
        cin>>operand[i];
    }

    for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z'){
            stk.Push(operand[str[i]-'A']);
        }
        else{
            double b=stk.Pop(),a=stk.Pop();

            if(str[i]=='+'){
                stk.Push(a+b);
            }
            else if(str[i]=='-'){
                stk.Push(a-b);
            }
            else if(str[i]=='*'){
                stk.Push(a*b);
            }
            else if(str[i]=='/'){
                stk.Push(a/b);
            }
        }
    }


    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<stk.Pop();

    return 0;
}


void Stack::Push(double x){
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

double Stack::Pop(){
    double tmp=top->num;
    link tmpnod=top;
    top=top->next;
    delete tmpnod;

    return tmp;
}

Stack::~Stack(){
    while(top){
        link tmp=top;
        top=top->next;
        delete tmp;
    }
}