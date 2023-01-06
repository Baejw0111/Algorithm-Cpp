#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

struct com{
    long int x,y,z;
};

int main(){
    com a[100001]={0};
    long int t,d=1000000009;
    cin>>t;

    for(long int i=1;i<100001;++i){
        if(i>=1){
            if(i==1){
                a[i].x=1;
            }
            else{
                a[i].x+=(a[i-1].y+a[i-1].z)%d;
                a[i].x%=d;
            }
        }
        if(i>=2){
            if(i==2){
                a[i].y=1;
            }
            else{
                a[i].y+=(a[i-2].x+a[i-2].z)%d;
                a[i].y%=d;
            }
        }
        if(i>=3){
            if(i==3){
                a[i].z=1;
            }
            else{
                a[i].z+=(a[i-3].y+a[i-3].x)%d;
                a[i].z%=d;
            }
        }
    }

    for(long int i=0;i<t;++i){
        long int n;
        cin>>n;
        cout<<(a[n].x+a[n].y+a[n].z)%d<<endl;
    }

    return 0;
}