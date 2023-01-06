#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int n,*p,*t;

int main(){
    cin>>n;

    p=new int[n+1]();
    t=new int[n+1]();

    for(int i=1;i<=n;++i){
        cin>>p[i];
    }

    for(int i=1;i<=n;++i){
        int Max=0;
        for(int j=0;j<i;++j){
            int tmp=t[j]+p[i-j];
            if(Max<tmp){
                Max=tmp;
            }
        }
        t[i]=Max;
    }

    cout<<t[n];

    return 0;
}