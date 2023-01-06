#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int n,a[10]={0},Sum[10][10]={0},trigger=0;
char S[10][10]={0};

void permutation(int s){
    if(trigger){
        return;
    }
    if(s==n){
        for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        trigger=1;
        return;
    }
    for(int i=-10;i<=10;++i){
        int o=1;
        for(int j=0;j<=s;++j){
            if(s!=0){
                Sum[j][s]=Sum[j][s-1]+i;
            }
            else{
                Sum[j][s]=i;
            }
            if(S[j][s]=='+' && Sum[j][s]<=0){
                o=0;
                break;
            }
            else if(S[j][s]=='-' && Sum[j][s]>=0){
                o=0;
                break;
            }
            else if(S[j][s]=='0' && Sum[j][s]!=0){
                o=0;
                break;
            }
        }
        if(o){
            a[s]=i;
            permutation(s+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            cin>>S[i][j];
        }
    }

    permutation(0);

    return 0;
}