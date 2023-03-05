#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int prime(int x){
    for(int i=3;i<=sqrt(x);i+=2){
        if(x%i==0){
            return 0;
        }
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int t;
    cin>>t;

    int p[1000001]={0};
    p[2]=1;

    for(int i=3;i<1000000;i+=2){
        p[i]=prime(i);
    }

    for(int i=0;i<t;i++){
        int n,c=0;
        cin>>n;

        if(p[2] && p[n-2]){
            c++;
        }

        for(int j=3;j<=n/2;j+=2){
            if(p[j] && p[n-j]){
                c++;
            }
        }

        cout<<c<<'\n';
    }


    return 0;
}