#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

int n,m,visited[1001]={0},visitNum=0,ans=0;
//0: ready, 1: wait 2: processed
vector<vector<int>> edge(1001);
queue<int> BFS;

void bfs(int root){
    BFS.push(root);
    visited[root]+=1;
    visitNum+=1;
    while(BFS.size()!=0){
        for(int i=0;i<edge[BFS.front()].size();++i){
            if(visited[edge[BFS.front()][i]]==0){
                BFS.push(edge[BFS.front()][i]);
                visited[edge[BFS.front()][i]]+=1;
                visitNum+=1;
            }
        }

        BFS.pop();
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
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    while(visitNum!=n){
        for(int i=1;i<=n;++i){
            if(visited[i]==0){
                bfs(i);
                ans+=1;
            }
        }
    }

    cout<<ans;

    return 0;
}