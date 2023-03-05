#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,T[15]={0},P[15]={0},ans=0;

void maximize(int s,int total){
    if(s>=n){
        ans=max(ans,total);
        return;
    }
    for(int i=s;i<n;++i){
        if(i+T[i]>n){
            maximize(i+T[i],total);
        }
        else{
            maximize(i+T[i],total+P[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>T[i]>>P[i];
    }

    maximize(0,0);
    cout<<ans;

    return 0;
}