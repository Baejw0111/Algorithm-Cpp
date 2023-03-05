#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,m;
int a[8]={0},num[8]={0};
//a는 출력할 답을 저장할 배열
//num은 입력된 수들을 저장할 배열

void print(int s,int p){
    if(s==m){
        for(int i=0;i<m;++i){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=p;i<n;++i){
        a[s]=num[i];
        print(s+1,i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    sort(num,num+n);

    for(int i=0;i<n;++i){
        a[0]=num[i];
        print(1,i);
    }

    return 0;
}