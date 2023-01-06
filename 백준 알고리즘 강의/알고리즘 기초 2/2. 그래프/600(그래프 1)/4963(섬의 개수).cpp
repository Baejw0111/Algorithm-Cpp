#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define ll long long

struct coor{
    int x,y;
};

int t,h,w, map[51][51] = {0}, island = 0;
queue<coor> q;

void bfs(int i,int j)
{
    q.push({j,i});
    map[i][j] = island;

    int x,y;
    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        q.pop();

        if (x > 0)
        {
            if (map[y][x - 1] == 1)
            {
                q.push({x-1,y});
                map[y][x-1] = island;
            }
            if (y > 0)
            {
                if (map[y - 1][x-1] == 1)
                {
                    q.push({x-1,y-1});
                    map[y-1][x-1] = island;
                }
            }
            if (y < h - 1)
            {
                if (map[y + 1][x-1] == 1)
                {
                    q.push({x-1,y+1});
                    map[y+1][x-1] = island;
                }
            }
        }
        if (x < w - 1)
        {
            if (map[y][x + 1] == 1)
            {
                q.push({x+1,y});
                map[y][x+1] = island;
            }
            if (y > 0)
            {
                if (map[y - 1][x+1] == 1)
                {
                    q.push({x+1,y-1});
                    map[y-1][x+1] = island;
                }
            }
            if (y < h - 1)
            {
                if (map[y + 1][x+1] == 1)
                {
                    q.push({x+1,y+1});
                    map[y+1][x+1] = island;
                }
            }
        }
        if (y > 0)
        {
            if (map[y - 1][x] == 1)
            {
                q.push({x,y-1});
                map[y-1][x] = island;
            }
        }
        if (y < h - 1)
        {
            if (map[y + 1][x] == 1)
            {
                q.push({x,y+1});
                map[y+1][x] = island;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(1){
        cin>>w>>h;
        if(w+h==0){
            break;
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin>>map[i][j];
            }
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (map[i][j] == 1)
                {
                    if(island==0){
                        island=2;
                    }
                    bfs(i,j);
                    island+=1;
                }
            }
        }

        if(island==0){
            cout<<island<<'\n';
        }
        else{
            cout<<island-2<<'\n';
        }
        island=0;
    }


    return 0;
}