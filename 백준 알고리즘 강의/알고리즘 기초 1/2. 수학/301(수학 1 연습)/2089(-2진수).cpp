#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    long long int a;
    cin>>a;

    if(a==0){
        cout<<a;
        return 0;
    }

    stack<int> ans;

    while(a!=0){
        int r=a%-2;
        a/=-2;

        if(r==-1){
            ans.push(1);
            a+=1;
        }
        else{
            ans.push(r);
        }
    }

    while(ans.size()>0){
        cout<<ans.top();
        ans.pop();
    }

    return 0;
}