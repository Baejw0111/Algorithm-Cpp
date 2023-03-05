#include <iostream>
#include <string>
using namespace std;

int factor(long int n,long int x){
    int c=0;
    for(long int i=x;n/i>=1;i*=x){
        c+=n/i;
    }

    return c;
}
//전체 범위에서 x를 걷어내며 카운팅 하는 함수이다.

int main(){
    long int n,m,two,five;
    cin>>n>>m;

    two=factor(n,2)-factor(n-m,2)-factor(m,2);
    five=factor(n,5)-factor(n-m,5)-factor(m,5);

    if(five>two){
        cout<<two;
    }
    else{
        cout<<five;
    }

    return 0;
}