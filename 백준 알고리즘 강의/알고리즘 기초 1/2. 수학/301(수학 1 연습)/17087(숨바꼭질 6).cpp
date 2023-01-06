#include <iostream>
#include <string>
using namespace std;

long int gcd(long int a,long int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //c++의 표준 stream의 동기화를 끊는 역할을 하여 입출력의 속도를 높인다.

    int n;
    long int s,a,d,ans;

    cin>>n>>s; 

    for(int i=0;i<n;i++){
        cin>>a;
        if(s>a){
            d=s-a;
        }
        else{
            d=a-s;
        }

        if(i==0){
            ans=d;
        }
        else{
            if(ans>d){
                ans=gcd(ans,d);
            }
            else{
                ans=gcd(d,ans);
            }
        }
    }

    cout<<ans;
    

    return 0;
}