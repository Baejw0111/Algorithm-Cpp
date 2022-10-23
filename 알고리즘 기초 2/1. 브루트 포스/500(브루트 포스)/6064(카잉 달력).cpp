#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int t,m,n,x,y,ans,g,d;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>t;
    while(t--){
        ans=0;
        cin>>m>>n>>x>>y;

        g=gcd(m,n);

        if(abs(x-y)%g!=0){
            cout<<-1<<endl;
            continue;
        }

        while(1){
            if(x==y){
                break;
            }
            d=min(x,y);
            x-=d;
            y-=d;
            if(x==0){
                x=m;
            }
            if(y==0){
                y=n;
            }
            ans+=d;
        }

        cout<<ans+x<<endl;

    }


    return 0;
}