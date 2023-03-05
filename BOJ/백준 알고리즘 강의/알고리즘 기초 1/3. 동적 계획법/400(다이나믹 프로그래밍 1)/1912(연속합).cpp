#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define lli long long int

lli n,a[100000][2]={0},ans=0;

int main(){
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>a[i][0];
    }

    a[0][1]=a[0][0];
    ans=a[0][1];

    for(int i=1;i<n;++i){
        a[i][1]=max(a[i-1][1]+a[i][0],a[i][0]);

        if(ans<a[i][1]){
            ans=a[i][1];
        }
    }

    cout<<ans;

    return 0;
}