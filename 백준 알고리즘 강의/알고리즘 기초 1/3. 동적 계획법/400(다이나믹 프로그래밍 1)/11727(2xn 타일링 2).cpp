#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n,a=1,b=0,c=0;
    cin>>n;

    for(int i=1;i<n;++i){
        int tmp=a;
        a+=(b+c)%10007;
        b=tmp%10007;
        c=tmp%10007;
    }

    cout<<(a+b+c)%10007;

    return 0;
}