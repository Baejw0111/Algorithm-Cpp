#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

int n,m,V,DFSstat[1001]={0},BFSstat[1001]={0};
vector<vector<int>> edge(1001);
queue<int> BFS;

void dfs(int root){
    cout<<root<<" ";
    DFSstat[root]+=1;
    for(int i=0;i<edge[root].size();++i){
        if(DFSstat[edge[root][i]]==0){
            dfs(edge[root][i]);
        }
    }
}

void bfs(){
    BFS.push(V);
    BFSstat[V]+=1;
    while(BFS.size()!=0){
        for(int i=0;i<edge[BFS.front()].size();++i){
            if(BFSstat[edge[BFS.front()][i]]==0){
                BFS.push(edge[BFS.front()][i]);
                BFSstat[edge[BFS.front()][i]]+=1;
            }
        }

        cout<<BFS.front()<<" ";
        BFS.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>V;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        sort(edge[a].begin(),edge[a].end());
        sort(edge[b].begin(),edge[b].end());
    }

    dfs(V);
    cout<<'\n';
    bfs();

    return 0;
}