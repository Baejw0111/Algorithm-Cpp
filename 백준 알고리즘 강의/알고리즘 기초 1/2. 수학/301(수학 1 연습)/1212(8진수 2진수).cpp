#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin>>str;

    stack<int> bi;

    for(int i=str.length()-1;i>=0;i--){
        int tmp=str[i]-'0';
        for(int j=0;j<3;j++){
            bi.push(tmp%2);
            tmp/=2;
        }
    }

    while(bi.top()==0 && bi.size()!=1){
        bi.pop();
    }

    while(bi.size()>0){
        cout<<bi.top();
        bi.pop();
    }

    return 0;
}