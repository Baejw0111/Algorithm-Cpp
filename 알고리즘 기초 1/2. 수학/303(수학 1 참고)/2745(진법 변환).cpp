#include <iostream>
#include <string>
#include <stack>
using namespace std;

void trans(string n,int b){
    long long int ans=0;
    int k=1;

    for(int i=n.length()-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            ans+=k*(n[i]-'0');
        }
        else{
            ans+=k*(n[i]-'A'+10);
        }

        k*=b;
    }

    cout<<ans;
}

int main(){
    string n;
    int b;
    cin>>n>>b;

    trans(n,b); 

    return 0;
}