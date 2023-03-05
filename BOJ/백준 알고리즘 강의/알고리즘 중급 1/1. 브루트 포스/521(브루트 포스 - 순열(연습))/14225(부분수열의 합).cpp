#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

const int MAX=2000001;

int n,S[20]={0},u[20]={0},sum[MAX]={0},total=0;

void permutation(int s,int p,int num){
    if(s==num){
        sum[total]=1;
        return;
    }
    for(int i=p+1;i<n-num+s+1;++i){
        if(!u[i]){
            total+=S[i];
            u[i]=1;
            permutation(s+1,i,num);
            total-=S[i];
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
        cin>>S[i];
    }

    sort(S,S+1);

    for(int i=1;i<=n;++i){
        permutation(0,-1,i);
    }

    int i=1;
    for(;i<MAX;++i){
        if(sum[i]==0){
            cout<<i;
            return 0;
        }
    }
    cout<<i;

    return 0;
}