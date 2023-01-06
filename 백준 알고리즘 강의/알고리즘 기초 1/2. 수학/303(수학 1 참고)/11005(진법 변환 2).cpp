#include <iostream>
#include <string>
#include <stack>
using namespace std;

void trans(int n,int b){
    stack<char> ans;

    if(b<=10){
        while(n!=0){
            ans.push(n%b+'0');
            n/=b;
        }
    }
    else{
        while(n!=0){
            int r=n%b;
            if(r<10){
                ans.push(r+'0');
            }
            else{
                ans.push(r-10+'A');
            }
            n/=b;
        }
    }

    while(ans.size()>0){
        cout<<ans.top();
        ans.pop();
    }
}

int main(){
    long long int n;
    int b;
    cin>>n>>b;

    trans(n,b); 

    return 0;
}