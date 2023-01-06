#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main(){
    int a[11]={0},t;
    a[0]=1;
    cin>>t;

    for(int i=1;i<11;++i){
        if(i>=1){
            a[i]+=a[i-1];
        }
        if(i>=2){
            a[i]+=a[i-2];
        }
        if(i>=3){
            a[i]+=a[i-3];
        }
    }

    for(int i=0;i<t;++i){
        int n;
        cin>>n;
        cout<<a[n]<<endl;
    }

    return 0;
}