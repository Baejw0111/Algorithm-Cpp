#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,m;
void print(int a[8],int s){
    if(s==m){
        for(int i=0;i<m;++i){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=a[s-1]+1;i<=n-m+s+1;++i){
        a[s]=i;
        print(a,s+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[8]={0};
    //a는 출력할 답을 저장할 배열
    cin>>n>>m;

    for(int i=1;i<=n-m+1;++i){
        a[0]=i;
        print(a,1);
    }

    return 0;
}