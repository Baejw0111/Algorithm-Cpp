#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n, m, B[4][4] = {0}, ans = 0, U[4][4] = {0};

void permutation(int total, int num)
{
    if (num == n * m)
    {
        ans = max(ans, total);
        return;
    }

    int i = num / m, j = num % m;
    if (!U[i][j])
    {
        int tmp = 0,y=i,x=j+1;
        //세로방향
        for (; y < n; ++y)
        {
            if (!U[y][j])
            {
                tmp *= 10;
                tmp += B[y][j];
                U[y][j] = 1;
                permutation(total + tmp, num + 1);
            }
            else
            {
                break;
            }
        }
        for (int k = i+1; k < y; ++k)
        {
            U[k][j] = 0;
        }

        //가로방향
        tmp = B[i][j];
        for (; x < m; ++x)
        {
            if (!U[i][x])
            {
                tmp *= 10;
                tmp += B[i][x];
                U[i][x] = 1;
                permutation(total + tmp, num + 1);
            }
            else
            {
                break;
            }
        }
        for (int k = j; k < x; ++k)
        {
            U[i][k] = 0;
        }
    }
    else
    {
        permutation(total, num + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
            B[i][j] = str[j] - '0';
    }

    permutation(0, 0);
    cout << ans;

    return 0;
}