#include <bits/stdc++.h>
using namespace std;

int dat[26]={0};
string str;

void cnt(){
    for(char i:str){
        dat[i-'a']+=1;
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