#include <bits/stdc++.h>
using namespace std;

int n,ans=0;
int X[14];

int check(int y,int x){
    for(int i=0;i<y;++i){
        if(X[i]==x || abs(i-y)==abs(X[i]-x)){
            return 0;
        }
    }

    return 1;
}

void DFS(int cnt){
    if(cnt==n){
        ++ans;
        return;
    }

    //각 퀸은 cnt번째 행에 놓인다. 즉 y 좌표는 cnt, x좌표는 i
    for(int i=0;i<n;++i){
        if(check(cnt,i)){
            X[cnt]=i;
            DFS(cnt+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    DFS(0);

    cout<<ans;
    return 0;
}