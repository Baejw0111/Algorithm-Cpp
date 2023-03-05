#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,num[8]={0},a[8]={0},u[8]={0},ans=0;

void permutation(int s){
    if(s==n){
        int total=0;
        for(int i=1;i<n;++i){
            total+=abs(a[i]-a[i-1]);
        }
        ans=max(ans,total);
        return;
    }
    for(int i=0;i<n;++i){
        if(!u[i]){
            a[s]=num[i];
            u[i]=1;
            permutation(s+1);
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
        cin>>num[i];
    }

    for(int i=0;i<n;++i){
        a[0]=num[i];
        u[i]=1;
        permutation(1);
        u[i]=0;
    }

    cout<<ans;

    return 0;
}