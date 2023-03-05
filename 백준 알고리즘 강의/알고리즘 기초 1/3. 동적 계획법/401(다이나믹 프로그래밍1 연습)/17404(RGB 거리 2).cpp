#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

ll n,p[1001][3]={0},m[1001][3][3]={0},ans[4]={0};
//m[1001][i][j]: i는 첫번째 색깔, j는 가격

int main(){
    cin>>n;

    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j){
            cin>>p[i][j];
        }
    }

    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(j!=i){
                m[1][i][j]=1001;
                continue;
            }
            m[1][i][j]=p[1][i];
        }
    }

    for(int i=0;i<3;++i){
        for(int j=2;j<n;++j){
            m[j][i][0]=min(m[j-1][i][1],m[j-1][i][2])+p[j][0];
            m[j][i][1]=min(m[j-1][i][0],m[j-1][i][2])+p[j][1];
            m[j][i][2]=min(m[j-1][i][1],m[j-1][i][0])+p[j][2];
        }
        for(int j=0;j<3;++j){
            if(i==j){
                continue;
            }
            m[n][i][j]=min(m[n-1][i][(j+1)%3],m[n-1][i][(j+2)%3])+p[n][j];
        }
        ans[i]=min(m[n][i][(i+1)%3],m[n][i][(i+2)%3]);
    }

    ans[3]=min(ans[0],min(ans[1],ans[2]));
    
    cout<<ans[3]<<endl;

    // for(int i=0;i<3;++i){
    //     for(int j=0;j<3;++j){
    //         for(int k=1;k<=n;++k){
    //             cout<<m[k][i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    return 0;
}