#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

ll n,s,a[20]={0},ans=0,tmp[20]={0};

void permutation(int p,ll total,int t){
    if(total==s && p!=-1){
        ans+=1;
    }
    if(n-1==p){
        return;
    }
    for(int i=p+1;i<n;++i){
        tmp[t]=a[i];
        permutation(i,total+a[i],t+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>s;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    permutation(-1,0,0);
    cout<<ans;

    return 0;
}