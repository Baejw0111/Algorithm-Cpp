#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int n,a[11]={0},oper[4]={0},u[4]={0},operorder[10]={0},ans_max=0,ans_min=0,sw=0;
//+,-,*,/

int cal(){
    int total=a[0];
    for(int i=0;i<n-1;++i){
        switch(operorder[i]){
        case 0:
            total+=a[i+1];
            break;

        case 1:
            total-=a[i+1];
            break;

        case 2:
            total*=a[i+1];
            break;

        case 3:
            total/=a[i+1];
            break;
        }
    }

    return total;
}

void permutation(int s){
    if(s==n-1){
        if(sw==0){
            ans_max=cal();
            ans_min=cal();
            sw=1;
        }
        else{
            ans_max=max(ans_max,cal());
            ans_min=min(ans_min,cal());
        }
        return;
    }
    for(int i=0;i<4;++i){
        if(u[i]<oper[i]){
            operorder[s]=i;
            u[i]+=1;
            permutation(s+1);
            u[i]-=1;
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

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<4;++i){
        cin>>oper[i];
    }

    permutation(0);
    cout<<ans_max<<endl<<ans_min;

    return 0;
}