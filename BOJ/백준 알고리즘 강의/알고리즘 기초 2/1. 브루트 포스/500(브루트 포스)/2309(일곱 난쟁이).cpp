#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

ll d[9]={0},t=0;

int main(){
    for(int i=0;i<9;++i){
        cin>>d[i];
        t+=d[i];
    }
    sort(d,d+9);

    for(int i=0;i<8;++i){
        for(int j=i+1;j<9;++j){
            if(t-d[i]-d[j]==100){
                for(int k=0;k<9;++k){
                    if(k==i || k==j){
                        continue;
                    }
                    cout<<d[k]<<endl;
                }
                return 0;
            }
        }
    }

    return 0;
}