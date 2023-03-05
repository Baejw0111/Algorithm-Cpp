#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define lli long long int

lli a[91][2]={0},n;

int main(){
    cin>>n;

    a[1][0]=0;
    a[1][1]=1;

    for(int i=2;i<=n;++i){
        a[i][0]=a[i-1][0]+a[i-1][1];
        a[i][1]=a[i-1][0];
    }

    cout<<a[n][0]+a[n][1];

    return 0;
}