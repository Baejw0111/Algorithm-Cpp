#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

ll n,p[100001][3]={0},ans=0,d=9901;

int main(){
    cin>>n;

    p[1][0]=1;
    p[1][1]=1;
    p[1][2]=1;

    for(int i=2;i<=n;++i){
        p[i][0]=(p[i-1][0]+p[i-1][1]+p[i-1][2])%d;
        p[i][1]=(p[i-1][0]+p[i-1][2])%d;
        p[i][2]=(p[i-1][0]+p[i-1][1])%d;
    }

    for(int i=0;i<3;++i){
        ans+=p[n][i];
        ans%=d;
    }

    cout<<ans;

    return 0;
}