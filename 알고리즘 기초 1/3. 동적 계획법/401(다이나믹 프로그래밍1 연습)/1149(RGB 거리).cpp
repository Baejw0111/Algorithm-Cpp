#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

ll n,p[1001][3]={0},m[1001][3]={0},ans;

int main(){
    cin>>n;

    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j){
            cin>>p[i][j];
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j){
            m[i][j]=min(m[i-1][(j+1)%3],m[i-1][(j+2)%3])+p[i][j];
        }
    }

    ans=min(m[n][0],min(m[n][1],m[n][2]));
    
    cout<<ans;

    return 0;
}