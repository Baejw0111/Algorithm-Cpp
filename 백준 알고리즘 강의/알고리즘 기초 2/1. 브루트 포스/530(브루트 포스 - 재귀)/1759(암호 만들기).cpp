#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

#define ll long long

int L,C,u[15]={0},cs=0,vs=0;
char c[15]={0};

void permutation(int s,int uv,int p){
    if(s==L){
        for(int i=0;i<C;++i){
            if(u[i]){
                cout<<c[i];
            }
        }
        cout<<'\n';
        return;
    }
    for(int i=p+1;i<=C-L+s;++i){
        if(!u[i]){
            if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
                if(uv<L-2){
                    u[i]=1;
                    permutation(s+1,uv+1,i);
                    u[i]=0;
                }
                else{
                    continue;
                }
            }
            else{
                if(s-uv<L-1){
                    u[i]=1;
                    permutation(s+1,uv,i);
                    u[i]=0;
                }
                else{
                    continue;
                }
            }
        }
        else{
            continue;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>L>>C;
    for(int i=0;i<C;++i){
        cin>>c[i];
    }
    sort(c,c+C);

    for(int i=0;i<C;++i){
        if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            ++vs;
        }
        else{
            ++cs;
        }
    }

    for(int i=0;i<=C-L;++i){
        u[i]=1;
        if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            permutation(1,1,i);
        }
        else{
            permutation(1,0,i);
        }
        u[i]=0;
    }

    return 0;
}