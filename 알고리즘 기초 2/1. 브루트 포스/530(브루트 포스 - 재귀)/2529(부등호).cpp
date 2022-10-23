#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define ll long long

int k;
int a[10]={0},u[10]={0};
ll Max=0,Min=10000000000;
//a는 출력할 답을 저장할 배열
//u는 숫자의 사용 여부를 저장할 배열
char A[10]={0};

void print(int s){
    if(s==k+1){
        int o=1;
        for(int i=1;i<k+1;++i){
            if(A[i-1]=='<'){
                if(a[i-1]>a[i]){
                    o=0;
                    break;
                }
            }
            else{
                if(a[i-1]<a[i]){
                    o=0;
                    break;
                }
            }
        }
        if(o){
            ll tmp=0;
            for(int i=0;i<k+1;++i){
                tmp*=10;
                tmp+=a[i];
            }
            Max=max(tmp,Max);
            Min=min(tmp,Min);
        }
        return;
    }
    for(int i=0;i<=9;++i){
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

    cin>>k;
    for(int i=0;i<k;++i){
        cin>>A[i];
    }

    print(0);

    for(int i=0;i<k-(int)log10(Max);++i){
        cout<<0;
    }
    cout<<Max<<endl;

    for(int i=0;i<k-(int)log10(Min);++i){
        cout<<0;
    }
    cout<<Min;

    return 0;
}