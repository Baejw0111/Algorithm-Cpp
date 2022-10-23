#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

long int a[101][10]={0};

int main(){
    long int d=1000000000;
    int n;
    cin>>n;

    a[1][0]=0;
    for(int i=1;i<9;++i){
        a[1][i]=1;
    }
    a[1][9]=1;

    for(int i=2;i<=n;++i){
        a[i][0]=(a[i-1][1])%d;
        for(int j=1;j<9;++j){
            a[i][j]=(a[i-1][j-1]+a[i-1][j+1])%d;
        }
        a[i][9]=(a[i-1][8])%d;
    }

    long int ans=0;
    for(int i=0;i<10;++i){
        ans+=a[n][i];
        ans%=d;
    }

    cout<<ans;

    return 0;
}