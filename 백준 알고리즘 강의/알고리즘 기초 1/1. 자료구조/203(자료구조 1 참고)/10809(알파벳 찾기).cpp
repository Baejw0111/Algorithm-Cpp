#include <bits/stdc++.h>
using namespace std;

int dat[26]={0};
string str;

void cnt(){
    for(int i=0;i<str.size();++i){
        int c=str[i]-'a';
        if(dat[c]==-1){
            dat[c]=i;
        }
    }
}

void init(){
    for(int i=0;i<26;++i){
        dat[i]=-1;
    }
}

void input(){
    cin>>str;
}

void output(){
    for(int i:dat){
        cout<<i<<' ';
    }
}

void solve(){
    init();
    input();
    cnt();
    output();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}