#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define lli long long int

int a[1000][3]={0},n,ans=0;

int main(){
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>a[i][0];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            if(a[j][0]<a[i][0] && a[j][1]>a[i][1]){
                a[i][1]=a[j][1];
            }
        }
        a[i][1]+=1;
    }

    for(int i=n-1;i>=0;--i){
        for(int j=n-1;j>i;--j){
            if(a[j][0]<a[i][0] && a[j][2]>a[i][2]){
                a[i][2]=a[j][2];
            }
        }
        a[i][2]+=1;
    }

    for(int i=0;i<n;++i){
        if(ans<a[i][1]+a[i][2]){
            ans=a[i][1]+a[i][2];
        }
    }

    cout<<ans-1;

    return 0;
}