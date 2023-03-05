#include <iostream>
#include <string>
using namespace std;

//팰린드롬수

int main(){
    string str;
    while(1){
        cin>>str;
        if(str=="0"){
            break;
        }
        int s=0;
        for(int i=0;i<str.length()/2;++i){
            if(str[i]!=str[str.length()-1-i]){
                cout<<"no\n";
                s+=1;
                break;
            }
        }
        if(s==0){
            cout<<"yes\n";
        }
    }

    return 0;
}