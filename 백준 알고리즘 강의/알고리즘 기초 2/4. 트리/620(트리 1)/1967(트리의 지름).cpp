#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long
const int MAX=100001;

int n,root,visited[MAX]={0},ans=0;
vector<pair<int,int>> tree[MAX];//노드, 거리

void DFS(int node,int dist){
    visited[node]=1;
    if(dist>ans){
        ans=dist;
        root=node;
    }

    for(int i=0;i<tree[node].size();++i){
        int next_node=tree[node][i].first;
        int next_dist=tree[node][i].second;
        if(!visited[next_node]){
            DFS(next_node,dist+next_dist);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0;i<n-1;++i){
        int v,v1,dist;
        cin>>v>>v1>>dist;

        tree[v].push_back({v1,dist});
        tree[v1].push_back({v,dist});
    }

    DFS(1,0);
    ans=0;
    for(int i=1;i<=n;++i){
        visited[i]=0;
    }
    DFS(root,0);

    cout<<ans;

    return 0;
}