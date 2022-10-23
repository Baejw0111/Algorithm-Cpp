#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

char c[50][50]={0};
int n,ans=0;

int Candy(){
    int maxt=1,tmp;
    char p;
    
    for(int i=0;i<n;++i){
        p=c[i][0];
        tmp=1;
        for(int j=1;j<n;++j){
            if(p==c[i][j]){
                ++tmp;
            }
            else{
                p=c[i][j];
                tmp=1;
            }
            maxt=max(maxt,tmp);
        }
    }

    for(int i=0;i<n;++i){
        p=c[0][i];
        tmp=1;
        for(int j=1;j<n;++j){
            if(p==c[j][i]){
                ++tmp;
            }
            else{
                p=c[j][i];
                tmp=1;
            }
            maxt=max(maxt,tmp);
        }
    }

    return maxt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>c[i][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(j<n-1){
                // cout<<c[i][j]<<" "<<c[i][j+1]<<endl;
                swap(c[i][j],c[i][j+1]);
                ans=max(ans,Candy());
                // for(int x=0;x<n;++x){
                //     for(int y=0;y<n;++y){
                //         cout<<c[x][y];
                //     }
                //     cout<<endl;
                // }
                // cout<<Candy()<<endl;
                // cout<<endl;
                swap(c[i][j],c[i][j+1]);
            }

            if(i<n-1){
                // cout<<c[i][j]<<" "<<c[i+1][j]<<endl;
                swap(c[i][j],c[i+1][j]);
                ans=max(ans,Candy());
                // for(int x=0;x<n;++x){
                //     for(int y=0;y<n;++y){
                //         cout<<c[x][y];
                //     }
                //     cout<<endl;
                // }
                // cout<<Candy()<<endl;
                // cout<<endl;
                swap(c[i][j],c[i+1][j]);
            }
        }
    }

    cout<<ans;

    return 0;
}