#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,m;
int a[8]={0},u[9]={0};
//a는 출력할 답을 저장할 배열
//u는 숫자의 사용 여부를 저장할 배열

void print(int s){
    if(s==m){
        for(int i=0;i<m;++i){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;++i){
        if(!u[i]){
            a[s]=i;
            u[i]=1;
            print(s+1);
            u[i]=0;
        }
        else{
            continue;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    print(0);

    return 0;
}