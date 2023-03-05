#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long
ll n,a[31][5]={0},ans;

int main(){
    cin>>n;
    if(n%2==1){
        cout<<0;
        return 0;
    }

    for(int i=0;i<3;++i){
        a[1][i]=1;
    }

    for(int i=2;i<=n;++i){
        if(i%2==1){
            a[i][0]=a[i-1][0]+a[i-1][1]+a[i-1][3];
            a[i][1]=a[i-1][0]+a[i-1][1]+a[i-1][2]+a[i-1][3];
            a[i][2]=a[i-1][0]+a[i-1][1]+a[i-1][3]+a[i-1][4];
        }
        else{
            a[i][0]=a[i-1][0];
            a[i][1]=a[i-1][1];
            a[i][2]=a[i-1][1];
            a[i][3]=a[i-1][2];
            a[i][4]=a[i-1][2];
        }
    }

    ans=a[n][0]+a[n][1]+a[n][3];

    cout<<ans;

    return 0;
}