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

    for(int i=0;i<n;++i){
        int v;
        cin>>v;
        while(1){
            int v1,dist;
            cin>>v1;
            if(v1==-1){
                break;
            }
            cin>>dist;
            tree[v].push_back({v1,dist});
        }
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
//트리의 지름을 구하는 방법은 임의의 한 정점에서 가장 먼 정점을 찾아낸 후
//그 정점에서 가장 먼 정점까지의 거리를 구하면 된다.
//엄청 단순화해서 생각해서 15cm 자를 생각해보면 쉽게 이해할 수 있다.