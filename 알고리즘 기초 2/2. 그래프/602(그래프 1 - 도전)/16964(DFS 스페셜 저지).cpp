#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=100001;

int n,a[MAX]={0},order[MAX]={0},k=1;
bool visited[MAX]={0},ans=1;
vector<vector<int>> edge(MAX);

bool comp(const int& x,const int& y){
    return order[x]<order[y];
}//입력된 방문 순서를 기준으로 우선순위 정렬

void input(){
    cin>>n;
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1;i<=n;++i){
        cin>>a[i];
        order[a[i]]=i;
    }

    for(int i=1;i<=n;++i){
        sort(edge[i].begin(),edge[i].end(),comp);
    }
}

void dfs(int root){
    visited[root]=1;
    k+=1;
    int s=edge[root].size(),*vecs=&edge[root][0];

    for(int i=0;i<s;++i){
        int ns=*(vecs+i);
        if(a[k]!=ns && visited[ns]==1){
            continue;
        }
        else if(a[k]==ns && visited[ns]==0){
            dfs(a[k]);
        }
        else{
            ans=0;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    if(a[1]==1){
        dfs(1);
    }
    else{
        ans=0;
    }

    cout<<ans;

    return 0;
}