#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int e,s,m,ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>e>>s>>m;

    while(1){
        if(e==s && s==m){
            break;
        }
        --e;
        if(e==0){
            e=15;
        }
        --s;
        if(s==0){
            s=28;
        }
        --m;
        if(m==0){
            m=19;
        }
        ++ans;
    }

    cout<<ans+e;

    return 0;
}