#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
const int MAX=100001;

int n,k,visited[MAX][2]={0};
queue<int> q;

void backtracking(int x){
    stack<int> s;

    int p=x;
    s.push(p);

    while(visited[p][1]!=p){
        p=visited[p][1];
        s.push(p);
    }

    while(s.size()!=0){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void bfs(){
    q.push(n);
    visited[n][0]=1;
    visited[n][1]=n;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        if(x+1<MAX){
            if(visited[x+1][0]==0){
                q.push(x+1);
                visited[x+1][0]=visited[x][0]+1;
                visited[x+1][1]=x;
                if(x+1==k){
                    cout<<visited[x][0]<<'\n';
                    backtracking(x+1);
                    return;
                }
            }
        }

        if(x-1>=0){
            if(visited[x-1][0]==0){
                q.push(x-1);
                visited[x-1][0]=visited[x][0]+1;
                visited[x-1][1]=x;
                if(x-1==k){
                    cout<<visited[x][0]<<'\n';
                    backtracking(x-1);
                    return;
                }
            }
        }

        if(2*x<MAX){
            if(visited[2*x][0]==0){
                q.push(2*x);
                visited[2*x][0]=visited[x][0]+1;
                visited[2*x][1]=x;
                if(2*x==k){
                    cout<<visited[x][0]<<'\n';
                    backtracking(2*x);
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
        cout<<0<<'\n'<<n;
    }
    else{
        bfs();
    }

    return 0;
}