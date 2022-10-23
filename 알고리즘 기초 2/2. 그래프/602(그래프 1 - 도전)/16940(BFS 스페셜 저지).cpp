#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=100001;

int n,a[MAX]={0},order[MAX]={0};
bool visited[MAX]={0},ans=0;
vector<vector<int>> edge(MAX);
queue<int> q;

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

void bfs(){
    if(a[1]!=1){
        return;
    }

    q.push(1);
    visited[1]=1;
    int k=2;

    while(!q.empty()){
        int cur=q.front(),s=edge[cur].size(),*vecs=&edge[cur][0];
        q.pop();
        
        for(int i=0;i<s;++i){
            int ns=*(vecs+i);
            if(a[k]!=ns){
                if(visited[ns]){
                    continue;
                }
                else{
                    return;
                }
            }
            else{
                if(visited[ns]){
                    return;
                }
                else{
                    q.push(a[k]);
                    visited[a[k]]=1;
                    k+=1;
                }
            }
        }
    }

    ans=1;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    bfs();

    cout<<ans;

    return 0;
}