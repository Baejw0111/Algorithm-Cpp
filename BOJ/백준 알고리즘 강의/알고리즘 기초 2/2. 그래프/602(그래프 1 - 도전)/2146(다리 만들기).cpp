#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
const int MAX=100;

int n,map[MAX][MAX]={0},ans=9999;
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};

void island_finder(int a,int b,int island){
    queue<pair<int,int>> q;

    q.push({a,b});
    map[a][b]=island;

    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(map[nx][ny]==1){
                    q.push({nx,ny});
                    map[nx][ny]=island;
                }
            }
        }
    }
}

void bfs(int a,int b){
    int visited[MAX][MAX]={0};
    queue<pair<int,int>> q;

    q.push({a,b});
    visited[a][b]=1;

    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(map[nx][ny]==0 && visited[nx][ny]==0){
                    if(visited[nx][ny]==0){
                        q.push({nx,ny});
                        visited[nx][ny]=visited[x][y]+1;
                    }
                    else if(visited[nx][ny]>0){
                        q.push({nx,ny});
                        visited[nx][ny]=min(visited[nx][ny],visited[x][y]+1);
                    }
                }
                else if(map[nx][ny]!=0 && map[a][b]!=map[nx][ny]){
                    ans=min(ans,visited[x][y]-1);
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
        for(int j=0;j<n;++j){
            cin>>map[i][j];
        }
    }

    int island=2;
    queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(map[i][j]==1){
                island_finder(i,j,island);
                island+=1;
            }
        }
    }

    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         cout<<map[i][j];
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(map[i][j]>0){
                int s=0;
                for(int k=0;k<4;++k){
                    int nx=i+mx[k],ny=j+my[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<n){
                        if(map[nx][ny]==0){
                            s=1;
                            break;
                        }
                    }
                }

                if(s){
                    bfs(i,j);
                }

            }
        }
    }

    cout<<ans;

    return 0;
}