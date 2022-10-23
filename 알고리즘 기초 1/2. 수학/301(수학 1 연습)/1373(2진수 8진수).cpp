#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin>>str;

    stack<int> oct;

    int k=1,tmp=0;

    for(int i=str.length()-1;i>=0;i--){
        tmp+=k*(str[i]-'0');
        k*=2;
        if(k==8||i==0){
            oct.push(tmp);
            tmp=0;
            k=1;
        }
    }

    while(oct.size()>0){
        cout<<oct.top();
        oct.pop();
    }

    return 0;
}