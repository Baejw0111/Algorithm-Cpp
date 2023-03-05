#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int n,m,visited[50][50]={0},ans=0;
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};
char board[50][50]={0};

void bfs(int cx,int cy){
    queue<pair<int,int>> q;
    q.push({cx,cy});
    visited[cx][cy]=1;
    char color=board[cx][cy];

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]==color){
                if(visited[nx][ny]==visited[x][y]+1){
                    ans=1;
                    break;
                }
                else if(visited[nx][ny]==0){
                    q.push({nx,ny});
                    visited[nx][ny]=visited[x][y]+1;
                }
            }
        }
        if(ans){
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<n;++i){
        string str;
        cin>>str;

        for(int j=0;j<m;++j){
            board[i][j]=str[j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(visited[i][j]==0){
                bfs(i,j);
            }
            if(ans){
                cout<<"Yes";
                return 0;
            }
        }
    }

    cout<<"No";

    return 0;
}