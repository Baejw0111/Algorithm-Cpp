#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

ll n,w[10][10]={0},a[10]={0},u[10]={0},ans=10000000;

void permutation(int s,ll total,int start){
    if(s==n){
        if(w[a[s-1]][start]!=0){
            total+=w[a[s-1]][start];
            ans=min(total,ans);
        }
        return;
    }
    for(int i=0;i<n;++i){
        if(!u[i] && w[a[s-1]][i]!=0){
            a[s]=i;
            u[i]=1;
            permutation(s+1,total+w[a[s-1]][i],start);
            u[i]=0;
        }
        else{
            continue;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>w[i][j];
        }
    }

    for(int i=0;i<n;++i){
        a[0]=i;
        u[i]=1;
        permutation(1,0,i);
        u[i]=0;
    }

    cout<<ans<<"\n";

    return 0;
}