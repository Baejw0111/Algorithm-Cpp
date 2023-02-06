#include <bits/stdc++.h>
using namespace std;

string str;
vector<string> ans;

void input(){
    cin>>str;
}

void output(){
    for(string i:ans){
        cout<<i<<'\n';
    }
}

void solve(){
    int len=str.length();

    for(int i=0;i<len;++i){
        ans.push_back(str);
        str.erase(0,1);
    }

    sort(ans.begin(),ans.end());

    output();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}