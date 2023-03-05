#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,S[20][20]={0},u[20]={0},ans=0;

void split(int s,int p,int num){
    if(s==num){
        int start=0,link=0;
        for(int i=0;i<n;++i){
            if(u[i]){
                for(int j=0;j<n;++j){
                    if(u[j]){
                        start+=S[i][j]+S[j][i];
                    }
                }
            }
            else{
                for(int j=0;j<n;++j){
                    if(!u[j]){
                        link+=S[i][j]+S[j][i];
                    }
                }
            }
        }
        start/=2;
        link/=2;

        ans=min(ans,abs(start-link));
        return;
    }
    for(int i=p+1;i<=n-num+s;++i){
        u[i]=1;
        split(s+1,i,num);
        u[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>S[i][j];
            ans+=S[i][j];
        }
    }

    for(int i=1;i<=n/2;++i){
        split(0,-1,i);
    }
    cout<<ans;

    return 0;
}