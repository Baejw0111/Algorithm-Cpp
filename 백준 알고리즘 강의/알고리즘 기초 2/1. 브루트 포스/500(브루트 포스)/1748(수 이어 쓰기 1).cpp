#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define ll long long

ll n,len,ans=0,x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    len=(int)log10(n)+1;

    x=1;
    y=10;

    for(int i=1;i<len;++i){
        ans+=(y-x)*i;
        x=y;
        y*=10;
    }

    ans+=(n-x+1)*len;

    cout<<ans;

    return 0;
}