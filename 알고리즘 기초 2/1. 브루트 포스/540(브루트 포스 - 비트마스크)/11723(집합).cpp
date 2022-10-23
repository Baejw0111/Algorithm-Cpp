#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

int S[21]={0},m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m;

    for(int i=0;i<m;++i){
        string str;
        int x;
        cin>>str;
        if(str!="all"&&str!="empty"){
            cin>>x;
        }

        if(str=="add"){
            S[x]=1;
        }
        else if(str=="remove"){
            S[x]=0;
        }
        else if(str=="check"){
            cout<<S[x]<<'\n';
        }
        else if(str=="toggle"){
            S[x]=!S[x];
        }
        else if(str=="all"){
            for(int i=1;i<=20;++i){
                S[i]=1;
            }
        }
        else if(str=="empty"){
            for(int i=1;i<=20;++i){
                S[i]=0;
            }
        }
    }

    return 0;
}