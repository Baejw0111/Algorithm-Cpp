#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int k,S[12]={0},a[6]={0};

void permutation(int s,int p){
    if(s==6){
        for(int i=0;i<6;++i){
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=p+1;i<=k-6+s;++i){
        a[s]=S[i];
        permutation(s+1,i);
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    while(1){
        cin>>k;
        if(k==0){
            break;
        }
        for(int i=0;i<k;++i){
            cin>>S[i];
        }
        for(int i=0;i<=k-6;++i){
            a[0]=S[i];
            permutation(1,i);
        }
        cout<<'\n';
    }

    return 0;
}