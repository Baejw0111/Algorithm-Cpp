#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int m,n,storage[1000][1000]={0},ans=-1,day=0,total=0,change=0,emptied=0;
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};
queue<pair<int,int>> q;
//다음날 익을 토마토들의 위치를 저장할 큐

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m>>n;

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>storage[i][j];
            if(storage[i][j]==1){
                total+=1;
                q.push({i,j});
            }
            else if(storage[i][j]==-1){
                emptied+=1;
            }
        }
    }

    while(1){
        if(total==n*m-emptied){
            ans=day;
        }
        int s=q.size();
        for(int i=0;i<s;++i){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            if(storage[x][y]==1){
                for(int k=0;k<4;++k){
                    int nx=x+mx[k],ny=y+my[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && storage[nx][ny]==0){
                        change=1;
                        storage[nx][ny]=1;
                        total+=1;
                        q.push({nx,ny});
                    }
                }
            }

        }
        day+=1;
        if(change==0){
            break;
        }
        change=0;

        // cout<<"\nday:"<<day<<'\n';
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         cout<<storage[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
    }

    cout<<ans;

    return 0;
}