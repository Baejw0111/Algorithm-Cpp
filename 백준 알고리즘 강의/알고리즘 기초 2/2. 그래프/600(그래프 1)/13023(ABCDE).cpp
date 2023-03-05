#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define ll long long

int n,m;
bool ans=0,U[2000]={0};
vector<vector<int>> F(2000);
//사이클 형성시 패스

void rel(int num,int s){
    if(ans){
        return;
    }
    if(num==5){
        ans=1;
        return;
    }
    for(int i:F[s]){
        if(!U[i]){
            U[i]=1;
            rel(num+1,i);
            U[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        F[a].push_back(b);
        F[b].push_back(a);
    }

    for(int i=0;i<n;++i){
        U[i]=1;
        rel(1,i);
        U[i]=0;
        if(ans){
            break;
        }
    }

    cout<<ans;
    return 0;
}