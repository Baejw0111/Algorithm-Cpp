#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define lli long long int

int a[1000][3]={0},n,ans=0,ansi;

int main(){
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>a[i][0];
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            if(a[j][0]<a[i][0] && a[j][1]>a[i][1]){
                a[i][1]=a[j][1];
                a[i][2]=j;
            }
        }
        a[i][1]+=1;
        if(a[i][1]==1){
            a[i][2]=i;
        }
        if(ans<a[i][1]){
            ans=a[i][1];
            ansi=i;
        }
    }

    cout<<ans<<endl;
     
    stack<int> stk;
    while(1){
        stk.push(a[ansi][0]);
        if(a[ansi][2]==ansi){
            break;
        }
        else{
            ansi=a[ansi][2];
        }
    }

    while(stk.size()>0){
        cout<<stk.top()<<" ";
        stk.pop();
    }

    return 0;
}