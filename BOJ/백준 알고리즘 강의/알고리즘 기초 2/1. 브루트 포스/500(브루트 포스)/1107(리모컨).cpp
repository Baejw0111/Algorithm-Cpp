#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

ll n,cur=100,onlymove=0,mix=500000,up,down,ans=0,tmp;
short m,broken[10]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<m;++i){
        cin>>broken[i];
    }
    sort(broken,broken+m);

    onlymove=abs(n-cur);

    up=n;
    down=n;

    while(1){
        int s=1;

        if(down>=0){
            tmp=down;
            do{
                if(binary_search(broken,broken+m,tmp%10)){
                    s=0;
                    break;
                }
                tmp/=10;
            }while(tmp!=0);
            if(s){
                mix=n-down;
                do{
                    mix+=1;
                    down/=10;
                }while(down!=0);
                break;
            }

            --down;
        }

        s=1;

        tmp=up;
        do{
            if(binary_search(broken,broken+m,tmp%10)){
                s=0;
                break;
            }
            tmp/=10;
        }while(tmp!=0);
        if(s){
            mix=up-n;
            do{
                mix+=1;
                up/=10;
            }while(up!=0);
            break;
        }

        ++up;

        if(up-n>onlymove){
            cout<<onlymove;
            return 0;
        }
    }

    ans=min(onlymove,mix);

    cout<<ans;

    return 0;
}