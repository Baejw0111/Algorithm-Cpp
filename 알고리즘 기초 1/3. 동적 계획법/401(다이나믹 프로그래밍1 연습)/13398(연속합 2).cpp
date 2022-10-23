#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long
ll n,a[100000][3]={0},ans;

int main(){
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>a[i][0];
    }

    a[0][1]=a[0][0];
    ans=a[0][1];

    for(int i=1;i<n;++i){
        a[i][1]=max(a[i-1][1]+a[i][0],a[i][0]);
        a[i][2]=max(a[i-1][2]+a[i][0],a[i-1][1]);

        ans=max(a[i][1],max(ans,a[i][2]));
    }

    cout<<ans;

    return 0;
}