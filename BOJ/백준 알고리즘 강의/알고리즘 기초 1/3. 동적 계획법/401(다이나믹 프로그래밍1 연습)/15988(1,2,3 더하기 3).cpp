#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

ll a[1000001]={0},t,d=1000000009,n;

int main(){
    a[0]=1;
    cin>>t;

    for(int i=1;i<1000001;++i){
        if(i>=1){
            a[i]+=a[i-1];
        }
        if(i>=2){
            a[i]+=a[i-2];
        }
        if(i>=3){
            a[i]+=a[i-3];
        }
        a[i]%=d;
    }

    for(int i=0;i<t;++i){
        cin>>n;
        cout<<a[n]<<'\n';
    }

    return 0;
}