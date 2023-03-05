#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define ll long long

short n;
ll a[500][500]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    cin>>n;

    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            cin>>a[i][j];
        }
    }

    for(int i=n-2;i>=0;--i){
        for(int j=0;j<=i;++j){
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }

    cout<<a[0][0];

    return 0;
}