#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

int k,V,E,ans=1;
vector<int> DFSstat(20001);
vector<vector<int>> edge(20001);

void dfs(int root,int state){
    DFSstat[root]=state;
    for(int i=0;i<edge[root].size();++i){
        if(DFSstat[edge[root][i]]==0){
            dfs(edge[root][i],state*-1);
        }
        else if(DFSstat[edge[root][i]]==state){
            ans=0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k;
    while(k--){
        cin>>V>>E;
        for(int i=0;i<E;++i){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(int i=1;i<=V;++i){
            if(DFSstat[i]==0){
                dfs(i,1);
            }
        }
        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

        //각 요소들 초기화
        ans=1;
        DFSstat.assign(V+1,0);
        for(int i=1;i<=V;++i){
            edge[i].clear();
        }
    }


    return 0;
}