#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n;
int a[100000]={0},u[100001]={0};
//obj는 입력된 값들을 저장할 배열
//a는 출력할 답을 저장할 배열
//u는 숫자의 사용 여부를 저장할 배열

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        u[i+1]=1;
    }

    for(int i=n-1;i>0;--i){
        if(a[i-1]>a[i]){
            for(int j=i-1;j<n;++j){
                u[a[j]]=0;
            }
            for(int j=a[i-1]-1;j>0;--j){
                if(u[j]==0){
                    a[i-1]=j;
                    u[j]=1;
                    break;
                }
            }
            for(int j=0;j<i;++j){
                cout<<a[j]<<" ";
            }
            for(int j=n;j>=1;--j){
                if(u[j]==0){
                    cout<<j<<" ";
                }
            }

            return 0;
        }
        else{
            continue;
        }
    }

    cout<<-1;

    return 0;
}