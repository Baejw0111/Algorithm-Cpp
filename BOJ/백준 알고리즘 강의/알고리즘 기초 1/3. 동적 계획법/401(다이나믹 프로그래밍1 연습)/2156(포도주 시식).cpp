#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

short vine[10001]={0};
ll n,p[10001][3]={0},ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    cin>>n;

    for(int i=1;i<=n;++i){
        cin>>vine[i];
    }

    for(int i=1;i<=n;++i){
        p[i][0]=max(max(p[i-1][0],p[i-1][1]),p[i-1][2]);
        p[i][1]=p[i-1][0]+vine[i];
        if(p[i-1][1]!=0){
            p[i][2]=p[i-1][1]+vine[i];
        }
    }

    ans=max(max(p[n][0],p[n][1]),p[n][2]);

    cout<<ans;

    return 0;
}