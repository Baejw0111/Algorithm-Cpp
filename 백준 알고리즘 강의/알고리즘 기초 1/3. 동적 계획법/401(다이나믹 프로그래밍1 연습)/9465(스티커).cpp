#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

short score[100001][2]={0};
//각 스티커 별 점수 저장
ll t,n,p[100001][3]={0},ans=0;
//p는 길이가 n일 경우

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    cin>>t;

    for(int i=0;i<t;++i){
        cin>>n;
        for(int j=0;j<2;++j){
            for(int k=1;k<=n;++k){
                cin>>score[k][j];
            }
        }
        for(int j=1;j<=n;++j){
            p[j][0]=max(p[j-1][1],p[j-1][2]);
            p[j][1]=max(p[j-1][0],p[j-1][2])+score[j][0];
            p[j][2]=max(p[j-1][1],p[j-1][0])+score[j][1];
        }

        ans=max(p[n][0],max(p[n][1],p[n][2]));

        cout<<ans<<'\n';
    }

    return 0;
}