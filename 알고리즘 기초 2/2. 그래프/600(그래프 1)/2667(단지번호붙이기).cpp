#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define ll long long

int n, map[25][25] = {0}, house = 0, complex = 2;
vector<int> complexes;

void complex_finder(int y, int x)
{
    house += 1;
    map[y][x] = complex;
    if (x > 0)
    {
        if (map[y][x - 1] == 1)
        {
            complex_finder(y, x - 1);
        }
    }
    if (x < n - 1)
    {
        if (map[y][x + 1] == 1)
        {
            complex_finder(y, x + 1);
        }
    }
    if (y > 0)
    {
        if (map[y - 1][x] == 1)
        {
            complex_finder(y - 1, x);
        }
    }
    if (y < n - 1)
    {
        if (map[y + 1][x] == 1)
        {
            complex_finder(y + 1, x);
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
                complex_finder(i, j);
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