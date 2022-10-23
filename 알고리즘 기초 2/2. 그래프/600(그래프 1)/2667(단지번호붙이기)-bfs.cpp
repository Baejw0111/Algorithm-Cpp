#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

struct coor{
    int x,y;
};

int n, map[25][25] = {0}, house = 0, complex = 2;
vector<int> complexes;
queue<coor> q;

void bfs(int i,int j)
{
    q.push({j,i});
    map[i][j] = complex;

    int x,y;

    while(!q.empty()){
        x=q.front().x;
        y=q.front().y;
        q.pop();
        house+=1;

        if (x > 0)
        {
            if (map[y][x - 1] == 1)
            {
                q.push({x-1,y});
                map[y][x-1] = complex;
            }
        }
        if (x < n - 1)
        {
            if (map[y][x + 1] == 1)
            {
                q.push({x+1,y});
                map[y][x+1] = complex;
            }
        }
        if (y > 0)
        {
            if (map[y - 1][x] == 1)
            {
                q.push({x,y-1});
                map[y-1][x] = complex;
            }
        }
        if (y < n - 1)
        {
            if (map[y + 1][x] == 1)
            {
                q.push({x,y+1});
                map[y+1][x] = complex;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; ++j)
        {
            map[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (house == 0 && map[i][j] == 1)
            {
                bfs(i, j);
                complexes.push_back(house);
                complex += 1;
                house = 0;
            }
        }
    }
    sort(complexes.begin(), complexes.end());

    cout << complexes.size() << '\n';
    for (int i = 0; i < complexes.size(); ++i)
    {
        cout << complexes[i] << '\n';
    }

    return 0;
}