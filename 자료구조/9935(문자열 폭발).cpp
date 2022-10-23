#include <iostream>
#include <stack>
using namespace std;

#define lli long long int
#define FOR(i,n) for(lli i=0;i<n;++i)

int main(){
    string str,bomb;
    cin>>str>>bomb;

    stack<char> tmp,ans;

    for(char i:str){
        if(i==bomb.back()){
            stack<char> trash;
            for(int j=bomb.length()-2;j>=0;--j){
                if(tmp.size()>0 && tmp.top()==bomb[j]){//segfault를 방지하기 위해 tmp size가 0보다 클때만 조건문 실행
                    trash.push(tmp.top());
                    tmp.pop();
                }
                else{
                    while(trash.size()>0){
                        tmp.push(trash.top());
                        trash.pop();
                    }
                    tmp.push(i);
                    break;
                }
            }
        }
        else{
            tmp.push(i);
        }
    }

    while(tmp.size()>0){
        ans.push(tmp.top());
        tmp.pop();
    }

    if(ans.size()==0){
        cout<<"FRULA";
    }
    else{
        while(ans.size()>0){
            cout<<ans.top();
            ans.pop();
        }
    }

    return 0;
}