#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define lli long long int

int a[1000][2]={0},n,ans=0;

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
        if(ans<a[i][1]){
            ans=a[i][1];
        }
    }

    cout<<ans;

    return 0;
}