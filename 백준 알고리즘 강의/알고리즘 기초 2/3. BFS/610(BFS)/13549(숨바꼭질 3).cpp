#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=100001;

int n,k,visited[MAX][2]={0};
//인덱스 0에는 방문 여부, 인덱스 1에는 시간을 저장한다.
struct cmp{
    bool operator()(int n1,int n2){
        if(visited[n1][1]>visited[n2][1]){
            return true;
        }//시간에 따라 우선순위 부여
        else{
            return false;
        }
    }
};

priority_queue<int,vector<int>,cmp> q;

void bfs(){
    q.push(n);
    visited[n][0]=1;
    visited[n][1]=0;

    while(!q.empty()){
        int x=q.top();
        q.pop();

        if(x==k){
            cout<<visited[x][1];
            return;
        }

        if(2*x<MAX){
            if(visited[2*x][0]==0||visited[2*x][1]>visited[x][1]){
                visited[2*x][0]=1;
                visited[2*x][1]=visited[x][1];
                q.push(2*x);
            }
        }

        if(x+1<MAX){
            if(visited[x+1][0]==0||visited[x+1][1]>visited[x][1]+1){
                visited[x+1][0]=1;
                visited[x+1][1]=visited[x][1]+1;
                q.push(x+1);
            }
        }

        if(x-1>=0){
            if(visited[x-1][0]==0||visited[x-1][1]>visited[x][1]+1){
                visited[x-1][0]=1;
                visited[x-1][1]=visited[x][1]+1;
                q.push(x-1);
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
        cout<<0;
    }
    else{
        bfs();
    }
    return 0;
}