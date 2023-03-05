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

    int p[1000001]={0};

    for(int i=3;i<1000000;i+=2){
        p[i]=prime(i);
    }

    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }

        int s=0;

        for(int i=3;i<=n/2;i+=2){
            if(p[i] && p[n-i]){
                cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
                s=1;
                break;
            }
        }

        if(s==0){
            cout<<"Goldbach's conjecture is wrong."<<'\n';
        }

    }


    return 0;
}