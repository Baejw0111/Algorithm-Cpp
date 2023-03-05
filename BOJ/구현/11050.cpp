#include <iostream>
#include <string>
using namespace std;

//이항 계수 1

int main(){
    int n,k,ans=1;
    cin>>n>>k;

    for(int i=n;i>n-k;--i){
        ans*=i;
    }
    for(int i=1;i<=k;++i){
        ans/=i;
    }

    cout<<ans;

    return 0;
}