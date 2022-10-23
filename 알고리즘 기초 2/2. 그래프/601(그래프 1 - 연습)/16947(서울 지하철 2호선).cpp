#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int n,visited[3001]={0};
vector<vector<int>> E(3001);

void dfs_cycle(int root,int ps){
    visited[root]=1;
    int s=E[root].size(),*vecs=&E[root][0];

    for(int i=0;i<s;++i){
        int ns=*(vecs+i);
        if(ns==ps){
            continue;
        }

        if(visited[ns]==1){
            visited[ns]=-1;
            visited[root]=-1;
        }
        else if(visited[ns]==0){
            dfs_cycle(ns,root);
            if(visited[ns]==-1){
                if(visited[root]==1){
                    visited[root]=-1;
                }
                else if(visited[root]==-1){
                    visited[root]=-2;
                }
            }
        }
    }

}

int bfs_dist(int root){
    if(visited[root]<0){
        return 0;
    }

    queue<int> q;
    q.push(root);
    int v[3001]={0};
    v[root]=1;

    while(1){
        int cs=q.front(),s=E[cs].size(),*vecs=&E[cs][0];
        q.pop();

        for(int i=0;i<s;++i){
            int ns=*(vecs+i);
            if(v[ns]==0){
                if(visited[ns]<0){
                    return v[cs];
                }
                else if(v[ns]==0){
                    q.push(ns);
                    v[ns]=v[cs]+1;
                }
            }
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;

        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs_cycle(1,0);

    for(int i=1;i<=n;++i){
        cout<<bfs_dist(i)<<" ";
    }

    return 0;
}