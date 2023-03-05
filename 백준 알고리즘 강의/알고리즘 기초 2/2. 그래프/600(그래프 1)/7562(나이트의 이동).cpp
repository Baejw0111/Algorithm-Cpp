#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int t,I,cx,cy,dx,dy;
int mx[8]={2,2,1,1,-1,-1,-2,-2},my[8]={1,-1,2,-2,2,-2,1,-1};


int bfs(){
    queue<pair<int,int>> q;
    int s=1,ans=0,board[300][300]={0};
    q.push({cx,cy});
    board[cx][cy]=1;

    if(cx==dx && cy==dy){
        s=0;
    }

    while(s){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<8;++i){
            int nx=x+mx[i],ny=y+my[i];
            if(nx>=0 && nx<I && ny>=0 && ny<I && board[nx][ny]==0){
                // cout<<nx<<" "<<ny<<" "<<m<<'\n';
                if(nx==dx && ny==dy){
                    s=0;
                    ans=board[x][y];
                    break;
                }
                q.push({nx,ny});
                board[nx][ny]=board[x][y]+1;
            }
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;

    while(t--){
        cin>>I>>cx>>cy>>dx>>dy;
        cout<<bfs()<<'\n';
    }

    return 0;
}