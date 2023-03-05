#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=100001;

int n,k,visited[MAX]={0};
queue<int> q;

void bfs(){
    q.push(n);
    visited[n]=1;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(x+1<MAX){
            if(visited[x+1]==0){
                q.push(x+1);
                visited[x+1]=visited[x]+1;
                if(x+1==k){
                    cout<<visited[x];
                    return;
                }
            }
        }

        if(x-1>=0){
            if(visited[x-1]==0){
                q.push(x-1);
                visited[x-1]=visited[x]+1;
                if(x-1==k){
                    cout<<visited[x];
                    return;
                }
            }
        }

        if(2*x<MAX){
            if(visited[2*x]==0){
                q.push(2*x);
                visited[2*x]=visited[x]+1;
                if(2*x==k){
                    cout<<visited[x];
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    if(n==k){
        cout<<0;
    }
    else{
        bfs();
    }

    return 0;
}