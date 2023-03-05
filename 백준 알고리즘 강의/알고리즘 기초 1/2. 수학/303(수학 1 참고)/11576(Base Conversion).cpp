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
    int a,b;
    cin>>a>>b;

    int n;
    cin>>n;

    int k=1,total=0;

    for(int i=1;i<n;i++){
        k*=a;
    }

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;

        total+=tmp*k;
        k/=a;
    }

    stack<int> ans;

    while(total!=0){
        ans.push(total%b);
        total/=b;
    }

    while(ans.size()>0){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}