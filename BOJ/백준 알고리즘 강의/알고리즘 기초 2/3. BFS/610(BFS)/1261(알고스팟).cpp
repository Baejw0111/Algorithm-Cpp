#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=100;

int n,m,maze[MAX][MAX]={0},visited[MAX][MAX]={0},wall[MAX][MAX]={0};
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};

struct cmp{
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        if(wall[p1.first][p1.second]>wall[p2.first][p2.second]){
            return true;
        }//부순 벽 개수에 따라 우선순위 부여
        else{
            return false;
        }
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;

void bfs(){
    q.push({0,0});
    visited[0][0]=1;

    while(!q.empty()){
        int x=q.top().first,y=q.top().second;
        q.pop();
        if(x==n-1 && y==m-1){
            cout<<wall[x][y]<<endl;
            return;
        }

        for(int i=0;i<4;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(nx<n && nx>=0 && ny<m && ny>=0){
                if(visited[nx][ny]==0){
                    visited[nx][ny]=1;
                    wall[nx][ny]=wall[x][y]+maze[nx][ny];
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m>>n;
    for(int i=0;i<n;++i){
        string str;
        cin>>str;
        for(int j=0;j<m;++j){
            maze[i][j]=str[j]-'0';
        }
    }

    bfs();

    return 0;
}