#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,m;
int a[8]={0},u[8]={0},num[8]={0};
//a는 출력할 답을 저장할 배열
//u는 숫자의 사용 여부를 저장할 배열
//num은 입력된 수들을 저장할 배열

void print(int s){
    if(s==m){
        for(int i=0;i<m;++i){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;++i){
        if(i!=0 && num[i]==num[i-1] && !u[i-1]){
        //방금 쓴 숫자와 동일할 경우 패스
            continue;
        }
        else if(!u[i]){
            a[s]=num[i];
            u[i]=1;
            print(s+1);
            u[i]=0;
        }
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
        if(i!=0 && num[i]==num[i-1]){
            continue;
        }
        else{
            a[0]=num[i];
            u[i]=1;
            print(1);
            u[i]=0;
        }
    }

    return 0;
}