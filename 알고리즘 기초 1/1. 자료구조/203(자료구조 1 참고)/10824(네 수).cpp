#include <iostream>
#include <string>
using namespace std;

int main(){
    long long int a,b,c,d;

    cin>>a>>b>>c>>d;

    for(long long int i=1;i<=10000000;i*=10){
        if(b/i==0){
            a*=i;
            a+=b;
            break;
        }
    }

    for(long long int i=1;i<=10000000;i*=10){
        if(d/i==0){
            c*=i;
            c+=d;
            break;
        }
    }

    cout<<a+c;

    return 0;
}