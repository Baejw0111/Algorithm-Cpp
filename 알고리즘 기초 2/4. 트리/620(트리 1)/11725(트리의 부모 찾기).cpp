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

int n,visited[MAX]={0},ans[MAX]={0};
vector<int> tree[MAX];
queue<int> q;

void bfs(){
    q.push(1);
    visited[1]=1;

    while(!q.empty()){
        int p=q.front();
        q.pop();

        for(int i=0;i<tree[p].size();++i){
            int c=tree[p][i];
            if(!visited[c]){
                q.push(c);
                visited[c]=1;
                ans[c]=p;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    bfs();

    for(int i=2;i<=n;++i){
        cout<<ans[i]<<'\n';
    }

    return 0;
}