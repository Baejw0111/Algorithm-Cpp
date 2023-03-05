#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int n,m,maze[100][100]={0},ans=200;
int mx[4]={0,0,1,-1};
int my[4]={1,-1,0,0};
queue<pair<int,int>> q;

void bfs(){
    int x=0,y=0;
    q.push({x,y});

    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]==1 && (nx!=0 || ny!=0)){
                q.push({nx,ny});
                if(maze[nx][ny]!=1){
                    maze[nx][ny]=min(maze[x][y]+1,maze[nx][ny]);
                }
                else{
                    maze[nx][ny]=maze[x][y]+1;
                }
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j)
        {
            maze[i][j] = str[j] - '0';
        }
    }

    bfs();

    cout<<maze[n-1][m-1];

    return 0;
}