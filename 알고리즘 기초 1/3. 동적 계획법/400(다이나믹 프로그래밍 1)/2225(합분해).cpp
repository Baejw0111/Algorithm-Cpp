#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define ll long long

short n,k;
ll a[201][200]={0},ans=0,d=1000000000;
//a[n][k]

int main(){
    cin>>n>>k;

    for(int i=0;i<k;++i){
        for(int j=0;j<=n;++j){
            if(i==0){
                a[j][i]=1;
            }
            else if(i==k-1){
                a[n][i]+=a[n-j][i-1];
                a[n][i]%=d;
            }
            else{
                for(int l=0;l<=n;++l){
                    if(j+l<=n){
                        a[j+l][i]+=a[l][i-1];
                        a[j+l][i]%=d;
                    }
                }
            }
        }
    }

    cout<<a[n][k-1];

    return 0;
}