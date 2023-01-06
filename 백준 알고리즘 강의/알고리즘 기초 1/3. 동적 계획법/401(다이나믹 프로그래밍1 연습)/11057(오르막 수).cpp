#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

ll n,p[1001][10]={0},ans=0,d=10007;

int main(){
    cin>>n;

    for(int i=0;i<10;++i){
        p[1][i]=1;
    }
    for(int i=2;i<=n;++i){
        for(int j=0;j<10;++j){
            for(int k=j;k<10;++k){
                p[i][k]=(p[i][k]+p[i-1][j])%d;
            }
        }
    }

    for(int i=0;i<10;++i){
        ans+=p[n][i];
        ans%=d;
    }

    cout<<ans;

    return 0;
}