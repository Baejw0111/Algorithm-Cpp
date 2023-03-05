#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define lli long long int

short a[100001]={0};
int n,q,m,tmp;

int main(){
    cin>>n;

    for(int i=1;i<=n;++i){
        q=(int)sqrt(i);
        m=a[i-q*q]+1;
        for(int j=1;j<=q;++j){
            tmp=1+a[i-j*j];
            if(m>tmp){
                m=tmp;
            }
        }
        a[i]=m;
    }

    cout<<a[n];

    return 0;
}